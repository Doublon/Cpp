#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "ListeTriee.h"

template <class T>
T* ListeTriee<T>::insere(const T& V)
{
    Cellule<T> *pNew;
    Cellule<T> *pSuivant;
    Cellule<T> *pPrecedent;

    pPrecedent=NULL;
    pSuivant=this->pTete;

    pNew= new Cellule<T>;
    pNew->Valeur=V;

    while(pSuivant!=NULL && pNew->Valeur>pSuivant->Valeur)
    {
        pPrecedent=pSuivant;
        pSuivant=pSuivant->Suivant;
    }

    if(pPrecedent==NULL)
    {
        this->pTete=pNew;
        pNew->Suivant=pSuivant;
    }
    else
    {
        pNew->Suivant=pSuivant;
        pPrecedent->Suivant=pNew;
    }


    return &pNew->Valeur;
}

template class ListeTriee <int> ;
template class ListeTriee <int*>;
template class ListeTriee <Couleur> ;
template class ListeTriee <SmartPointer<int> > ;


template class ListeTriee <SmartPointer<Forme> > ;