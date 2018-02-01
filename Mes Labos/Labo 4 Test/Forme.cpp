using namespace std;
#include "Forme.h"

int Forme::CptForme = 0;


//Fonctions des constructeurs et du destructeur //
Forme::Forme()
{
	Id= NULL;
	Position.setX(0);
	Position.setY(0);
	couleur=NULL;
	Profondeur=0;
	Infos=NULL;
	CptForme++;
}

Forme::Forme(const char* S, Point P)
{	
	Id=NULL;
	setId(S);
	couleur=NULL;
	setPosition(P);
	Profondeur=0;
	Infos=NULL;
	CptForme++;
	
}

Forme::Forme(const char* S, Point P,const Couleur* C, int prof)
{	
	Id=NULL;
	setId(S);
	setPosition(P);
	setCouleur(C);
	setProfondeur(prof);
	Infos=NULL;

	CptForme++;
}

Forme::Forme(const Forme& A)
{
	Id=NULL;
	setId(A.getId());
	setCouleur(A.getCouleur());
	setPosition(A.getPosition());
	setProfondeur(A.getProfondeur());
	Infos=NULL;
	CptForme++;
}

Forme::~Forme ()
{
	if(Id!=NULL)
	{
		delete Id;
	}

}

//Fonctions set de la classe forme//
void Forme::setId (const char* S)
{
	if(S!=NULL)
	{
		Id= new char[strlen(S)+1]; 
		strcpy(Id,S);
	}
	else
	{
		Id=NULL;
	}
	setInfos();
}

void Forme::setPosition (Point P)
{
	Position.setX(P.getX());
	Position.setY(P.getY());

	setInfos();
}

void Forme::setProfondeur (int P)
{
	Profondeur= P;
	setInfos();

}

void Forme::setCouleur (const Couleur *C)
{
	this->couleur= C;
	setInfos();

}

//Fonctions get de la classe forme//

const char* Forme::getId () const
{
	return this->Id;
}

const Couleur* Forme::getCouleur () const
{
	return this->couleur;
}

Point Forme::getPosition () const
{
	return this->Position;
}

int Forme::getProfondeur () const
{
	return this->Profondeur;
}

int Forme::getCompteur()
{
	return CptForme;
}

//Fonctions d'affichage de la classe forme//

void Forme::Affiche() const
{
	if(Id!=NULL) 
		cout << "Id: " << Id << endl;
	cout<<"Position: "<<Position<<endl;
	if(couleur!=NULL)
	{
		couleur->Affiche();
	}
	else 
	{ 
		cout << "Aucune couleur"<< endl; 
	}
	cout << "Profondeur : " << Profondeur<< endl;
}

//Fonctions operator de la classe forme//

ostream& operator<< (ostream& S, const Forme& F)
{

	S<<F.getInfos();

	return S;

}

Forme& Forme::operator= (Forme& A)
{
	Id=NULL;
	setId(A.getId());
	setCouleur(A.getCouleur());
	setPosition(A.getPosition());
	setProfondeur(A.getProfondeur());
	if(getInfos()!=NULL)
			setInfos();
	CptForme++;

	return *this;
}

int Forme::operator< (const Forme& C)
{
	return (getProfondeur() < C.getProfondeur());
}

int Forme::operator> (const Forme& C)
{
	return (getProfondeur() > C.getProfondeur());
}

int Forme::operator== (const Forme& C)
{
	return (getProfondeur() == C.getProfondeur());
}