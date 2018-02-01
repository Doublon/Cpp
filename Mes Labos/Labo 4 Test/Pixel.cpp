#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Pixel.h"

Pixel::Pixel():Forme()
{
	setInfos();
}


Pixel::Pixel(const char* S, Point P):Forme(S,P)
{
	setId(S);
	setInfos();
}

Pixel::Pixel(const char* S, Point P,const Couleur* C, int prof):Forme(S,P,C,prof)
{
	setId(S);
	setInfos();
}

Pixel::Pixel(const Pixel& A):Forme (A)
{
	setId(A.getId());
	Infos= new char[strlen(A.Infos)+1]; strcpy(Infos,A.Infos);
}

void Pixel::setInfos()
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

	sprintf(Buffer2,"PIXEL %s: Position(%d , %d), Couleur( %d, %d, %d, %s) , Profondeur=%d", Id, Position.getX(), Position.getY(), R, V, B, Buffer1,Profondeur);


	Infos= new char[strlen(Buffer2)+1];
	strcpy(Infos,(char*)Buffer2);

	delete Buffer1;

}

const char* Pixel::getInfos () const
{
	if (Infos!=NULL)
		return this->Infos;
	else
	return "Aucune";
}

Pixel::~Pixel ()
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

ostream& operator<< (ostream& S, const Pixel& P)
{
	int R=0,B=0,V=0;
	char *Buffer=NULL;



	if(P.couleur!=NULL)
	{
		R=P.couleur->getRouge();
		B=P.couleur->getBleu();
		V=P.couleur->getVert();

		if(P.couleur->getNom()!=NULL)
		{
			Buffer = new char[strlen(P.couleur->getNom()) + 1];
			strcpy(Buffer, P.couleur->getNom());
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


	S << "PIXEL "<<P.Id <<": Position:"<<P.Position<<","<<"), Couleur:(" << R<<","<<V<<","<< B <<"," <<Buffer<<"), Profondeur= "<<P.Profondeur<<endl;

	delete Buffer;

	return S;

}

void Pixel::setId (const char* S)
{
	char Check[80];
	int i=0;

	if(S==NULL)
		throw BaseException((char *)"L'id est NULL");

	strcpy(Check,S);

	if (Check[i] != 'P')
		throw BaseException((char *)"L'Id des pixels doit commencer par 'P'");

	i++;

	while (isdigit(Check[i]) && Check[i] != '\0')
		i++;

	if (Check[i] != '\0' || i < 2)
		throw BaseException((char *) "Il doit y avoir minimum 2 caractère et que des chiffres après le 'P'");

	Id= new char[strlen(S)+1];
	strcpy(Id,S);
}


void Pixel::Save(ostream& Fichier) const
{

	int Taille=0;

	Fichier.write((char*)Id, sizeof(char));
	Taille = strlen(getId())+1;
	Fichier.write((char*)&Taille, sizeof(int));
	Fichier.write((char*)Id, Taille);
	Position.Save(Fichier);
	Fichier.write((char*)&Profondeur, sizeof(int));
	Taille = strlen(couleur->getNom())+1;
	Fichier.write((char*)&Taille, sizeof(int));
	Fichier.write((char*)couleur->getNom(), Taille);
}


void Pixel::Load(ifstream& Fichier)
{
	char Buffer[50];
	Point Pros;
	int tmp, Taille = 0;

	Fichier.read((char *) &Taille, sizeof(int));
	Fichier.read((char *) Buffer, Taille);
	setId(Buffer);
	Pros.Load(Fichier);
	setPosition(Pros);
	Fichier.read((char *) &tmp, sizeof(int));
	setProfondeur(tmp);


	setInfos();
}

void Pixel::dessine()
{

	WindowSDL::setPixel(getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getPosition().getX(),
					  getPosition().getY());
}