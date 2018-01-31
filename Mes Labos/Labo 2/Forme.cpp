//
// Created by Doublon on 31/01/2018.
//

#include "Forme.h"
using namespace std;

int Forme::compteurForme=0;

Forme::Forme()
{
    this->id = NULL;
    this->position.setX(0);
    this->position.setY(0);
    this->couleur = NULL;
    setProfondeur(0);

    this->compteurForme++;
}

Forme::Forme(char *id, const Point &position, Couleur *couleur, int profondeur)
{
    setId(id);
    setCouleur(couleur);
    setPosition(position);
    setProfondeur(profondeur);

    this->compteurForme++;
}

Forme::Forme(char *id, const Point &position)
{
    setId(id);
    setCouleur(NULL);
    setPosition(position);
    setProfondeur(0);

    this->compteurForme++;
}

Forme::Forme(const Forme &forme)
{
    setId(forme.getId());
    setCouleur(forme.getCouleur());
    setPosition(forme.getPosition());
    setProfondeur(forme.getProfondeur());

    this->compteurForme++;
}

Forme::~Forme()
{
    this->compteurForme--;
}

char *Forme::getId() const
{
    return id;
}

void Forme::setId(char *id)
{
    if(id != NULL)
    {
        this->id = new char[strlen(id)+1];
        strcpy(getId(),id);
    }
    else
    {
        setId(NULL);
    }
}

const Point &Forme::getPosition() const
{
    return position;
}

void Forme::setPosition(const Point &position)
{
    this->position.setX(position.getX());
    this->position.setY(position.getY());
}

const Couleur *Forme::getCouleur() const
{
    return this->couleur;
}

void Forme::setCouleur(const Couleur *couleur)
{
    this->couleur = couleur;
}

int Forme::getProfondeur() const
{
    return profondeur;
}

void Forme::setProfondeur(int profondeur)
{
    this->profondeur = profondeur;
}

void Forme::Affiche() const
{
    if(getId() != NULL)
        cout << "Id : "<< getId() << endl;
    getPosition().Affiche();
    if(getCouleur() != NULL)
        getCouleur()->Affiche();
    else
        cout << "Aucune Couleur !" << endl;
    cout << "Profondeur  : " << getProfondeur() << endl;
}

int Forme::getCompteur()
{
    return compteurForme;
}


