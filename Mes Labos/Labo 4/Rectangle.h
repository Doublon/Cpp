//
// Created by Doublon on 01/02/2018.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Forme.h"

class Rectangle : Forme
{
    private:
        int dimX , dimY;
        bool rempli;

    public:
        Rectangle();
        Rectangle(char* id, Point position);
        Rectangle(const Rectangle& rectangle);
        Rectangle(char* id, Point position,const Couleur* couleur, int profondeur);
        Rectangle(char* id, Point position,const Couleur* couleur, int profondeur , int dimX , int dimY , bool rempli );
        Rectangle(char* id, Point position,int dimX , int dimY , bool rempli , const Couleur* couleur, int profondeur );
        ~Rectangle();

        void setInfo();
        string getInfos() const ;

        int getDimX() const;

        void setDimX(int dimX);

        int getDimY() const;

        void setDimY(int dimY);

        bool isRempli() const;

        void setRempli(bool rempli);

        friend ostream& operator<< (ostream& os , const Rectangle& rectangle);
};

#endif //RECTANGLE_H
