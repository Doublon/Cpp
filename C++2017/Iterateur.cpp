#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Iterateur.h"


//Fonctions de gestion de l'itérateur //

template <class T>
Iterateur<T>::Iterateur(ListeBase<T> &A):Li(A),Pointeur(Li.getTete()) {}

template <class T>
void Iterateur<T>::reset()
{
    this->Pointeur=(this->Li).getTete();
}

template <class T>
bool Iterateur<T>::end()
{
    if(this->Pointeur!=NULL)
        return false;
    else
        return true;
}

template <class T>
T Iterateur<T>::remove ()
{
    Cellule<T> *pPrec;
    T Sup;

    pPrec = this->Li.getTete();

    if (pPrec != Pointeur)
    {
        while (pPrec->Suivant != Pointeur)
                 pPrec = pPrec->Suivant;

        pPrec->Suivant = Pointeur->Suivant;
    }
    else
        Li.pTete = Li.pTete->Suivant;

    delete Pointeur;
    Sup = Pointeur->Valeur;

    Pointeur = Li.getTete();

    return Sup;

}


//Fonctions operator //
template <class T>
void Iterateur<T>::operator++(int a)
{
    this->Pointeur=(this->Pointeur)->Suivant;

}

template <class T>
Iterateur<T>& Iterateur<T>:: operator= (T V)
{
    (this->Pointeur)->Valeur=V;

    return *this;
}

template <class T>
Iterateur<T>::operator T() const
{
    return (this->Pointeur)->Valeur;
}

template <class T>
T* Iterateur<T>::operator& ()
{
    return &((this->Pointeur)->Valeur);
}

template <class T>
Cellule<T>* Iterateur<T>::getPointeur()
{
    return this->Pointeur;
}


template class Iterateur <int>;
template class Iterateur <int*>;
template class Iterateur <Couleur>;
template class Iterateur <SmartPointer<int> > ;
template class Iterateur <SmartPointer<Forme> > ;