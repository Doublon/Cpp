//
// Created by Doublon on 30/01/2018.
//

#include "Couleur.h"

int Couleur::compteurCouleur=0;

const Couleur Couleur::ROUGE(255,0,0,"Rouge");
const Couleur Couleur::BLEU(0,0,255,"Bleu");
const Couleur Couleur::VERT(0,255,0,"Vert");

Couleur::Couleur()
{
    setRouge(0);
    setBleu(0);
    setVert(0);

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

int Couleur::getLuminance() const
{
    return (getRouge()+getBleu()+getVert())/3;
}

bool Couleur::operator==(const Couleur &rhs) const
{
    return rouge == rhs . rouge &&
           bleu == rhs . bleu &&
           vert == rhs . vert &&
           nom == rhs . nom;
}

bool Couleur::operator!=(const Couleur &rhs) const
{
    return !(rhs == *this);
}

Couleur &Couleur::operator=(const Couleur& couleur)
{
    setNom(couleur.getNom());
    setVert(couleur.getVert());
    setBleu(couleur.getBleu());
    setRouge(couleur.getRouge());

    return *this;
}

Couleur Couleur::operator+(const Couleur &couleur) const
{
    int rouge = getRouge()+couleur.getRouge();
    int vert = getVert()+couleur.getVert();
    int bleu = getBleu()+couleur.getBleu();
    string nom = getNom()+couleur.getNom();

    Couleur newCouleur(rouge,bleu,vert,nom);
    return newCouleur;
}

Couleur Couleur::operator+(const int nombre) const
{
    int rouge = getRouge()+nombre;
    int vert = getVert()+nombre;
    int bleu = getBleu()+nombre;

    Couleur newCouleur(rouge,bleu,vert,getNom());
    return newCouleur;
}

Couleur operator+(const int nombre, const Couleur &couleur)
{
    Couleur newCouleur;
    newCouleur = couleur+nombre;

    return newCouleur;
}

Couleur Couleur::operator-(const int nombre) const
{
    int rouge = getRouge()-nombre;
    int vert = getVert()-nombre;
    int bleu = getBleu()-nombre;

    Couleur newCouleur(rouge,bleu,vert,getNom());
    return newCouleur;
}

bool Couleur::operator<(const Couleur &rhs) const
{
    if (rouge < rhs . rouge)
        return true;
    if (rhs . rouge < rouge)
        return false;
    if (bleu < rhs . bleu)
        return true;
    if (rhs . bleu < bleu)
        return false;
    if (vert < rhs . vert)
        return true;
    if (rhs . vert < vert)
        return false;
    return nom < rhs . nom;
}

bool Couleur::operator>(const Couleur &rhs) const
{
    return rhs < *this;
}

bool Couleur::operator<=(const Couleur &rhs) const
{
    return !(rhs < *this);
}

bool Couleur::operator>=(const Couleur &rhs) const
{
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Couleur &couleur)
{
    os << "rouge: " << couleur . rouge << " bleu: " << couleur . bleu << " vert: " << couleur . vert << " nom: "
       << couleur . nom;

    return os;
}

istream &operator>>(istream &is, const Couleur &couleur)
{
    int rouge;
    cout << "Rouge : ";
    is >> rouge;

    int bleu;
    cout << "Bleu : ";
    is >> bleu;

    int vert;
    cout << "Vert : ";
    is >> vert;

    string nom;
    cout << "Rouge : ";
    is >> nom;

    return is;
}



