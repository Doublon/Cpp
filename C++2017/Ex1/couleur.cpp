
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "couleur.h"

#define L_NOM 20


Couleur::Couleur()
{
	Rouge=5;
	Bleu=6;
	Vert=7;
	nom= new char[L_NOM]; nom[0]=0;
	
}
Couleur::Couleur(int R, int B, int V, char *S)
{
	Rouge=R;
	Bleu=B;
	Vert=V;

	nom= new char[strlen(S)+1]; strcpy(nom,S);

}

Couleur::Couleur(int R, int B, int V)
{
	Rouge=R;
	Bleu=B;
	Vert=V;
	nom= new char[L_NOM]; nom[0]=0;

}

Couleur::Couleur(Couleur& A)
{
	Rouge=A.Rouge;
	Bleu=A.Bleu;
	Vert=A.Vert;
	nom= new char[strlen(A.nom)+1]; strcpy(nom,A.nom);
}

void Couleur::setNom (char *S)
{
	nom= new char[strlen(S)+1]; strcpy(nom,S);
}

void Couleur::setRouge(int R)
{
	Rouge=R;

}

void Couleur::setBleu(int B)
{
	Bleu=B;

}

void Couleur::setVert(int V)
{
	Vert=V;

}

char* Couleur::getNom () const
{
	return this->nom;
}

int Couleur::getRouge () const
{
	return this->Rouge;
}

int Couleur::getBleu () const
{
	return this->Bleu;
}

int Couleur::getVert () const
{
	return this->Vert;
}

void Couleur::Affiche() const
{
	cout << "Rouge: " << Rouge << endl;
	cout << "Bleu: " << Bleu << endl;
	cout << "Vert: " << Vert << endl;
	cout << "Nom : " << nom<< endl;

}

Couleur::~Couleur ()
{
	cout << "Destruction de " << nom << endl;
	delete nom;

}


