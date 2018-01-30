#ifndef LISTEBASE_H
#define LISTEBASE_H
#include <iostream>
#include "Couleur.h"
#include "SmartPointer.h"


template<class T> struct Cellule{
    T Valeur;
    Cellule<T> *Suivant;
};

template <class T> class Iterateur;

template <class T> class ListeBase
{
    protected :
        Cellule<T>  *pTete;

    public:

        ListeBase();
        ListeBase(const ListeBase&);
        ~ListeBase();

        bool estVide() const;
        Cellule<T>* getTete() const;
        int getNombreElements() const;

        void Affiche() const;
        void SetTeteNull();
        virtual T* insere(const T&)=0;
        ListeBase<T>& operator=  (const ListeBase&);
        friend class Iterateur<T>;

};


#endif