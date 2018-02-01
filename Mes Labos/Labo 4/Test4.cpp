#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>
#include "Forme.h"
#include "Pixel.h"
//#include "Ligne.h"
//#include "Rectangle.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
//      case 2 : Essai2(); break;
//      case 3 : Essai3(); break;
//     case 4 : Essai4(); break;
//      case 5 : Essai5(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 4 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Test de la classe Pixel" << endl;
  cout << " 2. Test de la classe Ligne" << endl;
  cout << " 3. Test de la classe Rectangle" << endl;
  cout << " 4. Heritage et virtualite : Test de la methode virtuelle getInfos()" << endl;
  cout << " 5. Test du downcasting et du dynamic-cast" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//***********************************************************************************************
// A FAIRE : - rendre la classe Forme abstraite en ajoutant la methode virtuelle pure getInfos()
//           - la classe Pixel qui herite de Forme et qui redefinit la methode getInfos()
//           - redefinir l'operateur << de Pixel
//***********************************************************************************************
//*** Tests de la classe Pixel ******************************************************************
//***********************************************************************************************
void Essai1()
{
  cout << "----- 1.1 Test des constructeurs de Pixel ------------------------------------" << endl;
    Pixel p1;
/*  Pixel p1,p2("PT56",Point(120,200)),p3("A23",Point(200,400),&Couleur::BLEU,-10),p4(p3);
  cout << "--> p1 (defaut) : " << p1 << endl;
  cout << "--> p2 (initialisation partiel) : " << p2 << endl;
  cout << "--> p3 (initialisation complet) : " << p3 << endl;
  cout << "--> p4 (copie de p3) : " << p4 << endl;
  cout << endl;

  cout << "----- 1.2 Test de la methode getInfos() -----------------------------------------" << endl;
  cout << "--> p1 (defaut) : " << p1.getInfos() << endl;
  cout << "--> p2 (initialisation partiel) : " << p2.getInfos() << endl;
  cout << "--> p3 (initialisation complet) : " << p3.getInfos() << endl;
  cout << "--> p4 (copie de p3) : " << p4.getInfos() << endl;*/
}

//***********************************************************************************************
// A FAIRE: la classe Ligne qui
//                  - herite de la classe Forme
//                  - possede en plus une extremite (de type Point)  
//***********************************************************************************************
//*** Tests de la classe Ligne ******************************************************************
//***********************************************************************************************
/*void Essai2()
{
  cout << "(2.1) ***** Test du constructeur par defaut + setters de Ligne **********************" << endl;
  { 
    Ligne l;
    cout << "l = " << l << endl;
    cout << "--> modification de l" << endl;
    l.setPosition(Point(50,90));
    l.setExtremite(Point(200,150));
    cout << "l = " << l << endl << endl;
  }

  cout << "(2.2) ***** Test du constructeur d'initialisation + getters de Ligne ****************" << endl;
  { 
    Ligne l("L25U",Point(30,90),Point(200,90),&Couleur::ROUGE,-20);
    cout << "l = " << l << endl;
    cout << "Extremite de l = " << l.getExtremite() << endl;
    cout << "Infos de l = " << l.getInfos() << endl << endl;
  }

  cout << "(2.3) ***** Test du constructeur de copie de Ligne **********************************" << endl;
  {
    Ligne *pl = new Ligne("EER12",Point(30,90),Point(200,90),&Couleur::ROUGE,-20);
    cout << "Objet de base = " << *pl << endl;

    Ligne l(*pl);
    cout << "--> Destruction objet de base" << endl;
    delete pl;
    cout << "Copie = " << l << endl << endl; 
  }
}*/

