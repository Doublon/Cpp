#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Couleur.h"
#include "Point.h"
#include "Forme.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();

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
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

//*******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 2 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de la classe Point" << endl;
  cout << " 2. Tests de la classe Forme (avec agregations par valeur et par reference)" << endl;
  cout << " 3. Tests des compteurs statiques d'objets" << endl;
  cout << " 4. Tests des variables statiques de type Couleur" << endl;
  cout << " 5. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

//*******************************************************************************************************
//*** Tests de la classe Point **************************************************************************
//*******************************************************************************************************
void Essai1()
{
  cout << "(1) ***** Test des constructeurs de Point ***********************************************" << endl;
  {
    Point p1, p2(125,200), p3(p2);
    cout << "Defaut : "; p1.Affiche();
    cout << "Initialisation : "; p2.Affiche();
    cout << "Copie : "; p3.Affiche();
    cout << endl;
  }

  cout << endl << "(2) **** Test des setters/getters ***********************************************" << endl;
  {
    Point p;
    cout << "Defaut : "; p.Affiche();
    p.setX(300);
    p.setY(170);
    cout << "Apres setters : "; p.Affiche();
    cout << "X = " << p.getX() << endl;
    cout << "Y = " << p.getY() << endl;
  }
}

//*************************************************************************************************
//*** Tests de la classe Forme (Agregation)                                                     *** 
//***               - par valeur avec Point                                                     ***
//***               - par reference avec Couleur                                                ***
//*************************************************************************************************
void Essai2()
{
  cout << "(1) ***** Test du constructeur par defaut de Forme *************************************" << endl;
  { // Par defaut, une forme ne possede pas de couleur (NULL)
    // Par defaut, une forme possede une position (Point) construite par defaut
    // Par defaut, une forme possede une profondeur egale a 0
    Forme f;
    f.Affiche();
    cout << endl << endl;
  }

  cout << "(2) ***** Test du constructeur d'initialisation partiel de Forme ***********************" << endl;
  { // Une nouvelle forme construite par ce constructeur ne possede pas de couleur (NULL) et une profondeur egale a 0
    Point p(240,100);
    Forme f("F001",p);
    f.Affiche();
    cout << endl << endl;
  }

  cout << "(3) ***** Test du constructeur d'initialisation complet de Forme ***********************" << endl;
  { 
    Couleur saumon(248,152,85);
    Forme f("F002",Point(130,300),&saumon,-10);
    f.Affiche();
    cout << endl << endl;
  }

  cout << "(4) **** Test des setters/getters ******************************************************" << endl;
  {
    Forme f;
    f.Affiche();
    f.setId("F11");
    f.setPosition(Point(200,150));
    Couleur cyan(0,255,255,"Cyan");
    f.setCouleur(&cyan);
    f.setProfondeur(-20);
    f.Affiche();

    cout << endl << "Id : " << f.getId() << endl;
    cout << "Position : ";
    f.getPosition().Affiche();
    cout << "Couleur : ";
    f.getCouleur()->Affiche();
    cout << "Profondeur : " << f.getProfondeur() << endl << endl;
  }

  cout << "(5) ***** Test du constructeur de copie de Forme ***************************************" << endl;
  {
    Couleur grenadine(233,56,63,"Grenadine");
    Forme f1("F123",Point(10,50),&grenadine,-30);
    Forme f2(f1); // f1 et f2 pointent vers le meme objet Couleur
    f2.setId("F456");
    cout << "f1 : " << endl;
    f1.Affiche();
    cout << "Copie de f1 (id modifie) : " << endl;
    f2.Affiche();
    cout << "--> on modifie le nom de la couleur" << endl;
    grenadine.setNom("rouge pale");
    cout << "f1 : " << endl;
    f1.Affiche();
    cout << "Copie de f1 (id modifie) : " << endl;
    f2.Affiche();
  }
}

//*******************************************************************************************************
//*** Tests des compteurs statiques d'objets ************************************************************
//*******************************************************************************************************
void Essai3()
{
  cout << "(1) ***** Affichage des compteurs statiques ********************************************" << endl;
  cout << "Nb Objets Couleur = " << Couleur::getCompteur() << endl;
  cout << "Nb Objets Point   = " << Point::getCompteur() << endl;
  cout << "Nb Objets Forme   = " << Forme::getCompteur() << endl << endl;

  cout << "(2) ***** Instanciation de differents objets *******************************************" << endl;
  Couleur c1(255,89,45),c2(c1),*p1;
  p1 = new Couleur(100,100,100,"gris");
  c1.Affiche();
  c2.Affiche();
  p1->Affiche();
  Point pt(200,300),*p2;
  p2 = new Point(pt);
  pt.Affiche();
  p2->Affiche();
  Forme f("F17",Point(130,300),&c1,-10);
  Forme* p3 = new Forme("F234",pt);
  f.Affiche();
  p3->Affiche();
  cout << endl;

  cout << "(3) ***** Affichage des compteurs statiques ********************************************" << endl;
  cout << "Nb Objets Couleur = " << Couleur::getCompteur() << endl;
  cout << "Nb Objets Point   = " << Point::getCompteur() << endl;
  cout << "Nb Objets Forme   = " << Forme::getCompteur() << endl << endl;

  cout << "(4) ***** Destruction des objets dynamiques ********************************************" << endl;
  delete p1;
  delete p2;
  delete p3;
  cout << endl;

  cout << "(5) ***** Affichage des compteurs statiques ********************************************" << endl;
  cout << "Nb Objets Couleur = " << Couleur::getCompteur() << endl;
  cout << "Nb Objets Point   = " << Point::getCompteur() << endl;
  cout << "Nb Objets Forme   = " << Forme::getCompteur() << endl << endl;
}

//*******************************************************************************************************
//*** Tests des variables statiques de type Couleur *****************************************************
//*******************************************************************************************************
void Essai4()
{
  cout << "(1) ***** Tests de base ****************************************************************" << endl;
  Couleur::ROUGE.Affiche(); // ROUGE est un objet de la classe Couleur, il possede donc la methode Affiche()
  Couleur::VERT.Affiche();
  cout << endl;

  //Couleur::BLEU.setNom("Mauve"); // --> ne compile pas car l'objet BLEU est un objet constant (voir enonce) !!!

  cout << "(2) ***** Copie des objets statiques ***************************************************" << endl;
  Couleur c(Couleur::BLEU);
  c.Affiche();
  c.setVert(255);   // compile car c n'est pas un objet constant
  c.setNom("Cyan");
  c.Affiche();
  cout << endl;

  cout << "(3) ***** Creation de Forme ************************************************************" << endl;
  Forme f("F223",Point(250,120),&Couleur::ROUGE,-20);  
  f.Affiche();
  f.setCouleur(&Couleur::BLEU);
  f.Affiche();
  cout << endl;

  cout << "(4) ***** Et pour le fun :) ! --> savoir expliquer !!! *********************************" << endl;
  cout << "Nb Objets Couleur = " << Couleur::BLEU.getCompteur() << endl;  
  cout << endl;
}

