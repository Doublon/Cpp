#include <iostream>
#include <stdlib.h>
using namespace std;
#include "couleur.h"


int main()
{
	Couleur C;

	
	C.setNom ("Chouette");	
	C.setRouge (245);
	C.setVert (50);
	C.setBleu (0);
	
	Couleur B(C)	;

	cout << "Rouge = " << B.getRouge() << endl;
   	cout << "Vert = " << B.getVert() << endl;
    	cout << "Bleu = " << B.getBleu() << endl;
   	cout << "Nom = " << B.getNom() << endl;

	
		
	//C.Affiche();

}

