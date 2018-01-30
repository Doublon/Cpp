#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Ligne.h"
#include "Pixel.h"
#include "Rectangle.h"
#include "Cercle.h"

using namespace std;

template <class T> class SmartPointer
{
    private :
        T	*Val;

    public:

        SmartPointer();
        SmartPointer(T*);
        SmartPointer(const SmartPointer<T>&);
        ~SmartPointer();

        T* getVal() const;


        void Delete();

        SmartPointer<T>& operator= (const SmartPointer<T>&);

        T& operator*() const;
        T* operator->() const;
        int operator< (const SmartPointer<T>&);
        int operator> (const SmartPointer<T>&);
        int operator== (const SmartPointer<T>&);

        friend ostream& operator<< (ostream& S, const SmartPointer<T>& A)
        {
            S<<*(A.getVal());

            return S;
        }

};

#endif