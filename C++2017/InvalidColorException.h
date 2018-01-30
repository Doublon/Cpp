#ifndef INVALIDCOLOREXCEPTION_H
#define INVALIDCOLOREXCEPTION_H

#include <iostream>
#include "BaseException.h"

class InvalidColorException : public BaseException {
    private:
        bool RougeVal;
        bool BleuVal;
        bool VertVal;
    public:

        //Fonctions constructeurs et destructeur //
        InvalidColorException();
        InvalidColorException(char*);
        InvalidColorException(char*,bool,bool,bool);
        InvalidColorException(const InvalidColorException&);

        //Fonctions set //
        void setRougeVal (bool);
        void setBleuVal (bool);
        void setVertVal (bool);
        void setCouleurVal (bool,bool,bool);

        //Fonctions validité //
        bool RougeValide() const;
        bool BleuValide() const;
        bool VertValide() const;
        void Afficher() const;
};

#endif