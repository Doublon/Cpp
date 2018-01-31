//
// Created by Doublon on 31/01/2018.
//

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <stdlib.h>

class Point
{
    private:
        int x;
        int y;

    public:
        Point();
        Point(int x, int y);
        Point(const Point& point);
        virtual ~Point();

        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);

        void Affiche()const;

};

#endif //POINT_H
