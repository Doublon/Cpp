//
// Created by Doublon on 01/02/2018.
//

#include "Rectangle.h"

Rectangle::Rectangle() : Forme()
{
    setInfo();
    setDimX(0);
    setDimY(0);
    setRempli(false);
    compteurForme++;
}

Rectangle::Rectangle(char *id, Point position) : Forme (id , position)
{
    setInfo();
    setDimX(0);
    setDimY(0);
    setRempli(false);
    compteurForme++;
}

Rectangle::Rectangle(const Rectangle &rectangle) : Forme(rectangle.getId(),rectangle.getPosition(),rectangle.getCouleur(),rectangle.getProfondeur())
{
    setInfo();
    setDimX(0);
    setDimY(0);
    setRempli(false);
    compteurForme++;
}

Rectangle::Rectangle(char *id, Point position, const Couleur *couleur, int profondeur) : Forme(id,position,couleur,profondeur)
{
    setInfo();
    setDimX(0);
    setDimY(0);
    setRempli(false);
    compteurForme++;
}

Rectangle::Rectangle(char *id, Point position, const Couleur *couleur, int profondeur, int dimX, int dimY, bool rempli) : Forme(id,position,couleur,profondeur)
{
    setInfo();
    setDimX(dimX);
    setDimY(dimY);
    setRempli(rempli);
    compteurForme++;
}

Rectangle::Rectangle(char *id, Point position, int dimX, int dimY, bool rempli, const Couleur *couleur, int profondeur) : Forme(id,position,couleur,profondeur)
{
    setInfo();
    setDimX(dimX);
    setDimY(dimY);
    setRempli(rempli);
    compteurForme++;
}

Rectangle::~Rectangle()
{
    compteurForme--;
}

int Rectangle::getDimX() const
{
    return dimX;
}

void Rectangle::setDimX(int dimX)
{
    Rectangle::dimX = dimX;
}

int Rectangle::getDimY() const
{
    return dimY;
}

void Rectangle::setDimY(int dimY)
{
    Rectangle::dimY = dimY;
}

bool Rectangle::isRempli() const
{
    return rempli;
}

void Rectangle::setRempli(bool rempli)
{
    Rectangle::rempli = rempli;
}

void Rectangle::setInfo()
{
    stringstream ss;
    int rempli ;

    if(isRempli())
        rempli=1;
    else
        rempli=0;

    if(getCouleur() != NULL )
    {
        if(getCouleur()->getNom().empty())
            ss << "[RECTANGLE : Position("<< getPosition().getX() << "," << getPosition().getY()<< "), DimX=" << getDimX() << "DimY=" << getDimY() << " ,Rempli=" << rempli <<
                    "Couleur : (" << getCouleur()->getRouge() << "," << getCouleur()->getBleu() << "," << getCouleur()->getVert() << ", inconnu) , Profondeur = " << getProfondeur() << "]";
        else
            ss << "[RECTANGLE : Position("<< getPosition().getX() << "," << getPosition().getY()<< "), DimX=" << getDimX() << "DimY=" << getDimY() << " ,Rempli=" << rempli <<
               "Couleur : (" << getCouleur()->getRouge() << "," << getCouleur()->getBleu() << "," << getCouleur()->getVert() << "," << getCouleur()->getCompteur() <<
               ") , Profondeur = " << getProfondeur() << "]";

        this->infos = ss.str();
    }
    else
        this->infos = "aucune info !!!";
}

string Rectangle::getInfos() const
{
    return this->infos;
}

ostream &operator<<(ostream &os, const Rectangle &rectangle)
{
    int rempli ;

    if(rectangle.isRempli())
        rempli=1;
    else
        rempli=0;

    if(rectangle.getCouleur() != NULL )
    {
        if(rectangle.getCouleur()->getNom().empty())
            os << "[RECTANGLE : Position("<< rectangle.getPosition().getX() << "," << rectangle.getPosition().getY()<< "), DimX=" << rectangle.getDimX() << "DimY=" << rectangle.getDimY() <<
               " ,Rempli=" << rempli << "Couleur : (" << rectangle.getCouleur()->getRouge() << "," << rectangle.getCouleur()->getBleu() << "," << rectangle.getCouleur()->getVert() <<
               ", inconnu) , Profondeur = " <<rectangle. getProfondeur() << "]";
        else
            os << "[RECTANGLE : Position("<< rectangle.getPosition().getX() << "," << rectangle.getPosition().getY()<< "), DimX=" << rectangle.getDimX() << "DimY=" << rectangle.getDimY() <<
               " ,Rempli=" << rempli << "Couleur : (" << rectangle.getCouleur()->getRouge() << "," << rectangle.getCouleur()->getBleu() << "," << rectangle.getCouleur()->getVert() <<
               "," << rectangle.getCouleur()->getCompteur() << ") , Profondeur = " << rectangle.getProfondeur() << "]";

    }
    else
       os << "aucune info";

    return os;
}
