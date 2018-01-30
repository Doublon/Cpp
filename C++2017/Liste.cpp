#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Liste.h"

template <class T>
T* Liste<T>::insere(const T& V)
{
    Cellule <T>*New;
    Cellule <T>*pSuivant;



    New= new Cellule<T>;
    New->Valeur=V;
    New->Suivant=NULL;

    if(this->pTete!=NULL)
    {
        pSuivant=this->pTete;
        while(pSuivant->Suivant!=NULL)
            pSuivant=pSuivant->Suivant;
        pSuivant->Suivant=New;
    }
    else
        this->pTete=New;


    return &New->Valeur;

}

template class Liste<int>;
template class Liste<Couleur>;