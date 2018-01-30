#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

class Point {
	private:
		int X;
		int Y;
		static int CptPoint;

	public:
		Point();
		Point(int, int);
		Point(const Point&);
		~Point();

		
		void setX(int);
		void setY (int);

		
		int getX () const;
		int getY () const;
		static int getCompteur();		
		
		void Affiche () const;

		Point& operator=(const Point&);
		friend ostream& operator<< (ostream&, const Point&);

		void Save(ostream&) const;
		void Load(ifstream&);
};

ostream& operator<< (ostream&, const Point&);
#endif