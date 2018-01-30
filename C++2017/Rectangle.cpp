#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Rectangle.h"


Rectangle::Rectangle():Forme()
{
    DimX=0;
    DimY=0;
    Rempli=false;
    setInfos();
}


Rectangle::Rectangle(const char* S, Point P):Forme(S,P)
{
    setId(S);
    DimX=0;
    DimY=0;
    Rempli=false;
    setInfos();
}

Rectangle::Rectangle(const char* S, Point P, int DX, int DY, bool Rem, const Couleur* C, int prof):Forme(S,P,C,prof)
{
    setId(S);
    DimX=DX;
    DimY=DY;
    Rempli=Rem;
    setInfos();
}

Rectangle::Rectangle(const Rectangle& A):Forme (A)
{
    setId(A.getId());
    DimX=A.getDimX();
    DimY=A.getDimY();
    Rempli=A.isRempli();
    Infos= new char[strlen(A.Infos)+1]; strcpy(Infos,A.Infos);
}

void Rectangle::setDimX (int X)
{
    DimX=X;
    setInfos();
}

void Rectangle::setDimY (int Y)
{
    DimY=Y;
    setInfos();
}

void Rectangle::setRempli(bool R)
{
    Rempli=R;
}

int Rectangle::getDimX () const
{
    return this->DimX;
}

int Rectangle::getDimY () const
{
    return this->DimY;
}

bool Rectangle::isRempli() const
{
    return this->Rempli;
}

void Rectangle::setInfos()
{
    char *Buffer1=NULL;
    char Buffer2 [150];
    int R=0,B=0,V=0;


    if (couleur!=NULL)
    {
        R=couleur->getRouge();
        B=couleur->getBleu();
        V=couleur->getVert();

        if(couleur->getNom()!=NULL) {
            Buffer1 = new char[strlen(couleur->getNom()) + 1];
            strcpy(Buffer1, couleur->getNom());
        }
        else
        {
            Buffer1= new char[8];
            strcpy(Buffer1,"Inconnu");
        }
    }
    else
    {
        Buffer1= new char[8];
        strcpy(Buffer1,"Inconnu");
    }

    if(Infos!=NULL);
    delete Infos;

    sprintf(Buffer2,"Rectangle %s: Position(%d , %d), DimX=%d, DimY= %d, Rempli = %d Couleur( %d, %d, %d, %s) , Profondeur=%d",Id, Position.getX(), Position.getY(),DimX, DimX, Rempli, R, B, V, Buffer1,Profondeur);
    Infos= new char[strlen(Buffer2)+1];
    strcpy(Infos,Buffer2);



    delete Buffer1;

}

const char* Rectangle::getInfos () const
{
    if (Infos!=NULL)
        return this->Infos;
    else
        return "Aucune";
}

Rectangle::~Rectangle ()
{
    if(Id!=NULL)
    {
        delete Id;
    }
    if(Infos!=NULL)
    {
        delete Infos;
    }
    CptForme--;

}

ostream& operator<< (ostream& S, const Rectangle& R)
{
    int Ro=0,B=0,V=0;
    char *Buffer=NULL;


    if(R.couleur!=NULL)
    {
        Ro=R.couleur->getRouge();
        B=R.couleur->getBleu();
        V=R.couleur->getVert();

        if(R.couleur->getNom()!=NULL)
        {
            Buffer = new char[strlen(R.couleur->getNom()) + 1];
            strcpy(Buffer, R.couleur->getNom());
        }
        else
        {
            Buffer = new char[8];
            strcpy(Buffer, "Inconnu");
        }
    }
    else
    {
        Buffer=new char [8];
        strcpy(Buffer,"Inconnu");
    }



    S << "RECTANGLE "<<R.Id <<": Position:"<<R.Position <<",DimX="<<R.DimX<<",DimY="<<R.DimY<<", Rempli="<<R.isRempli()<<", Couleur:(" << Ro<<","<<B<<","<< V <<"," <<Buffer <<"), Profondeur= "<<R.Profondeur <<endl;

    delete Buffer;

    return S;

}

void Rectangle::setId (const char* S)
{
    char Check[80];
    int i=0;

    if(S==NULL)
        throw BaseException((char *)"L'id est NULL");

    strcpy(Check,S);

    if (Check[i] != 'R')
        throw BaseException((char *)"L'Id des rectangles doit commencer par 'R'");

    i++;

    while (isdigit(Check[i]) && Check[i] != '\0')
        i++;

    if (Check[i] != '\0' || i < 2)
        throw BaseException((char *) "Il doit y avoir minimum 2 caractère et que des chiffres après le 'R'");

    Id= new char[strlen(S)+1];
    strcpy(Id,S);
}


void Rectangle::Save(ostream& Fichier) const
{

    int Taille=0;

    Fichier.write((char*)Id, sizeof(char));
    Taille = strlen(getId())+1;
    Fichier.write((char*)&Taille, sizeof(int));
    Fichier.write((char*)Id, Taille);
    Position.Save(Fichier);
    Fichier.write((char*)&Profondeur, sizeof(int));
    Fichier.write((char*)&DimX, sizeof(int));
    Fichier.write((char*)&DimY, sizeof(int));
    Fichier.write((char*)&Rempli, sizeof(bool));

    Taille = strlen(couleur->getNom())+1;
    Fichier.write((char*)&Taille, sizeof(int));
    Fichier.write((char*)couleur->getNom(), Taille);
}


void Rectangle::Load(ifstream& Fichier)
{
    char Buffer[50];
    Point Pros;
    int tmp, Taille=0;
    bool rmp;

    Fichier.read((char*)&Taille, sizeof(int));
    Fichier.read((char*)Buffer, Taille);
    setId(Buffer);
    Pros.Load(Fichier);
    setPosition(Pros);
    Fichier.read((char *) &tmp, sizeof(int));
    setProfondeur(tmp);
    Fichier.read((char *) &tmp, sizeof(int));
    setDimX(tmp);
    Fichier.read((char *) &tmp, sizeof(int));
    setDimY(tmp);
    Fichier.read((char *) &rmp, sizeof(bool));
    setRempli(rmp);

    setInfos();

}

void Rectangle::dessine()
{

    if(!isRempli())
        WindowSDL::drawRectangle(getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getPosition().getX(),
                      getPosition().getY(),getDimX(),getDimY());
    else
        WindowSDL::fillRectangle(getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getPosition().getX(),
                               getPosition().getY(),getDimX(),getDimY());

}