#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#include "InvalidColorException.h"


//Fonctions constructeurs et destructeur //
InvalidColorException::InvalidColorException():BaseException()
{
    setRougeVal(true);
    setBleuVal(true);
    setVertVal(true);
};

InvalidColorException::InvalidColorException(char* S):BaseException(S)
{
    setRougeVal(true);
    setBleuVal(true);
    setVertVal(true);
}
InvalidColorException::InvalidColorException(char* S, bool R, bool V, bool B):BaseException(S)
{
    setRougeVal(R);
    setBleuVal(B);
    setVertVal(V);
}
InvalidColorException::InvalidColorException(const InvalidColorException& A):BaseException(A)
{
    setRougeVal(A.RougeValide());
    setBleuVal(A.BleuValide());
    setVertVal(A.VertValide());
}


//Fonctions set de la classe //
void InvalidColorException::setRougeVal(bool A)
{
    RougeVal=A;
}

void InvalidColorException::setBleuVal(bool A)
{
    BleuVal=A;
}

void InvalidColorException::setVertVal(bool A)
{
    VertVal=A;
}


//Fonctions validité //
bool InvalidColorException::RougeValide() const
{
    return this->RougeVal;
}
bool InvalidColorException::BleuValide() const
{
    return this->BleuVal;
}

bool InvalidColorException::VertValide() const
{
    return this->VertVal;
}

//Fonctions affichages //
void InvalidColorException::Afficher() const
{
    if(getMessage()!=NULL)
        cout<<getMessage()<<endl;

    if(!RougeValide())
        cout<<"Rouge invalide"<<endl;

    if(!BleuValide())
        cout<<"Bleu invalide"<<endl;

    if(!VertValide())
        cout<<"Vert invalide"<<endl;
}