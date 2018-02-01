//
// Created by Doublon on 01/02/2018.
//

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include "Forme.h"

class Pixel : public Forme
{
    public:
        Pixel();
        Pixel(char* id, Point point);
        Pixel(const Pixel& pixel);
        Pixel(char* id, Point point,const Couleur* couleur, int profondeur);
        ~Pixel();

        void setInfo();
        string getInfos() const ;

        friend ostream& operator<< (ostream& os , const Pixel& pixel);

};

#endif //PIXEL_H
