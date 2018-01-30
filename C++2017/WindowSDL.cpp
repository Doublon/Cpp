#include "WindowSDL.h"

#include <iostream>
using namespace std;

#include <signal.h>

/////////////////////////////////////////////////////////////////////////////////////////
char          WindowSDL::alive = 0;
SDL_Surface*  WindowSDL::screen = NULL;
int           WindowSDL::width = 800;
int           WindowSDL::height = 600;
pthread_t     WindowSDL::threadEventSDL = 0;

WindowSDLclick   WindowSDL::click;
char             WindowSDL::clicked = 0;
pthread_mutex_t  WindowSDL::mutexClick;
pthread_cond_t   WindowSDL::condClick;

char            WindowSDL::Key = 0;
char             WindowSDL::Pressed = 0;
pthread_mutex_t  WindowSDL::mutexKey;
pthread_cond_t   WindowSDL::condKey;

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::open(int w,int h) throw (WindowSDLexception)
{

  if (alive)
    throw WindowSDLexception("WindowSDL deja ouverte !!!");

  // Initialisation du Module Video
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw WindowSDLexception("Erreur de SDL_Init");

  
  // Definition de la fenetre
  if ((screen = SDL_SetVideoMode(w,h,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    throw WindowSDLexception("Erreur de SDL_SetVideoMode");

    SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);

  // Titre de la Fenetre
  SDL_WM_SetCaption("Paint",NULL);


    atexit(SDL_Quit); // Pour quitter proprement la SDL lors de l'exit

  pthread_mutex_init(&mutexClick,NULL);
  pthread_cond_init(&condClick,NULL);
  if (pthread_create(&threadEventSDL,NULL,FctThreadEventSDL,(void*)NULL) != 0)
    throw WindowSDLexception("Erreur de creation du threadEventSDL");

  width = w;
  height = h;
  alive = 1; 
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::setPalette() throw (WindowSDLexception)
{
  SDL_Surface *Palette = NULL;
  SDL_Rect positionPalette;

  positionPalette.x=575;
  positionPalette.y=70;

  if (!alive)
    throw WindowSDLexception("WindowSDL pas ouvert !!!");

  Palette=SDL_LoadBMP("Palette.bmp");
  SDL_BlitSurface(Palette, NULL, screen, &positionPalette);

  SDL_Flip(screen);

}
void WindowSDL::RemplirPaletteBase()
{

    PaletteBase(0,0,0,0,0);
    PaletteBase(1,0,127,127,127);
    PaletteBase(2,0,136,0,21);
    PaletteBase(3,0,255,0,0);
    PaletteBase(4,0,255,127,39);
    PaletteBase(5,0,255,255,0);
    PaletteBase(6,0,134,177,76);
    PaletteBase(7,0,0,162,232);
    PaletteBase(8,0,63,72,204);
    PaletteBase(9,0,163,73,164);
    PaletteBase(0,1,255,255,255);
    PaletteBase(1,1,195,195,195);
    PaletteBase(2,1,185,122,87);
    PaletteBase(3,1,255,174,201);
    PaletteBase(4,1,255,201,14);
    PaletteBase(5,1,239,228,176);
    PaletteBase(6,1,181,230,29);
    PaletteBase(7,1,153,217,234);
    PaletteBase(8,1,112,146,190);
    PaletteBase(9,1,200,191,231);

}
void WindowSDL::PaletteBase(int Case, int Colonne, int R, int V, int B)
{

  int y=6, x=571;

  x+=Case*22;
  y+=Colonne*22;

  fillRectangle(R,V,B,x,y,16,16);


}

void WindowSDL::RemplirPalette(int Case, int Colonne, int R, int V, int B)
{

  int y=99, x=582;

  x+=Case*26;
  y+=Colonne*22;

  fillRectangle(R,V,B,x,y,14,12);


}


/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::setMenu(bool Fill) throw (WindowSDLexception)
{
    SDL_Surface *Menu = NULL;
    SDL_Rect positionMenu;

    positionMenu.x=0;
    positionMenu.y=0;

    if (!alive)
        throw WindowSDLexception("WindowSDL pas ouvert !!!");

    if(Fill)
         Menu=SDL_LoadBMP("MenuFill.bmp");
    else
        Menu=SDL_LoadBMP("MenuNoFill.bmp");

    SDL_BlitSurface(Menu, NULL, screen, &positionMenu);

    RemplirPaletteBase();

    SDL_Flip(screen);

}

/////////////////////////////////////////////////////////////////////////////////////////
char WindowSDL::isAlive()
{
  return alive;
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::close() throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");
  alive = 0;
  screen = NULL;
  pthread_cancel(threadEventSDL);
  threadEventSDL = 0;
  SDL_Quit();
}

/////////////////////////////////////////////////////////////////////////////////////////
void* WindowSDL::FctThreadEventSDL(void *p)
{
  SDL_Event event;
  sigset_t mask;

  sigfillset(&mask);
  sigprocmask(SIG_SETMASK,&mask,NULL);

  while(1)
  {
    SDL_WaitEvent(&event);

    if (event.type == SDL_QUIT) {
      alive = 0;
      screen = NULL;
      threadEventSDL = 0;
      SDL_Quit();
      pthread_mutex_lock(&mutexClick);
      clicked = 1;
      pthread_mutex_unlock(&mutexClick);
      pthread_cond_signal(&condClick);
      pthread_exit(NULL);
    }

      if (event.type == SDL_MOUSEBUTTONUP)
      {
        if (event.button.button == SDL_BUTTON_LEFT) {
          pthread_mutex_lock(&mutexClick);
          click.setX(event.button.x);
          click.setY(event.button.y);
          clicked = 1;
          pthread_mutex_unlock(&mutexClick);
          pthread_cond_signal(&condClick);
        }
      }

      if(event.type==SDL_KEYDOWN)
      {
        if (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_RETURN) {
          pthread_mutex_lock(&mutexKey);
          Key = 'V';
          Pressed = 1;
          pthread_mutex_unlock(&mutexKey);
          pthread_cond_signal(&condKey);
        }

        if (event.key.keysym.sym == SDLK_UP) {
          pthread_mutex_lock(&mutexKey);
          Key = '+';
          Pressed = 1;
          pthread_mutex_unlock(&mutexKey);
          pthread_cond_signal(&condKey);
        }

        if (event.key.keysym.sym == SDLK_DOWN) {
          pthread_mutex_lock(&mutexKey);
          Key = '-';
          Pressed = 1;
          pthread_mutex_unlock(&mutexKey);
          pthread_cond_signal(&condKey);
        }
    }

  }

  pthread_exit(NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::setBackground(int R,int G,int B) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  SDL_Rect rect;

  if (R<0 || R>255 || G<0 || G>255 || B<0 || B>255)
    throw WindowSDLexception("Couleur invalide !!!");

  rect.x = 0;
  rect.y = 0;
  rect.w = width;
  rect.h = height;
 
  if (SDL_FillRect(screen,&rect,SDL_MapRGB((screen)->format,R,G,B)) < 0)
    throw WindowSDLexception("Erreur de SDL_FillRect");
  
  SDL_UpdateRect(screen,rect.x,rect.y,rect.w,rect.h);

  return;
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::fillRectangle(int R,int G,int B,int x,int y,int w,int h) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  SDL_Rect rect;

  if (R<0 || R>255 || G<0 || G>255 || B<0 || B>255)
    throw WindowSDLexception("Couleur invalide !!!");

  if (w >= 0)
  {
    rect.x = x;
    rect.w = w;
  }
  else 
  {
    rect.x = x + w + 1;
    rect.w = -w;
  }
  if (h >= 0)
  {
    rect.y = y;
    rect.h = h;
  }
  else 
  {
    rect.y = y + h + 1;
    rect.h = -h;
  }

  if (SDL_FillRect(screen,&rect,SDL_MapRGB((screen)->format,R,G,B)) < 0)
    throw WindowSDLexception("Erreur de SDL_FillRect");
  
  SDL_UpdateRect(screen,rect.x,rect.y,rect.w,rect.h);

  return;
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::setPixel(int R,int G,int B,int x,int y) throw (WindowSDLexception)
{
  if (x<0 || x>=width || y<0 || y>=height)
    return; 

  fillRectangle(R,G,B,x,y,1,1);
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawLine(int R,int G,int B,int x1,int y1, int x2,int y2) throw (WindowSDLexception)
{ // Bresenham
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  int x,y;
  int Dx,Dy;
  int xincr,yincr;
  int erreur;
  int i;

  Dx = abs(x2-x1);
  Dy = abs(y2-y1);
  if(x1<x2) xincr = 1;
  else xincr = -1;
  if(y1<y2) yincr = 1;
  else yincr = -1;

  x = x1;
  y = y1;
  if(Dx>Dy)
  {
    erreur = Dx/2;
    for(i=0;i<Dx;i++)
    {
      x += xincr;
      erreur += Dy;
      if(erreur>Dx)
      {
        erreur -= Dx;
        y += yincr;
      }
      setPixel(R,G,B,x,y);
    }
  }
  else
  {
    erreur = Dy/2;
    for(i=0;i<Dy;i++)
    {
      y += yincr;
      erreur += Dx;
      if(erreur>Dy)
      {
        erreur -= Dy;
        x += xincr;
      }
      setPixel(R,G,B,x,y);
    }
  }
  setPixel(R,G,B,x1,y1);
  setPixel(R,G,B,x2,y2);
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawCircle (int R,int G,int B,int cx,int cy, int rayon) throw (WindowSDLexception)
{ // Bresenham
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

    int d, y, x;

    d = 3 - (2 * rayon);
    x = 0;
    y = rayon;

    while (y >= x) {
      setPixel(R,G,B,cx + x, cy + y);
      setPixel(R,G,B,cx + y, cy + x);
      setPixel(R,G,B,cx - x, cy + y);
      setPixel(R,G,B,cx - y, cy + x);
      setPixel(R,G,B,cx + x, cy - y);
      setPixel(R,G,B,cx + y, cy - x);
      setPixel(R,G,B,cx - x, cy - y);
      setPixel(R,G,B,cx - y, cy - x);

      if (d < 0)
        d = d + (4 * x) + 6;
      else {
        d = d + 4 * (x - y) + 10;
        y--;
      }

      x++;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawDisc (int R,int G,int B,int cx,int cy, int rayon) throw (WindowSDLexception)
{ // Bresenham
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  int d, y, x;

  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;

  while (y >= x) {
    drawLine(R,G,B,cx + x, cy + y,cx,cy);
    drawLine(R,G,B,cx + x, cy + y,cx,cy);
    drawLine(R,G,B,cx + y, cy + x,cx,cy);
    drawLine(R,G,B,cx - x, cy + y,cx,cy);
    drawLine(R,G,B,cx - y, cy + x,cx,cy);
    drawLine(R,G,B,cx + x, cy - y,cx,cy);
    drawLine(R,G,B,cx + y, cy - x,cx,cy);
    drawLine(R,G,B,cx - x, cy - y,cx,cy);
    drawLine(R,G,B,cx - y, cy - x,cx,cy);

    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }

    x++;
  }

}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawRectangle(int R,int G,int B,int x,int y,int w,int h) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  drawLine(R,G,B,x,y,x+w,y);
  drawLine(R,G,B,x+w,y,x+w,y+h);
  drawLine(R,G,B,x+w,y+h,x,y+h);
  drawLine(R,G,B,x,y+h,x,y);
}

/////////////////////////////////////////////////////////////////////////////////////////
WindowSDLclick WindowSDL::waitClick() throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  WindowSDLclick c;

  pthread_mutex_lock(&mutexClick);
  clicked = 0;
  while (!clicked)
    pthread_cond_wait(&condClick,&mutexClick);
  if (!alive)
  {
    pthread_mutex_unlock(&mutexClick); 
    throw WindowSDLexception("WindowSDL non ouverte !!!");
  }
  c = click;
  pthread_mutex_unlock(&mutexClick);

  return c;
}

char WindowSDL::waitKey() throw (WindowSDLexception)
{
  fflush(stdin);
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  char c;

  pthread_mutex_lock(&mutexKey);
  Pressed = 0;
  while (!Pressed)
    pthread_cond_wait(&condKey,&mutexKey);
  if (!alive)
  {
    pthread_mutex_unlock(&mutexKey);
    throw WindowSDLexception("WindowSDL non ouverte !!!");
  }
  c = Key;
  pthread_mutex_unlock(&mutexKey);

  return c;
}
