//
// Created by Doublon on 01/02/2018.
//

#include <sstream>
#include "Pixel.h"

Pixel::Pixel() : Forme()
{
    setInfo();
    compteurForme++;
}

Pixel::Pixel(char* id, Point point) : Forme(id,point)
{
    setInfo();
    compteurForme++;
}

Pixel::Pixel(const Pixel& pixel) : Forme(pixel.getId(),pixel.getPosition(),pixel.getCouleur(),pixel.getProfondeur())
{
    setInfo();
    compteurForme++;
}

Pixel::Pixel(char* id, Point point,const Couleur* couleur, int profondeur) : Forme(id,point,couleur,profondeur)
{
    setInfo();
    compteurForme++;
}

Pixel::~Pixel ()
{
    compteurForme--;
}

void Pixel::setInfo()
{
    stringstream ss;

    if(getCouleur() != NULL )
    {
        if(getCouleur()->getNom().empty())
            ss << "[PIXEL : Position("<< getPosition().getX() << "," << getPosition().getY()<< ")" << "Couleur : (" << getCouleur()->getRouge() << "," << getCouleur()->getBleu() << "," <<
               getCouleur()->getVert() << ", inconnu) , Profondeur = " << getProfondeur() << "]";
        else
            ss << "[PIXEL : Position("<< getPosition().getX() << "," << getPosition().getY()<< ")" << "Couleur : (" << getCouleur()->getRouge() << "," << getCouleur()->getBleu() << "," <<
               getCouleur()->getVert() << "," << getCouleur()->getCompteur() << ") , Profondeur = " << getProfondeur() << "]";

        this->infos = ss.str();
    }
    else
        this->infos = "Aucune info !!!";
}

string Pixel::getInfos() const
{
    if(this->infos.empty())
        return "Aucune info";
    else
        return this->infos;
}

ostream &operator<<(ostream &os, const Pixel &pixel)
{
    if(pixel.getCouleur() != NULL)
    {
        if(pixel.getCouleur()->getNom().empty())
            os << "[PIXEL : Position("<< pixel.getPosition().getX() << "," << pixel.getPosition().getY()<< ")" << "Couleur : (" << pixel.getCouleur()->getRouge() << "," <<
               pixel.getCouleur()->getBleu() << "," << pixel.getCouleur()->getVert() << ", inconnu) , Profondeur = " << pixel.getProfondeur() << "]";
        else
            os << "[PIXEL : Position("<< pixel.getPosition().getX() << "," << pixel.getPosition().getY()<< ")" << "Couleur : (" << pixel.getCouleur()->getRouge() << "," <<
               pixel.getCouleur()->getBleu() << "," << pixel.getCouleur()->getVert() << "," << pixel.getCouleur()->getCompteur() << ") , Profondeur = " << pixel.getProfondeur() << "]";
    }
    else
    {
        os << "[PIXEL : Position("<< pixel.getPosition().getX() << "," << pixel.getPosition().getY()<< ")" << "Couleur : (0,0,0,aucune) , Profondeur = " << pixel.getProfondeur() << "]";
    }


    return os;
}
