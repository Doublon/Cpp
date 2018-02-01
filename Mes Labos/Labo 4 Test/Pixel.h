#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include "Forme.h"

class Pixel : public Forme {

	public:
		Pixel();
		Pixel(const char*, Point);
		Pixel(const Pixel&);
		Pixel(const char*, Point,const Couleur*, int);
		~Pixel();
		
		void setInfos();
		void setId (const char* S);
		const char* getInfos () const;

		void Save(ostream&) const;
		void Load(ifstream&);

	friend ostream& operator<< (ostream&, const Pixel&);

		//Fonction de dessine //
		void dessine();
};


ostream& operator<< (ostream&, const Pixel&);

#endif