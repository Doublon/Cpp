#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Ligne.h"


//Fonctions des constructeurs et du destructeur //

Ligne::Ligne():Forme()
{
    Extremite.setX(0);
    Extremite.setY(0);
    setInfos();
}

Ligne::Ligne(const char* S, Point P):Forme(S,P)
{
    setId(S);
    Extremite.setX(0);
    Extremite.setY(0);
    setInfos();
}

Ligne::Ligne(const char* S, Point P, Point E, const Couleur* C, int prof):Forme(S,P,C,prof)
{
    setId(S);
    setExtremite(E);
    setInfos();
}

Ligne::Ligne(const Ligne& A):Forme (A)
{
    setId(A.getId());
    setExtremite(A.Extremite);
    Infos= new char[strlen(A.Infos)+1]; strcpy(Infos,A.Infos);
}

Ligne::~Ligne ()
{
    if(Id!=NULL)
    {
        delete Id;
    }
    if(Infos!=NULL)
    {
        delete Infos;
    }
    //cout<<"----------------------------"<<CptForme<<endl;
    CptForme--;

}

//Fonctions set de la classe Ligne //

void Ligne::setExtremite (Point E)
{
    Extremite.setX(E.getX());
    Extremite.setY(E.getY());

    setInfos();
}


void Ligne::setId (const char* S)
{
    char Check[80];
    int i=0;

    if(S==NULL)
        throw BaseException((char *)"L'id est NULL");

    strcpy(Check,S);

    if (Check[i] != 'L')
        throw BaseException((char *)"L'Id des lignes doit commencer par 'L'");

    i++;

    while (isdigit(Check[i]) && Check[i] != '\0')
        i++;

    if (Check[i] != '\0' || i < 2)
        throw BaseException((char *) "Il doit y avoir minimum 2 caractère et que des chiffres après le 'L'");

    Id= new char[strlen(S)+1];
    strcpy(Id,S);
}

void Ligne::setInfos()
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

    sprintf(Buffer2,"Ligne %s: Position(%d , %d), Extremite(%d, %d), Couleur( %d, %d, %d, %s) , Profondeur=%d",Id, Position.getX(), Position.getY(),Extremite.getX(), Extremite.getY(), R, V, B, Buffer1,Profondeur);
    Infos= new char[strlen(Buffer2)+1];
    strcpy(Infos,Buffer2);



    delete Buffer1;

}

//Fonctions get de la classe Ligne //

Point Ligne::getExtremite () const
{
    return this->Extremite;
}


const char* Ligne::getInfos () const
{
    if (Infos!=NULL)
        return this->Infos;
    else
        return "Aucune";
}

//Fonctions d'affichage de la classe Ligne //

void Ligne::Affiche () const
{
    Forme::Affiche();
    cout<<"Extremite: "<<Extremite<<endl;
}

//Fonctions operator de la classe Ligne //

ostream& operator<< (ostream& S, const Ligne& F)
{
    int R=0,B=0,V=0;
    char *Buffer=NULL;


    if(F.couleur!=NULL)
    {
        R=F.couleur->getRouge();
        B=F.couleur->getBleu();
        V=F.couleur->getVert();

        if(F.couleur->getNom()!=NULL)
        {
            Buffer = new char[strlen(F.couleur->getNom()) + 1];
            strcpy(Buffer, F.couleur->getNom());
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


    S << "LIGNE "<<F.Id <<": Position:"<<F.Position<<",Extremite:"<<F.Extremite<<", Couleur:(" << R<<","<<V<<","<< B <<"," <<Buffer<<"), Profondeur= "<<F.Profondeur <<endl;

    delete Buffer;

    return S;

}

//Fonctions Save et Load //

void Ligne::Save(ostream& Fichier) const
{
    int Taille=0;

    Fichier.write((char*)Id, sizeof(char));
    Taille = strlen(getId())+1;
    Fichier.write((char*)&Taille, sizeof(int));
    Fichier.write((char*)Id, Taille);
    Position.Save(Fichier);
    Extremite.Save(Fichier);
    Fichier.write((char*)&Profondeur, sizeof(int));

    Taille = strlen(couleur->getNom())+1;
    Fichier.write((char*)&Taille, sizeof(int));
    Fichier.write((char*)couleur->getNom(), Taille);

}


void Ligne::Load(ifstream& Fichier)
{
    char Buffer[50];
    Point Pros;
    int tmp, Taille=0;

    Fichier.read((char*)&Taille, sizeof(int));
    Fichier.read((char*)Buffer, Taille);
    cout<<Buffer<<endl;
    setId(Buffer);
    Pros.Load(Fichier);
    setPosition(Pros);
    Pros.Load(Fichier);
    setExtremite(Pros);
    Fichier.read((char*)&tmp, sizeof(int));
    setProfondeur(tmp);

    setInfos();
}

void Ligne::dessine()
{
    WindowSDL::drawLine(getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getPosition().getX(),
                      getPosition().getY(),getExtremite().getX(),getExtremite().getY());
}