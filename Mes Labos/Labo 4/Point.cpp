//
// Created by Doublon on 31/01/2018.
//

#include "Point.h"


int Point::compteurPoint=0;

Point::Point()
{
    setX(0);
    setY(0);

    this->compteurPoint++;
}

Point::~Point()
{
    this->compteurPoint--;
}

Point::Point(int x, int y)
{
    setX(x);
    setY(y);

    this->compteurPoint++;
}

Point::Point(const Point &point)
{
    setX(point.getX());
    setY(point.getY());

    this->compteurPoint++;
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

int Point::getCompteur()
{
    return compteurPoint;
}

ostream &operator<<(ostream &os, const Point &point)
{
    os << "Point : X : " << point.getX() << " Y : " << point.getY() << endl ;
    return os;
}


