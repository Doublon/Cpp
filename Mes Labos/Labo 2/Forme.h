//
// Created by Doublon on 31/01/2018.
//

#ifndef FORME_H
#define FORME_H

#include <iostream>
#include "Point.h"
#include "Couleur.h"
#include <string>

using namespace std;

class Forme
{
    private:
        char* id;
        Point position;
        const Couleur *couleur;
        int profondeur;
        static int compteurForme;

    public:
        Forme();
        Forme(char *id, const Point &position, const Couleur *couleur, int profondeur);
        Forme(char *id, const Point &position);
        Forme(const Forme& forme);
        virtual ~Forme();

        char *getId() const;

        void setId(char *id);

        const Point &getPosition() const;

        void setPosition(const Point &position);

        const Couleur * getCouleur() const;

        void setCouleur(const Couleur *couleur);

        int getProfondeur() const;

        void setProfondeur(int profondeur);

        static int getCompteur();

        void Affiche()const;
};

#endif //LABO_2_FORME_H
