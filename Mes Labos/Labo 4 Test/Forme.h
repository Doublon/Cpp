#ifndef FORME_H
#define FORME_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "BaseException.h"
#include "Point.h"
#include "Couleur.h"
#include "WindowSDL.h"

class Forme {
	protected:
		char* Id;
		Point Position;
		const Couleur* couleur;
		int Profondeur;
		static int CptForme;
		char* Infos;

	public:

		//Constructeurs et destructeur //
		Forme();
		Forme(const char*, Point);
		Forme(const Forme&);
		Forme(const char*, Point,const Couleur*, int);
		virtual ~Forme();

		//Fonctions set //
		virtual void setId(const char*);
		void setPosition(Point);
		void setProfondeur(int);
		void setCouleur (const Couleur*);
		virtual void setInfos(){};

		//Fonctions get//
		const char* getId () const;
		int getProfondeur () const;
		virtual const char* getInfos() const=0;
		const Couleur* getCouleur () const;
		Point getPosition () const;
		static int getCompteur();

		virtual void Affiche () const;

		//Fonction operator //
		Forme& operator= (Forme&);
		int operator< (const Forme&);
		int operator> (const Forme&);
		int operator== (const Forme&);
		friend ostream& operator<< (ostream&, const Forme&);

		//Fonction Save ou Load //
		virtual void Save(ostream&) const=0;
		virtual void Load(ifstream&)=0;

		//Fonction de dessine //

		virtual void dessine()=0;

};

ostream& operator<< (ostream&, const Forme&);

#endif

