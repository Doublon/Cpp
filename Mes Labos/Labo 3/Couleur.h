//
// Created by Doublon on 30/01/2018.
//

#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

class Couleur
{
    private :
        int rouge;
        int bleu;
        int vert;
        string nom;
        static int compteurCouleur;

    public:
        static const Couleur ROUGE;
        static const Couleur BLEU;
        static const Couleur VERT;

        Couleur();
        Couleur(int rouge, int bleu, int vert, string nom);
        Couleur(int rouge, int bleu, int vert);
        Couleur(const Couleur& coul);
        virtual ~Couleur();

        int getRouge() const;

        void setRouge(int rouge);

        int getBleu() const;

        void setBleu(int bleu);

        int getVert() const;

        void setVert(int vert);

        string getNom() const;

        void setNom(const string &nom);

        static int getCompteur();

        void Affiche() const ;

        int getLuminance() const;

        bool operator==(const Couleur &rhs) const;

        bool operator!=(const Couleur &rhs) const;

        Couleur& operator = (const Couleur& couleur);
        Couleur operator+ (const Couleur& couleur) const ;
        Couleur operator+ (const int nombre)const;
        friend Couleur operator+ (const int nombre , const Couleur& couleur);
        Couleur operator- (const int nombre)const;
};


#endif //COULEUR_H
