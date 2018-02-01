using namespace std;
#include "Couleur.h"



int Couleur::CptCouleur = 0;

const Couleur Couleur::ROUGE(255,0,0,"Rouge");
const Couleur Couleur::BLEU(0,0,255,"Bleu");
const Couleur Couleur::VERT(0,255,0,"Vert");


//Fonctions des constructeurs et du destructeur //
Couleur::Couleur()
{
	Rouge=0;
	Bleu=0;
	Vert=0;
	Nom=NULL;
	setNom("Noir");
	CptCouleur++;
	
}

Couleur::Couleur(int R, int V, int B, const char *S)
{
	bool ValR=true, ValB=true, ValV=true;

	if(R<0||R>255)
		ValR=false;
	if(B<0||B>255)
		ValB=false;
	if(V<0||V>255)
		ValV=false;

	if(!ValR || !ValB || !ValV)
		throw InvalidColorException((char *) "Couleur invalide", ValR,ValV,ValB);

	setRouge(R);
	setBleu(B);
	setVert(V);
	Nom=NULL;
	setNom(S);
	CptCouleur++;

}

Couleur::Couleur(int R, int V, int B)
{
	bool ValR=true, ValB=true, ValV=true;
	if(R<0||R>255)
		ValR=false;
	if(B<0||B>255)
		ValB=false;
	if(V<0||V>255)
		ValV=false;

	if(!ValR || !ValB || !ValV)
		throw InvalidColorException((char *) "Couleur invalide", ValR,ValV,ValB);

	setRouge(R);
	setBleu(B);
	setVert(V);
	Nom=NULL;
	setNom("Inconnu");
	CptCouleur++;

}

Couleur::Couleur(const Couleur& A)
{
	bool ValR=true, ValB=true, ValV=true;

	if(A.getRouge()<0||A.getRouge()>255)
		ValR=false;
	if(A.getBleu()<0||A.getBleu()>255)
		ValB=false;
	if(A.getVert()<0||A.getVert()>255)
		ValV=false;

	if(!ValR || !ValB || !ValV)
		throw InvalidColorException((char *) "Couleur invalide", ValR,ValB,ValV);

	Rouge=A.getRouge();
	Bleu=A.getBleu();
	Vert=A.getVert();
	Nom=NULL;
	setNom(A.getNom());
	CptCouleur++;
}

Couleur::~Couleur ()
{
	if(Nom!=NULL)
	{
		delete Nom;
	}
	Nom=NULL;
	CptCouleur--;

}

//Fonction set de la classe couleur//
void Couleur::setNom (const char *S)
{
	if(Nom!=NULL) 
		delete Nom;

	if(S!=NULL)
	{
		Nom= new char[strlen(S)+1]; 
		strcpy(Nom,S);
	}
	else
		Nom=NULL;
}

void Couleur::setRouge(int R)
{
	if(R<0||R>255)
		throw InvalidColorException((char *) "Couleur invalide", false,true,true);
	Rouge=R;

}

void Couleur::setBleu(int B)
{
	if(B<0||B>255)
		throw InvalidColorException((char *) "Couleur invalide", true,true,false);
	Bleu=B;

}

void Couleur::setVert(int V)
{
	if(V<0||V>255)
		throw InvalidColorException((char *) "Couleur invalide", true,false,true);
	Vert=V;

}

//Fonctions get de la classe couleur//
const char* Couleur::getNom () const
{
	return this->Nom;
}

int Couleur::getRouge () const
{
	return this->Rouge;
}

int Couleur::getBleu () const
{
	return this->Bleu;
}

int Couleur::getVert () const
{
	return this->Vert;
}

int Couleur::getCompteur ()
{
	return CptCouleur;
}


int Couleur::getLuminance() const
{

	return ((Rouge+Bleu+Vert)/3);
}

//Fonction d'affichage de la fonction couleur//
void Couleur::Affiche() const
{
	cout << "Rouge: " << Rouge << endl;
	cout << "Bleu: " << Bleu << endl;
	cout << "Vert: " << Vert << endl;
	if (Nom!=NULL)
		cout << "Nom : " << Nom<< endl;

}

//Fonctions des operators de la fonction couleur//

Couleur& Couleur::operator= (const Couleur& C)
{
	setNom(C.getNom());
	setRouge(C.getRouge());
	setBleu(C.getBleu());
	setVert(C.getVert());

	return *this;
}

Couleur Couleur::operator+ (const Couleur& C1) const
{
	Couleur C2;
	int R=getRouge()+C1.getRouge();
	int V=getVert()+C1.getVert();
	int B=getBleu()+C1.getBleu();
	char *Buffer=NULL;
	
	if(this->getNom()!=NULL && C1.getNom()!=NULL)
	{
		Buffer= new char[strlen(this->getNom())+strlen(C1.getNom())+strlen("Mélange de ")+strlen(" et de ")+1];
		sprintf(Buffer,"Mélange de %s et de %s",this->getNom(),C1.getNom());
	}
	else
	{
		Buffer= new char [strlen("Mélange inconnu")+1];
		strcpy(Buffer,"Mélange inconnu");
	}

	if(R>255)
		R=255;

	if(V>255)
		V=255;

	if(B>255)
		B=255;

	C2.setRouge(R);
	C2.setBleu(B);
	C2.setVert(V);
	C2.setNom(Buffer);

	delete Buffer;

	return C2;
}

