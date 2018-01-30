#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "ListeBase.h"

template <class T>
ListeBase<T>::ListeBase()
{
   pTete=NULL;
}

template <class T>
ListeBase<T>::ListeBase(const ListeBase& A)
{
    Cellule<T> *pSuivant, *pPrecedent;
    Cellule<T> *pNew=NULL;

    pSuivant=A.getTete();
    pPrecedent=NULL;
    pNew=NULL;

    pNew= new Cellule<T>;
    pNew->Valeur=pSuivant->Valeur;

    pPrecedent=pNew;
    pSuivant=pSuivant->Suivant;
    this->pTete=pNew;

    while(pSuivant!=NULL)
    {
        pNew= NULL;
        pNew= new Cellule<T>;
        pNew->Valeur=pSuivant->Valeur;
        pPrecedent->Suivant=pNew;

        pPrecedent=pNew;
        pSuivant=pSuivant->Suivant;
    }

    pPrecedent->Suivant=NULL;

}

template <class T>
bool ListeBase<T>::estVide() const
{
    if(pTete==NULL)
        return true;
    else
        return false;
}

template <class T>
int ListeBase<T>::getNombreElements() const
{
    Cellule<T> *Svt ;
     Svt=this->pTete;
    int Total=0;

    if(Svt==NULL)
        return 0;
    else
    {
        while (Svt != NULL) {
            Total++;
            Svt=Svt->Suivant;
        }
        return Total;
    }
}

template <class T>
Cellule<T>* ListeBase<T>::getTete() const
{
    return  this->pTete;
}

template <class T>
void ListeBase<T>::SetTeteNull()
{
    this->pTete=NULL;
}

template <class T>
void ListeBase<T>::Affiche() const
{
    struct Cellule<T> *pSuivant;
    pSuivant=this->pTete;

    while(pSuivant!=NULL)
    {
        cout<<pSuivant->Valeur<<endl;
        pSuivant=pSuivant->Suivant;
    }
}

template <class T>
ListeBase<T>& ListeBase<T>::operator=  (const ListeBase& A)
{
    Cellule<T> *pSuivant, *pPrecedent;
    Cellule<T> *pNew=NULL;

    pSuivant=A.getTete();
    pPrecedent=NULL;
    pNew=NULL;

    pNew= new Cellule<T>;
    pNew->Valeur=pSuivant->Valeur;

    pPrecedent=pNew;
    pSuivant=pSuivant->Suivant;
    this->pTete=pNew;

    while(pSuivant!=NULL)
    {
    pNew= NULL;
    pNew= new Cellule<T>;
    pNew->Valeur=pSuivant->Valeur;
    pPrecedent->Suivant=pNew;

    pPrecedent=pNew;
    pSuivant=pSuivant->Suivant;
    }

    pPrecedent->Suivant=NULL;

    return *this;
}

template <class T>
ListeBase<T>::~ListeBase()
{
    Cellule<T> *pTmp;
    pTmp=this->pTete;
    while(pTmp!=NULL)
    {
        pTmp=(this->pTete->Suivant);
        delete pTete;
        pTete=pTmp;
    }
    pTete=NULL;

}



template class ListeBase <int>;
template class ListeBase <int*>;
template class ListeBase <Couleur>;
template class ListeBase <SmartPointer<int> >;
template class ListeBase <SmartPointer<Forme> >;
