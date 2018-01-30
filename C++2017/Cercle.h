#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "Forme.h"


class Cercle : public Forme {

private:
    int Rayon;
    bool Rempli;
public:
    Cercle();
    Cercle(const char* S, Point P);
    Cercle (const Cercle&);
    Cercle(const char*, Point, int, int, bool, const Couleur*, int);
    ~Cercle();

    void setInfos();
    void setRayon(int);
    void setRempli(bool);
    void setId(const char*);

    int getRayon() const;
    bool isRempli()const;
    const char* getInfos () const;

    friend ostream& operator<< (ostream&, const Cercle&);

    void Save(ostream&) const;
    void Load(ifstream&);

        //Fonction de dessine //
        void dessine();
};


ostream& operator<< (ostream&, const Cercle&);

#endif