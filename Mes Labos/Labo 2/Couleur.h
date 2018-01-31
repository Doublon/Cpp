//
// Created by Doublon on 30/01/2018.
//

#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>


class Couleur
{
    private :
        int rouge;
        int bleu;
        int vert;
        char * nom;

    public:
        Couleur();
        Couleur(int rouge, int bleu, int vert, char *nom);
        Couleur(int rouge, int bleu, int vert);
        Couleur(const Couleur& coul);
        virtual ~Couleur();

        int getRouge() const;

        void setRouge(int rouge);

        int getBleu() const;

        void setBleu(int bleu);

        int getVert() const;

        void setVert(int vert);

        char *getNom() const;

        void setNom(char *nom)const;

        void Affiche() const ;
};


#endif //COULEUR_H
