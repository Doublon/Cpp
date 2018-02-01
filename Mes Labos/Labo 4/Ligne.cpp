//
// Created by Doublon on 01/02/2018.
//


#include "Ligne.h"

Ligne::Ligne() : Forme()
{
    this->extremite.setX(0);
    this->extremite.setY(0);
    compteurForme++;
}

Ligne::Ligne(char *id, Point position) : Forme (id , position)
{
    this->extremite.setX(0);
    this->extremite.setY(0);
    compteurForme++;
}

Ligne::Ligne(const Ligne &ligne) : Forme(ligne.getId(),ligne.getPosition(),ligne.getCouleur(),ligne.getProfondeur())
{
    setExtremite(ligne.getExtremite());
    compteurForme++;
}

Ligne::Ligne(char *id, Point position, const Couleur *couleur, int profondeur) : Forme(id,position,couleur,profondeur)
{
    this->extremite.setX(0);
    this->extremite.setY(0);
    compteurForme++;
}

Ligne::Ligne(char *id, Point position, const Couleur *couleur, int profondeur, Point extremite) : Forme(id,position,couleur,profondeur)
{
    setExtremite(extremite);
    compteurForme++;
}

Ligne::Ligne(char *id, Point position, Point extremite, const Couleur *couleur, int profondeur) : Forme(id,position,couleur,profondeur)
{
    setExtremite(extremite);
    compteurForme++;
}

Ligne::~Ligne()
{
    compteurForme--;
}

void Ligne::setInfo()
{
    stringstream ss;

    if(getCouleur() != NULL )
    {
        if(getCouleur()->getNom().empty())
            ss << "[LIGNE : Position("<< getPosition().getX() << "," << getPosition().getY()<< ") Extremite : (" << getExtremite().getX() << "," << getExtremite().getY() << ") "
                    "Couleur : (" << getCouleur()->getRouge() << "," << getCouleur()->getBleu() << "," << getCouleur()->getVert() << ", inconnu) , Profondeur = " << getProfondeur() << "]";
        else
            ss << "[LIGNE : Position("<< getPosition().getX() << "," << getPosition().getY()<< ") Extremite : (" << getExtremite().getX() << "," << getExtremite().getY() << ") "
                    "Couleur : (" << getCouleur()->getRouge() << "," << getCouleur()->getBleu() << "," << getCouleur()->getVert() << "," << getCouleur()->getCompteur() <<
                    ") , Profondeur = " << getProfondeur() << "]";

        this->infos = ss.str();
    }
    else
        this->infos = "aucune info !!!";
}

string Ligne::getInfos() const
{
    if(this->infos.empty())
        return "Aucune info";
    else
        return this->infos;
}

const Point &Ligne::getExtremite() const
{
    return this->extremite;
}

void Ligne::setExtremite(const Point &extremite)
{
    this->extremite.setX(extremite.getX());
    this->extremite.setX(extremite.getY());
}

ostream &operator<<(ostream &os, const Ligne &ligne)
{
    if(ligne.getCouleur() != NULL)
    {
        if(ligne.getCouleur()->getNom().empty())
            os << "[LIGNE : Position("<< ligne.getPosition().getX() << "," << ligne.getPosition().getY()<< ") Extremite : (" << ligne.getExtremite().getX() << "," << ligne.getExtremite().getY() << ") "
                    "Couleur : (" << ligne.getCouleur()->getRouge() << "," << ligne.getCouleur()->getBleu() << "," << ligne.getCouleur()->getVert() << ", inconnu) , Profondeur = " <<
                    ligne.getProfondeur() << "]";
        else
            os << "[LIGNE : Position("<< ligne.getPosition().getX() << "," << ligne.getPosition().getY()<< ") Extremite : (" << ligne.getExtremite().getX() << "," << ligne.getExtremite().getY() << ") "
                    "Couleur : (" << ligne.getCouleur()->getRouge() << "," << ligne.getCouleur()->getBleu() << "," << ligne.getCouleur()->getVert() << "," << ligne.getCouleur()->getCompteur() <<
                    ") , Profondeur = " << ligne.getProfondeur() << "]";
    }
    else
    {
        os << "[LIGNE : Position("<< ligne.getPosition().getX() << "," << ligne.getPosition().getY()<< ") Extremite : (" << ligne.getExtremite().getX() << "," <<
           ligne.getExtremite().getY() << ") Couleur : (0,0,0,aucune) , Profondeur = " << ligne.getProfondeur() << "]";
    }


    return os;
}