Couleur Couleur::operator+ (const int E) const
{
	Couleur C1;

	char* Buffer;

	Buffer=NULL;

	C1.setRouge(getRouge()+E < 255 ? getRouge()+E:0);
	C1.setBleu(getBleu()+E < 255 ? getBleu()+E:0);
	C1.setVert(getVert()+E < 255 ? getVert()+E:0);

	if(getNom()!=NULL)
	{
		Buffer= new char[strlen(getNom())+12];
		sprintf(Buffer,"%s clair(%d)",getNom(),E);
	}

	C1.setNom(Buffer);

	if(Buffer!=NULL)
		delete Buffer;

	return C1;
}

Couleur operator+ (const int E,const Couleur& C1)
{
	Couleur C2;
	C2=C1+E;


	return C2;
}

Couleur Couleur::operator- (const int E) const
{
	Couleur C1;
	char* Buffer=NULL;

	C1.setRouge(getRouge()-E> 0 ? getRouge()-E:0);
	C1.setBleu(getBleu()-E> 0 ? getBleu()-E:0);
	C1.setVert(getVert()-E> 0 ? getVert()-E:0);
	
	if(getNom()!=NULL)
	{		
		Buffer= new char[strlen(getNom())+12];
		sprintf(Buffer,"%s fonce(%d)",getNom(),E);
	}
	
	C1.setNom(Buffer);

	delete Buffer;
	
	return C1;
}


int Couleur::operator< (const Couleur& C)
{
	return (getLuminance() < C.getLuminance());
}

int Couleur::operator> (const Couleur& C)
{
	return (getLuminance() > C.getLuminance());
}

int Couleur::operator== (const Couleur& C)
{
	return (getLuminance() == C.getLuminance());
}

ostream& operator<< (ostream& S, const Couleur& C)
{
	char *Buffer;
	if(C.Nom!=NULL)
	{
		Buffer= new char [strlen(C.Nom)+1];
		strcpy(Buffer,C.Nom);
	}
	else
	{
		Buffer= new char [strlen("Inconnu")+1];
		strcpy(Buffer,"Inconnu");
	}

	S << "Couleur("<<C.Rouge<<","<<C.Vert<<","<<C.Bleu<<","<<Buffer<<")";

	delete Buffer;
	return S;
}

istream& operator>> (istream& S, Couleur& C)
{

	int R,B,V;
	char Buffer[30]	;

	cout<<"Rouge: ";
	S >> R;
	C.setRouge(R);


	cout<<"Bleu: ";
	S >> B;
	C.setBleu(B);


	cout<<"Vert: ";
	S >> V;
	C.setVert (V);


	cout<<"Nom: ";
	S >> Buffer;
	C.setNom(Buffer);

	return S;
}

Couleur Couleur::operator++ ()
{

	setRouge(10 + getRouge()< 255 ? 10 + getRouge():255);
	setBleu(10 + getBleu()< 255 ? 10 +getBleu():255);
	setVert(10 + getVert()< 255 ? 10 +getVert():255);

	return *this;
}


Couleur Couleur::operator++ (int E)
{
	Couleur C1(*this);

	setRouge(10 + getRouge()< 255 ? 10 + getRouge():255);
	setBleu(10 + getBleu()< 255 ? 10 +getBleu():255);
	setVert(10 + getVert()< 255 ? 10 +getVert():255);

	return C1;
}

Couleur Couleur::operator-- ()
{

	setRouge(getRouge()-10> 0? 10 + getRouge()-10:0);
	setBleu(getBleu()-10> 0 ? 10 +getBleu()-10 :0);
	setVert(getVert()-10> 0 ? getVert()-10:0);

	return *this;
}


Couleur Couleur::operator-- (int E)
{
	Couleur C1(*this);

	setRouge(getRouge()-10> 0 ? getRouge()-10:0);
	setBleu(getBleu()-10> 0 ? getBleu()-10:0);
	setVert(getVert()-10> 0 ? getVert()-10:0);

	return C1;
}

//Fonctions Save et Load de la fonction couleur//

void Couleur::Save(ostream& Fichier) const
{
	int existe,Taille=0;

    Fichier.write((char*)&Rouge, sizeof(int));
    Fichier.write((char*)&Vert, sizeof(int));
    Fichier.write((char*)&Bleu, sizeof(int));
    Taille = strlen(getNom())+1;
    if (Taille == 0)
    {
        existe = 0;
        Fichier.write((char*)&existe, sizeof(int));
    }
    else
    {
        existe = 1;
        Fichier.write((char*)&existe, sizeof(int));
        Fichier.write((char*)&Taille, sizeof(int));
        Fichier.write((char*)Nom, Taille);
    }

}

void Couleur::Load(ifstream& Fichier)
{
    int tmp, Taille = 0;
    char Buffer[20];
    int existe;


    Fichier.read((char*)&tmp, sizeof(int));
    setRouge(tmp);

    Fichier.read((char*)&tmp, sizeof(int));
    setVert(tmp);

    Fichier.read((char*)&tmp, sizeof(int));
    setBleu(tmp);

    Fichier.read((char*)&existe, sizeof(int));

    if(existe!=0)
    {
        Fichier.read((char*)&Taille, sizeof(int));
        Fichier.read((char*)Buffer, Taille);
        setNom(Buffer);
    }
    else
    {
        setNom(NULL);
    }

}

