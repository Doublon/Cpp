#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Forme.h"


class Rectangle : public Forme {

private:
    int DimX;
    int DimY;
    bool Rempli;
public:
    Rectangle();
    Rectangle(const char* S, Point P);
    Rectangle (const Rectangle&);
    Rectangle(const char*, Point, int, int, bool, const Couleur*, int);
    ~Rectangle();

    void setInfos();
    void setDimX(int);
    void setDimY(int);
    void setRempli(bool);
    void setId(const char*);

    int getDimX() const;
    int getDimY() const;
    bool isRempli()const;
    const char* getInfos () const;

    friend ostream& operator<< (ostream&, const Rectangle&);

    void Save(ostream&) const;
    void Load(ifstream&);

        //Fonction de dessine //
        void dessine();
};


ostream& operator<< (ostream&, const Rectangle&);

#endif