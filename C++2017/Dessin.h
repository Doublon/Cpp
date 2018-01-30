#ifndef DESSIN_H
#define DESSIN_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include <fstream>
#include "WindowSDL.h"
#include "Couleur.h"
#include "BaseException.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"

class Dessin {
	private:
	int Largeur;
	int Hauteur;
	bool Fill;

	Couleur Fond;
	Liste<Couleur>  Palette;
	ListeTriee<SmartPointer<Forme> > Formes;


	public:

		//Constructeur et destructeur //
		Dessin();
		Dessin(int, int, const Couleur&);
		~Dessin();

		//Gestion des couleurs //
		void AjouteCouleur (const Couleur&);
		Couleur* RechercheCouleur (const char*);
		void ModifCouleur (const char*);
		void DeleteCouleur (const char*);

		//Gestion des formes//
		void AjouteForme (Forme*, const char*);
		void ModifForme (const char*, char*);
		void DeleteForme (const char*);
		Forme*  RechercheProximite ();
		Forme* RechercheFormeAff (int X1, int X2);
		int VerifId (const char *S);


	//Fonction get de la classe//
		int getLargeur () const;
		int getHauteur() const;
		bool getFill () const;
		Couleur getFond () const;
		Liste<Couleur> getPalette ()const;
		ListeTriee<SmartPointer<Forme> > getFormes();

		//Fonction set de la classe//
		void setLargeur (int);
		void setHauteur(int);
		void setFond (const Couleur&);
		void setFill (bool);

		//Fonction d'Affichage//
		void AfficherParametre() const;
		void AffichePalette() const;
		void AfficheFormes() const;

		//Fonctions Save et Load//
		void Save(const char*);
		void Load(const char*);

		//Fonctions d'importation//

		void importCouleurs(const char*);
		void importRectangles(const char*);
		void importPixels(const char*);
		void importLignes(const char*);
		void importCercles(const char*);

		//Fonction dessine //
		void dessine();



};

int CalculeProximite(int X1,int Y1,int X2,int Y2);

#endif