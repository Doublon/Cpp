//
// Created by Doublon on 30/01/2018.
//

#include "Couleur.h"

int Couleur::compteurCouleur=0;

Couleur::Couleur()
{
    setRouge(0);
    setBleu(0);
    setVert(0);
    setNom(NULL);

    this->compteurCouleur++;
}

Couleur::Couleur(int rouge, int bleu, int vert, string nom)
{
    setRouge(rouge);
    setBleu(bleu);
    setVert(vert);
    setNom(nom);

    this->compteurCouleur++;
}

Couleur::Couleur(int rouge, int bleu, int vert)
{
    setRouge(rouge);
    setBleu(bleu);
    setVert(vert);

    this->compteurCouleur++;
}

Couleur::Couleur(const Couleur &couleur)
{
    setRouge(couleur.getRouge());
    setBleu(couleur.getBleu());
    setVert(couleur.getVert());
    if(!couleur.getNom().empty())
        setNom(couleur.getNom());

    this->compteurCouleur++;
}

Couleur::~Couleur()
{
    this->compteurCouleur--;
}

int Couleur::getRouge() const
{
    return this->rouge;
}

void Couleur::setRouge(int rouge)
{
    Couleur::rouge = rouge;
}

int Couleur::getBleu() const
{
    return this->bleu;
}

void Couleur::setBleu(int bleu)
{
    Couleur::bleu = bleu;
}

int Couleur::getVert() const
{
    return this->vert;
}

void Couleur::setVert(int vert)
{
    Couleur::vert = vert;
}

string Couleur::getNom() const
{
    return nom;
}

void Couleur::Affiche() const
{
    cout << "Rouge : " << getRouge() << endl;
    cout << "Bleu : " << getBleu() << endl;
    cout << "Vert : " << getVert() << endl;
    if(!getNom().empty())
        cout << "Nom : " << getNom() << endl;

}

void Couleur::setNom(const string &nom)
{
    Couleur::nom = nom;
}

int Couleur::getCompteur()
{
    return compteurCouleur;
}



