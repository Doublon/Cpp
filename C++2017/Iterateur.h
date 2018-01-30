#ifndef ITERATEUR_H
#define ITERATEUR_H
#include <iostream>
#include "ListeBase.h"


template <class T>
class Iterateur
{

private:
    ListeBase<T>& Li;
    Cellule<T> *Pointeur;
public:

    //Fonctions de gestion de l'itérateur //
    Iterateur(ListeBase<T>&);
    void reset ();
    bool end();
    T remove();
    Cellule<T>* getPointeur();

    //Fonctions operator //
    void operator++ (int);
    Iterateur<T>& operator=(T);
    operator T() const;
    T* operator& () ;
};

#endif