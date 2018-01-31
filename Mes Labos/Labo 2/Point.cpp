//
// Created by Doublon on 31/01/2018.
//

#include "Point.h"
using namespace std;

Point::Point()
{
    setX(0);
    setY(0);
}

Point::~Point()
{

}

Point::Point(int x, int y)
{
    setX(x);
    setY(y);
}

Point::Point(const Point &point)
{
    setX(point.getX());
    setY(point.getY());
}

int Point::getX() const
{
    return x;
}

void Point::setX(int xi)
{
    x = xi;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int yi)
{
    y = yi;
}

void Point::Affiche() const
{
    cout << "X : " << getX() << endl;
    cout << "Y :" <<getY() << endl;
}


