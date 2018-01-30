#ifndef LIGNE_H
#define LIGNE_H

#include <iostream>
#include "Forme.h"

class Ligne : public Forme {

private:
    Point Extremite;
public:
    // Fonctions constructeurs et destructeur//
    Ligne();
    Ligne(const char*, Point);
    Ligne(const Ligne&);
    Ligne(const char*, Point, Point, const Couleur*, int);
    ~Ligne();

    // Fonctions set de la classe//
    void setInfos();
    void setExtremite(Point);
    void setId(const char*);

    // Fonctions get de la classe//
    Point getExtremite() const;
    const char* getInfos () const;

    // Fonction d'affichage//
    void Affiche () const;

    // Fonction operator//
    friend ostream& operator<< (ostream&, const Ligne&);

    // Fonctions Save et Load//
    void Save(ostream&) const;
    void Load(ifstream&);

    //Fonction de dessine //
    void dessine();

};


ostream& operator<< (ostream&, const Ligne&);


#endif