//***********************************************************************************************
// A FAIRE: la classe Rectangle qui
//                  - herite de la classe Forme
//                  - possede en plus une largeur (dimX), hauteur (dimY) et un booleen rempli  
//***********************************************************************************************
//*** Tests de la classe Rectangle **************************************************************
//***********************************************************************************************
/*
void Essai3()
{
  cout << "(3.1) ***** Test du constructeur par defaut + setters de Rectangle ******************" << endl;
  { 
    Rectangle r;
    cout << "r = " << r << endl;
    cout << "--> modification de r" << endl;
    r.setPosition(Point(50,90));
    r.setDimX(300);
    r.setDimY(200);
    r.setRempli(true);
    cout << "r = " << r << endl << endl;
  }

  cout << "(3.2) ***** Test du constructeur d'initialisation + getters de Rectangle ************" << endl;
  { 
    Rectangle r("R1112",Point(40,10),60,150,false,&Couleur::VERT,-30);
    cout << "r = " << r << endl;
    cout << "Largeur de r = " << r.getDimX() << endl;
    cout << "Hauteur de r = " << r.getDimY() << endl;
    if (r.isRempli()) cout << "r est rempli" << endl;
    else cout << "r n'est pas rempli" << endl;
    cout << "Infos de r = " << r.getInfos() << endl << endl;
  }

  cout << "(3.3) ***** Test du constructeur de copie de Rectangle ******************************" << endl;
  {
    Rectangle *pr = new Rectangle("RR11",Point(50,20),200,100,true,&Couleur::BLEU,-20);
    cout << "Objet de base = " << *pr << endl;

    Rectangle r(*pr);
    cout << "--> Destruction objet de base" << endl;
    delete pr;
    cout << "Copie = " << r << endl << endl; 
  }
}
*/

//***********************************************************************************************
// A FAIRE : normalement rien...
//           juste comprendre et tester le code ci-dessous
//***********************************************************************************************
//*** Tests de la virtualite ********************************************************************
//***********************************************************************************************
/*void Essai4()
{
  srand((unsigned)time(NULL));

  cout << "----- 4.1 Allocation dynamique de Formes -------------------------------------------------------" << endl;
  Forme* forme[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "forme[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : forme[i] = new Pixel("P11",Point(200,400),&Couleur::BLEU,-10);
               cout << "Pixel" << endl;
               break;

      case 1 : forme[i] = new Ligne("L34",Point(30,90),Point(200,90),&Couleur::ROUGE,-20);
               cout << "Ligne" << endl;
               break;

      case 2 : forme[i] = new Rectangle("R44",Point(50,20),200,100,true,&Couleur::BLEU,-20);
               cout << "Rectangle" << endl;
    }
  }
  cout << endl;

  cout << "----- 4.2 Test de la methode VIRTUELLE getInfos() (redefinie dans chaque classe heritee) -------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "forme[" << i << "] : " << forme[i]->getInfos() << endl;
  }
  cout << endl;

  
  cout << "----- 4.4 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete forme[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}*/

//***********************************************************************************************
// A FAIRE : normalement rien dans vos classes...
//           juste comprendre et tester le code ci-dessous
//***********************************************************************************************
//*** Tests du downcasting et dynamic-cast ******************************************************
//***********************************************************************************************
/*void Essai5()
{
  srand((unsigned)time(NULL));

  cout << "----- 5.1 Allocation dynamique de Formes -------------------------------------------------------" << endl;
  Forme* forme[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "forme[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : forme[i] = new Pixel("P009",Point(200,400),&Couleur::BLEU,-10);
               cout << "Pixel" << endl;
               break;

      case 1 : forme[i] = new Ligne("LLL7",Point(30,90),Point(200,90),&Couleur::ROUGE,-20);
               cout << "Ligne" << endl;
               break;

      case 2 : forme[i] = new Rectangle("RR44",Point(50,20),200,100,true,&Couleur::BLEU,-20);
               cout << "Rectangle" << endl;
    }
  }
  cout << endl;

  cout << "----- 5.2 Test du downcasting et dynamic-cast ------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "forme[" << i << "] ";
    Pixel* pp = dynamic_cast<Pixel*>(forme[i]);
    if (pp != NULL) cout << "est un Pixel" << endl;
    Ligne* pl = dynamic_cast<Ligne*>(forme[i]);
    if (pl != NULL) cout << "est une Ligne" << endl;
    Rectangle* pr = dynamic_cast<Rectangle*>(forme[i]);
    if (pr != NULL) cout << "est un Rectangle" << endl;
  }
  cout << endl;

  cout << "----- 5.3 Liberation memoire ----------------------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete forme[i];
}*/

