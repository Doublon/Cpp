#ifndef LISTETRIEE_H
#define LISTETRIEE_H
#include <iostream>
#include "ListeBase.h"


template <class T>
class ListeTriee: public ListeBase<T>
{
    public:
        T* insere(const T&);
};

#endif