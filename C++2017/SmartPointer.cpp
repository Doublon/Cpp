using namespace std;
#include "SmartPointer.h"

template <class T>
SmartPointer<T>::SmartPointer()
{
    this->Val=NULL;
}

template <class T>
SmartPointer<T>::SmartPointer(T* A) : Val(A) {}


template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &A): Val(A.Val) {}
/*
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T> &A)
{
    this->Val=A.getVal();
    return *this;
}
*/
template <class T>
T* SmartPointer<T>::getVal() const
{
    return (this->Val);
}

template <class T>
void SmartPointer<T>::Delete()
{
    delete this->Val;
    this->Val=NULL;

}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator= (const SmartPointer<T>& A)
{
    this->Val = A.Val;
    return *this;
}

template <class T>
T& SmartPointer<T>::operator*() const
{
    return *Val;
}

template <class T>
T* SmartPointer<T>::operator->() const
{
    return Val;
}

template <class T>
int SmartPointer<T>::operator< (const SmartPointer<T> &A)
{
    return (*(this->Val)<*(A.getVal()));
}

template <class T>
int SmartPointer<T>::operator> (const SmartPointer<T> &A)
{
    return (*(this->Val)>*(A.getVal()));
}

template <class T>
int SmartPointer<T>::operator== (const SmartPointer<T> &A)
{

    return (*(this->Val)==*(A.getVal()));
}

template <class T>
SmartPointer<T>::~SmartPointer (){}


template class SmartPointer <int>;
template class SmartPointer <Ligne>;
template class SmartPointer <Forme>;