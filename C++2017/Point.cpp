using namespace std;
#include "Point.h"

int Point::CptPoint= 0 ;

Point::Point()
{
	X=0;
	Y=0;
	CptPoint++;
}

Point::Point(int X1, int Y1)
{
	X=X1;
	Y=Y1;
	CptPoint++;
}

Point::Point(const Point& A)
{
	X=A.getX();
	Y=A.getY();
	CptPoint++;
}

void Point::setX (int X1)
{
	X=X1;
}

void Point::setY (int Y1)
{
	Y=Y1;
}


int Point::getX () const
{
	return this->X;
}

int Point::getY () const
{
	return this->Y;
}

int Point::getCompteur ()
{
	return CptPoint;
}

void Point::Affiche() const
{
	cout << "(" << X <<","<<Y<<")"<< endl;
}

Point::~Point ()
{
	CptPoint--;

}

ostream& operator<< (ostream& S, const Point& P)
{
	S << "("<<P.X<<","<<P.Y<<")";

	return S;
}

Point& Point::operator=(const Point& A)
{
	setX(A.getX());
	setY(A.getY());

	return *this;
}

void Point::Save(ostream& Fichier) const
{
	Fichier.write((char*)&X, sizeof(int));
	Fichier.write((char*)&Y, sizeof(int));

}

void Point::Load(ifstream& Fichier)
{
	int tmp;

	Fichier.read((char*)&tmp, sizeof(int));
	setX(tmp);
	Fichier.read((char*)&tmp, sizeof(int));
	setY(tmp);

}