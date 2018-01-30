#include <stdlib.h>
#include <iostream>
using namespace std;

#include "SmartPointer.h"
#include "Forme.h"
#include "Ligne.h"
#include "Pixel.h"
#include "Rectangle.h"
#include "ListeTriee.h"
#include "Liste.h"
#include "Iterateur.h"

int main()
{
  cout << "*** 1. Initialisation de quelques pointeurs classiques *****************************************************" << endl;
  int *pI1 = new int(5);
  cout << "Pointeur 1 = " << pI1 << " --- Valeur pointee 1 = " << *pI1 << endl;

  int *pI2 = new int(3);
  cout << "Pointeur 2 = " << pI2 << " --- Valeur pointee 2 = " << *pI2 << endl << endl;

  cout << "*** 2. Comparer les pointeurs et les valeurs pointees, c'est pas la meme chose, la preuve... ***************" << endl;
  if (pI1 < pI2) cout << "pI1 avant pI2" << endl;
  else cout << "pI1 apres pI2" << endl;

  if (*pI1 < *pI2) cout << "*pI1 avant *pI2" << endl;
  else cout << "*pI1 apres *pI2" << endl << endl;

  cout << "*** 3. Par contre, avec les SmartPointer... ****************************************************************" << endl;
  SmartPointer<int> p1(pI1),p2(pI2); // Constructeurs de SmartPointer !!!
  if (p1 < p2) cout << "Valeur pointee1 avant Valeur pointee2" << endl; // redefinir operateurs de comparaison de SmartPointer
  else cout << "Valeur pointee1 apres Valeur pointee2" << endl << endl;

  p1.Delete();  // Appel a delete de l'objet pointe
  p2.Delete();

  cout << "*** 4. Mais avec quelques efforts, on arrive a une utilisation agreable des SmartPointer *******************" << endl;
  SmartPointer<int> p = new int(7) ; // on peut l'utiliser comme un pointeur classique:-)
  cout << "Valeur pointee par notre SmartPointer p = " << *(p.getVal()) << endl;
  cout << "ou encore.." << endl;
  cout << "Valeur pointee par notre SmartPointer p = " << *p << endl << endl; // redefinir operateur* de SmartPointer
  cout << "et meme..." << endl;
  *p = 11;
  cout << "Valeur pointee par notre SmartPointer p = " << *p << endl << endl;
  p.Delete();

  cout << "*** 5. Test avec une Ligne *********************************************************************************" << endl;
  SmartPointer<Ligne> pf = new Ligne("L11",Point(30,50),Point(300,250),&Couleur::ROUGE,-10); 
  cout << "Ligne = " << *pf << endl << endl;
  pf.Delete();

  cout << "*** 6. Liste triee de pointeurs de int SANS SmartPointer ***************************************************" << endl;
  ListeTriee<int*> liste;
  liste.insere(new int (5));
  liste.insere(new int (2));
  liste.insere(new int (8));
  liste.insere(new int (3));

  Iterateur<int*> it(liste);
  while(!it.end())
  {
    int *p = (int*)it;
    cout << *p << endl;
    it++;
  }
  cout << endl << "pas vraiment triee sur les valeurs pointees... mais" << endl;
  liste.Affiche();
  cout << "bien sur les valeurs de pointeurs !!!" << endl;
  
  // mais n'oublions pas les delete...
  it.reset();
  while(!it.end())
  {
    int *p = (int*)it;
    delete p;
    it++;
  }
  cout << endl;

  cout << "*** 7. Liste triee de pointeurs de int AVEC SmartPointer ***************************************************" << endl;
  ListeTriee<SmartPointer<int> > liste2;
  liste2.insere(new int (5));   // ne pas oublier de redefinir operator= de SmartPointer !!!
  liste2.insere(new int (2));
  liste2.insere(new int (8));
  liste2.insere(new int (3));
  liste2.Affiche(); // redefinir operator<< de SmartPointer de telle sorte qu'il affiche la valeur du pointeur
   
  // a nouveau, n'oublions pas les delete
  Iterateur<SmartPointer<int> > it2(liste2);
  while(!it2.end())
  {
    SmartPointer<int> p = (SmartPointer<int>)it2;
    cout << "Valeur = " << *p << endl;
    p.Delete();
    it2++;
  }

  cout << "*** 8. Liste triee de pointeurs de Forme AVEC SmartPointer *************************************************" << endl;
  ListeTriee<SmartPointer<Forme> > liste3;
  liste3.insere(new Ligne("L11",Point(30,50),Point(300,250),&Couleur::ROUGE,-10));
  liste3.insere(new Pixel("P009",Point(200,400),&Couleur::BLEU,-20));
  liste3.insere(new Rectangle("R44",Point(50,20),200,100,true,&Couleur::BLEU,-5));
  liste3.insere(new Ligne("L7",Point(30,90),Point(200,90),&Couleur::ROUGE,-8));
  liste3.Affiche();
   
  // a nouveau, n'oublions pas les delete
  Iterateur<SmartPointer<Forme> > it3(liste3);
  while(!it3.end())
  {
    SmartPointer<Forme> p = (SmartPointer<Forme>)it3;
    cout << "Forme = " << p.getVal()->getId() << " " << p.getVal()->getInfos() << endl;
    cout << "ou encore..." << endl;
    cout << "Forme = " << p->getId() << " " << p.getVal()->getInfos() << endl << endl; // redefinir operator-> de SmartPointer
    p.Delete();
    it3++;
  }

  return 0;
}



