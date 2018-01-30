#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <iostream>

class BaseException{
protected:
    char* Message;

public:
    BaseException();
    BaseException(char*);
    BaseException(const BaseException&);
    ~BaseException();

    void setMessage(const char*);
    const char* getMessage() const ;

    virtual void Afficher() const;


};

#endif