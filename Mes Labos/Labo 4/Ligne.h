//
// Created by Doublon on 01/02/2018.
//

#ifndef LIGNE_H
#define LIGNE_H

#include "Forme.h"

class Ligne : public Forme
{
    private:
        Point extremite;

    public:
        Ligne();
        Ligne(char* id, Point position);
        Ligne(const Ligne& ligne);
        Ligne(char* id, Point position,const Couleur* couleur, int profondeur);
        Ligne(char* id, Point position,const Couleur* couleur, int profondeur , Point extremite);
        Ligne(char* id, Point position,Point extremite , const Couleur* couleur, int profondeur );
        ~Ligne();

        void setInfo();
        string getInfos() const ;

        const Point &getExtremite() const;

        void setExtremite(const Point &extremite);

        friend ostream& operator<< (ostream& os , const Ligne& ligne);
};

#endif //LIGNE_H
