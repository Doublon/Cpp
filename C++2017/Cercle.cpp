#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Cercle.h"


Cercle::Cercle():Forme()
{
    Rayon=0;
    Rempli=false;
    setInfos();
}


Cercle::Cercle(const char* S, Point P):Forme(S,P)
{
    setId(S);
    Rayon=0;
    Rempli=false;
    setInfos();
}

Cercle::Cercle(const char* S, Point P, int Ry, int DY, bool Rem, const Couleur* C, int prof):Forme(S,P,C,prof)
{
    setId(S);
    Rayon=Ry;
    Rempli=Rem;
    setInfos();
}

Cercle::Cercle(const Cercle& A):Forme (A)
{
    setId(A.getId());
    Rayon=A.getRayon();
    Rempli=A.isRempli();
    Infos= new char[strlen(A.Infos)+1]; strcpy(Infos,A.Infos);
}


void Cercle::setRayon (int Ry)
{
    Rayon=Ry;
    setInfos();
}

void Cercle::setRempli(bool R)
{
    Rempli=R;
}

int Cercle::getRayon () const
{
    return this->Rayon;
}


bool Cercle::isRempli() const
{
    return this->Rempli;
}

void Cercle::setInfos()
{
    char *Buffer1=NULL;
    char Buffer2 [150];
    int R=0,B=0,V=0;


    if (couleur!=NULL)
    {
        R=couleur->getRouge();
        B=couleur->getBleu();
        V=couleur->getVert();

        if(couleur->getNom()!=NULL) {
            Buffer1 = new char[strlen(couleur->getNom()) + 1];
            strcpy(Buffer1, couleur->getNom());
        }
        else
        {
            Buffer1= new char[8];
            strcpy(Buffer1,"Inconnu");
        }
    }
    else
    {
        Buffer1= new char[8];
        strcpy(Buffer1,"Inconnu");
    }

    if(Infos!=NULL);
    delete Infos;

    sprintf(Buffer2,"Cercle %s: Position(%d , %d), Rayon= %d, Rempli = %d Couleur( %d, %d, %d, %s) , Profondeur=%d",Id, Position.getX(), Position.getY(),Rayon, Rempli, R, B, V, Buffer1,Profondeur);
    Infos= new char[strlen(Buffer2)+1];
    strcpy(Infos,Buffer2);



    delete Buffer1;

}

const char* Cercle::getInfos () const
{
    if (Infos!=NULL)
        return this->Infos;
    else
        return "Aucune";
}

Cercle::~Cercle ()
{
    if(Id!=NULL)
    {
        delete Id;
    }
    if(Infos!=NULL)
    {
        delete Infos;
    }
    CptForme--;

}

ostream& operator<< (ostream& S, const Cercle& R)
{
    int Ro=0,B=0,V=0;
    char *Buffer=NULL;


    if(R.couleur!=NULL)
    {
        Ro=R.couleur->getRouge();
        B=R.couleur->getBleu();
        V=R.couleur->getVert();

        if(R.couleur->getNom()!=NULL)
        {
            Buffer = new char[strlen(R.couleur->getNom()) + 1];
            strcpy(Buffer, R.couleur->getNom());
        }
        else
        {
            Buffer = new char[8];
            strcpy(Buffer, "Inconnu");
        }
    }
    else
    {
        Buffer=new char [8];
        strcpy(Buffer,"Inconnu");
    }



    S << "CERCLE "<<R.Id <<": Position:"<<R.Position <<",Rayon="<<R.Rayon<<", Rempli="<<R.isRempli()<<", Couleur:(" << Ro<<","<<B<<","<< V <<"," <<Buffer <<"), Profondeur= "<<R.Profondeur <<endl;

    delete Buffer;

    return S;

}

void Cercle::setId (const char* S)
{
    char Check[80];
    int i=0;

    if(S==NULL)
        throw BaseException((char *)"L'id est NULL");

    strcpy(Check,S);

    if (Check[i] != 'C')
        throw BaseException((char *)"L'Id des cercles doit commencer par 'C'");

    i++;

    while (isdigit(Check[i]) && Check[i] != '\0')
        i++;

    if (Check[i] != '\0' || i < 2)
        throw BaseException((char *) "Il doit y avoir minimum 2 caractère et que des chiffres après le 'C'");

    Id= new char[strlen(S)+1];
    strcpy(Id,S);
}


void Cercle::Save(ostream& Fichier) const
{

    int Taille=0;

    Fichier.write((char*)Id, sizeof(char));
    Taille = strlen(getId())+1;
    Fichier.write((char*)&Taille, sizeof(int));
    Fichier.write((char*)Id, Taille);
    Position.Save(Fichier);
    Fichier.write((char*)&Profondeur, sizeof(int));
    Fichier.write((char*)&Rayon, sizeof(int));
    Fichier.write((char*)&Rempli, sizeof(bool));

    Taille = strlen(couleur->getNom())+1;
    cout<<couleur->getNom()<<endl;
    Fichier.write((char*)&Taille, sizeof(int));
    Fichier.write((char*)couleur->getNom(), Taille);
}


void Cercle::Load(ifstream& Fichier)
{
    char Buffer[50];
    Point Pros;
    int tmp, Taille=0;
    bool rmp;

    Fichier.read((char*)&Taille, sizeof(int));
    Fichier.read((char*)Buffer, Taille);
    setId(Buffer);
    Pros.Load(Fichier);
    setPosition(Pros);
    Fichier.read((char *) &tmp, sizeof(int));
    setProfondeur(tmp);
    Fichier.read((char *) &tmp, sizeof(int));
    setRayon(tmp);
    Fichier.read((char *) &rmp, sizeof(bool));
    setRempli(rmp);



    setInfos();

}

void Cercle::dessine()
{

    if(!isRempli())
        WindowSDL::drawCircle(getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getPosition().getX(),
                      getPosition().getY(),getRayon());
    else
        WindowSDL::drawDisc(getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getPosition().getX(),
                            getPosition().getY(),getRayon());

}