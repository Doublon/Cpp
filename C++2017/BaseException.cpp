#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "BaseException.h"


BaseException::BaseException()
{
    Message=NULL;
}
BaseException::BaseException(char *S)
{
    setMessage(S);
}
BaseException::BaseException(const BaseException& A)
{
    setMessage(A.Message);
}
BaseException::~BaseException()
{
    if(Message!=NULL)
        delete Message;
}

void BaseException::setMessage(const char *S)
{
    if(S!=NULL)
    {
        Message= new char[strlen(S)+1];
        strcpy(Message,S);
    }
    else
        Message=NULL;
}
const char* BaseException::getMessage() const
{
    return this->Message;
}

void BaseException::Afficher() const
{
    if(getMessage()!=NULL)
        cout<<getMessage()<<endl;
    else
        cout<<"Erreur";
}