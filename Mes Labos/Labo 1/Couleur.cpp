//
// Created by Doublon on 30/01/2018.
//

#include "Couleur.h"
using namespace std;

Couleur::Couleur()
{
    setRouge(0);
    setBleu(0);
    setVert(0);
    setNom("inconnu");
}

Couleur::Couleur(int rouge, int bleu, int vert, char *nom)
{
    setRouge(rouge);
    setBleu(bleu);
    setVert(vert);
    setNom(nom);
}

Couleur::Couleur(int rouge, int bleu, int vert) : rouge(rouge), bleu(bleu), vert(vert)
{
    setRouge(rouge);
    setBleu(bleu);
    setVert(vert);
}

Couleur::Couleur(const Couleur &couleur)
{
    setRouge(couleur.getRouge());
    setBleu(couleur.getBleu());
    setVert(couleur.getVert());
    if(couleur.getNom()!=NULL)
        setNom(couleur.getNom());
}

Couleur::~Couleur()
{

}

int Couleur::getRouge() const
{
    return rouge;
}

void Couleur::setRouge(int rouge)
{
    Couleur::rouge = rouge;
}

int Couleur::getBleu() const
{
    return bleu;
}

void Couleur::setBleu(int bleu)
{
    Couleur::bleu = bleu;
}

int Couleur::getVert() const
{
    return vert;
}

void Couleur::setVert(int vert)
{
    Couleur::vert = vert;
}

char *Couleur::getNom() const
{
    return nom;
}

void Couleur::setNom(char *nom)
{
    Couleur::nom = nom;
}

void Couleur::Affiche() const
{
    cout << "Rouge : " << getRouge() << endl;
    cout << "Bleu : " << getBleu() << endl;
    cout << "Vert : " << getVert() << endl;
    if(getNom()!=NULL)
        cout << "Nom : " << getNom() << endl;

}



