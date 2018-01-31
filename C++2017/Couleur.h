#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "InvalidColorException.h"

class Couleur {
	private:
		int Rouge;
		int Bleu;
		int Vert;
		char *Nom;
		static int CptCouleur;
	public:

	//Fonctions constructeur et destructeur//

		Couleur();
		Couleur(int, int, int, const char*);
		Couleur(int, int, int);
		Couleur(const Couleur&);
		~Couleur();

	//Fonctions statics //
		static const Couleur ROUGE;
		static const Couleur BLEU;
		static const Couleur VERT;

	//Fonctions set de la classe//
		void setNom (const char*);
		void setRouge (int);
		void setBleu (int);
		void setVert (int);


	//Fonctions get de la classe//
		const char *getNom() const;
		int getRouge () const;
		int getBleu () const;
		int getVert () const;
		static int getCompteur();
		void Affiche () const;
		int getLuminance() const;


	//Fonctions operators de la classe//
		Couleur& operator= (const Couleur&);
		Couleur operator+ (const Couleur&) const;
		Couleur operator+ (const int) const;
		Couleur operator- (const int) const;
		int operator< (const Couleur&);
		int operator> (const Couleur&);
		int operator== (const Couleur&);

		Couleur operator++ ();
		Couleur operator++ (int);
		Couleur operator-- ();
		Couleur operator-- (int);

		friend Couleur operator+ (const int, const Couleur&);
		friend ostream& operator<< (ostream&, const Couleur&);
		friend istream& operator>> (istream&, const Couleur&);

	//Fonctions Save et Load de la classe//
		void Save(ostream&) const;
		void Load(ifstream&);
};

Couleur operator+ (const int, const Couleur&);
ostream& operator<< (ostream&, const Couleur&);
istream& operator>> (istream&, Couleur&);

#endif