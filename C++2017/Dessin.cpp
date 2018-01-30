using namespace std;
#include "Dessin.h"


//Constructeurs et destrcuteurs //

Dessin::Dessin()
{

	Largeur=0;
	Hauteur=0;
	Fond=Couleur(255,255,255,"Blanc");
	Palette.SetTeteNull();
	Formes.SetTeteNull();
    Fill=true;

}

Dessin::Dessin(int L, int H, const Couleur& F)
{
	setLargeur(L);
	setHauteur(H);
	setFond(F);
	Palette.SetTeteNull();
	Formes.SetTeteNull();
    Fill=true;

}

Dessin::~Dessin() {
    Iterateur<SmartPointer<Forme> > Rech(Formes);

    Rech.reset();
    while (!Rech.end())
    {
        ((Rech).remove()).Delete();

    }
}


//Fonction set de la classe dessin //

void Dessin::setLargeur (int L)
{
	if(L<950||L>1400)
		throw BaseException((char*) "La largeur du dessin doit être entre 950 et 1400");
	Largeur=L;
}
void Dessin::setHauteur(int H)
{
	if(H<400||H>650)
		throw BaseException((char*) "La largeur du dessin doit être entre 400 et 650");
	Hauteur=H;
}
void Dessin::setFond (const Couleur& C)
{
	Fond=C;
}

void Dessin::setFill(bool F)
{
    Fill=F;
}

//Fonction get de la classe dessin //

int Dessin::getLargeur() const
{
	return this->Largeur;
}

int Dessin::getHauteur() const
{
	return this->Hauteur;
}

bool Dessin::getFill() const
{
    return Fill;
}

Couleur Dessin::getFond() const
{
	return this->Fond;
}

Liste<Couleur> Dessin::getPalette() const
{
	return this->Palette;
}

ListeTriee<SmartPointer<Forme> > Dessin::getFormes()
{

    return this->Formes;

}
//Fonction d'affichage //

void Dessin::AffichePalette() const
{
	(this->Palette).Affiche();
}

void Dessin::AfficheFormes() const
{
	(this->Formes).Affiche();
}

void Dessin::AfficherParametre() const
{
	cout<<"Largeur: "<<Largeur<<endl;
	cout<<"Hauteur: "<<Hauteur<<endl;
	cout<<"Fond: "<<Fond<<endl;
}


// Gestion des couleurs //

void Dessin::AjouteCouleur (const Couleur& NewCouleur)
{
    Iterateur<Couleur> Rech(Palette);

    cout<<NewCouleur<<endl;

    for (Rech.reset() ; !Rech.end(); Rech++)
    {
        if(strcmp (((Couleur)Rech).getNom(),NewCouleur.getNom())==0)
        {
            throw BaseException((char*)"La couleur est déjà présente dans la palette");
        }

    }
    Palette.insere(NewCouleur);
}

Couleur* Dessin::RechercheCouleur(const char *NomCouleur)
{
    Iterateur<Couleur> Rech(Palette);

    for (Rech.reset() ; !Rech.end(); Rech++)
    {
        if(strcmp (((Couleur)Rech).getNom(),NomCouleur)==0)

            break;
    }
    if(!Rech.end())
    {
        return &(Rech.getPointeur())->Valeur;
    }
    else
    {
        throw BaseException((char*)"La couleur n'est pas présente dans la palette");
    }


}

void Dessin::ModifCouleur(const char *NomCouleur)
{
    Iterateur<Couleur> Rech(Palette);
    Couleur New;
    int i;
    Iterateur<SmartPointer<Forme> > Fo(Formes);
    for (Rech.reset(), i=0; !Rech.end(); Rech++,i++)
    {
        if(strcmp (((Couleur)Rech).getNom(),NomCouleur)==0)
            break;
    }

    if(!Rech.end()&& i>19)
    {
        cin>>New;
        *(&Rech) = New;


        for (Fo.reset() ; !Fo.end(); Fo++)
        {

            if(strcmp((((SmartPointer<Forme>)Fo).getVal()->getCouleur())->getNom(),New.getNom())== 0)
            {

                ((SmartPointer<Forme>)Fo)->setInfos();
            }

        }

    }
    else
        throw BaseException((char*)"La couleur n'est pas présente dans la palette ou est une couleur de base.");



}

void Dessin::DeleteCouleur(const char *NomCouleur)
{
    Iterateur<Couleur> Rech(Palette);
    Couleur Sup;
    int i;
    Iterateur<SmartPointer<Forme> > Fo(Formes);


    for (Rech.reset(), i=0; !Rech.end(); Rech++,i++)
    {
        if(strcmp (((Couleur)Rech).getNom(),NomCouleur)==0)
            break;
    }



    if(!Rech.end()&& i>19)
    {
        for (Fo.reset() ; !Fo.end(); Fo++)
        {

            if(strcmp((((SmartPointer<Forme>)Fo).getVal()->getCouleur())->getNom(),NomCouleur)== 0)
                throw BaseException((char*)"La couleur est utilisée par une/des forme(s)");

        }
        Sup = Rech.remove();
        cout << "Couleur supprimée = " << Sup << endl;
    }
    else
        throw BaseException((char*)"La couleur n'est pas présente dans la palette ou est une couleur de base");
}


//Gestion des formes //

void Dessin::AjouteForme (Forme* NewForme, const char *NomCouleur)
{

    int IdTest;
    char NewId[80];
    char Type[2];


    IdTest=VerifId(NewForme->getId());
    if(IdTest!=-1)
    {
        strncpy(Type,NewForme->getId(),1);
        Type[1]='\0';
        sprintf(NewId,"%s%.4d",Type,IdTest);
        NewForme->setId(NewId);
    }

    NewForme->setCouleur(RechercheCouleur(NomCouleur));
    Formes.insere(NewForme);
}


void Dessin::ModifForme(const char *IdForme, char *NomCouleur)
{
    Forme* Modif;

    cout<<"Clicker sur la forme que vous désirez modifier: "<<endl;
    Modif=RechercheProximite();
    Modif->setCouleur(RechercheCouleur(NomCouleur));

}


void Dessin::DeleteForme(const char *IdForme)
{

    int Petit, X, Y, Test, Pos=0, i;
    WindowSDLclick click1=WindowSDL::waitClick();
    Iterateur<SmartPointer<Forme> > Rech(Formes);


    Rech.reset();

    X=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getX();
    Y=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getY();

    Petit=CalculeProximite(click1.getX(),click1.getY(),X,Y);
    Rech++;

    for (i=1;!Rech.end();i++)
    {
        X=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getX();
        Y=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getY();
        Test=CalculeProximite(click1.getX(),click1.getY(),X,Y);

        if(Test<Petit)
        {
            Petit=Test;
            Pos=i;
        }

        Rech++;
    }

    Rech.reset();

    for (i=0;i<Pos;i++)
    {
        Rech++;
    }

    (Rech.remove()).Delete();
}



// Gestion Save et Load //

void Dessin::Save(const char* NomFichier)
{

    Iterateur<Couleur> CoulRech(Palette);
    Iterateur<SmartPointer<Forme> > FormeRech(Formes);

    ofstream Fichier(NomFichier,ios::out);
    int NbrEle;


    Fichier.write((char*)&Largeur, sizeof(int));
    Fichier.write((char*)&Hauteur, sizeof(int));
    Fond.Save(Fichier);

    NbrEle=getPalette().getNombreElements();
    Fichier.write((char*)&NbrEle, sizeof(int));

    for (CoulRech.reset() ; !CoulRech.end(); CoulRech++)
    {
        ((Couleur)CoulRech).Save(Fichier);
    }

    NbrEle=Formes.getNombreElements();
    Fichier.write((char*)&NbrEle, sizeof(int));

    for (FormeRech.reset() ; !FormeRech.end(); FormeRech++)
    {
        (((SmartPointer<Forme>)FormeRech).getVal())->Save(Fichier);
    }

}


void Dessin::Load(const char* NomFichier)
{
    ifstream Fichier(NomFichier,ios::out);
    if(Fichier==NULL)
        throw BaseException((char*)"Erreur d'ouverture de fichier");
    int NbrEle, Tmp, Taille;
    Couleur CoulCharg;
    Forme *FormeCharg;
    char Type, NomCouleur[80];

    Fichier.read((char*)&Tmp, sizeof(int));
    setLargeur(Tmp);
    Fichier.read((char*)&Tmp, sizeof(int));
    setHauteur(Tmp);
    Fond.Load(Fichier);

    Fichier.read((char*)&NbrEle, sizeof(int));
    while(NbrEle>0)
    {
        CoulCharg.Load(Fichier);
        AjouteCouleur(CoulCharg);
        NbrEle--;
    }
    Fichier.read((char*)&NbrEle, sizeof(int));
    while(NbrEle>0)
    {
        Fichier.read((char*)&Type, sizeof(char));
        switch(Type) {
            case 'L':
                FormeCharg=new Ligne;
                FormeCharg->Load(Fichier);
                break;
            case 'P':
                FormeCharg=new Pixel;
                FormeCharg->Load(Fichier);
                break;
            case 'R':
                FormeCharg=new Rectangle;
                FormeCharg->Load(Fichier);
                break;
            case 'C':
                FormeCharg=new Cercle;
                FormeCharg->Load(Fichier);
                break;
        }
        Fichier.read((char *) &Taille, sizeof(int));
        Fichier.read((char *) NomCouleur, Taille);
        AjouteForme(FormeCharg,NomCouleur);
        NbrEle--;

        FormeCharg=NULL;
    }

}

void Dessin::importCouleurs(const char *NomFichier)
{
    ifstream Fichier(NomFichier,ios::out);
    if(Fichier==NULL)
        throw BaseException((char*)"Erreur d'ouverture de fichier");
    int R,B,V;
    char *split;
    char Buffer[150];
    Couleur Coul;

    Fichier.getline(Buffer,150);


    while(Fichier.getline(Buffer,50))
    {
        try
        {
            split = strtok(Buffer, ";");
            if (split != NULL)
            {
                R = atoi(split);
                Coul.setRouge(R);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                V = atoi(split);
                Coul.setVert(V);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                B = atoi(split);
                Coul.setBleu(B);
            }

            split = strtok(NULL, "\n");
            if (split != NULL) {
                Coul.setNom(split);
            }

            AjouteCouleur(Coul);

        }
        catch(BaseException& E)
        {
                E.Afficher();
        }
    }


}

void Dessin::importPixels(const char *NomFichier)
{
    ifstream Fichier(NomFichier,ios::out);
    if(Fichier==NULL)
        throw BaseException((char*)"Erreur d'ouverture de fichier");
    int Tmp;
    char *split;
    char Buffer[150];
    char NomCouleur[80];
    char idForme[80];
    Pixel *P;
    Point point;


    Fichier>>Buffer;

     while(Fichier>>Buffer)
     {
         try
         {
            P= new Pixel;
            sprintf(idForme,"P%.4d",(P->getCompteur()));
            P->setId(idForme);

            split = strtok(Buffer, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setX(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setY(Tmp);
            }
            P->setPosition(point);

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                P->setProfondeur(Tmp);
            }

            split = strtok(NULL, "\n");
            if (split != NULL)
            {
                strcpy(NomCouleur,split);
            }

            AjouteForme(P,NomCouleur);
        }
         catch(BaseException& E)
         {
             delete P;
             E.Afficher();
         }
    }

}


void Dessin::importLignes(const char *NomFichier)
{
    ifstream Fichier(NomFichier,ios::out);
    if(Fichier==NULL)
        throw BaseException((char*)"Erreur d'ouverture de fichier");
    int Tmp;
    char *split;
    char Buffer[150];
    char NomCouleur[80];
    char idForme[80];
    Ligne *L;
    Point point;


    Fichier>>Buffer;

    while(Fichier>>Buffer)
    {
        try
        {
            L= new Ligne;
            sprintf(idForme,"L%.4d",(L->getCompteur()));
            L->setId(idForme);

            split = strtok(Buffer, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setX(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setY(Tmp);
            }
            L->setPosition(point);

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setX(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setY(Tmp);
            }
            L->setExtremite(point);

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                L->setProfondeur(Tmp);
            }

            split = strtok(NULL, "\n");
            if (split != NULL)
            {
                strcpy(NomCouleur,split);
            }

            AjouteForme(L,NomCouleur);

        }
        catch(BaseException& E)
        {
            delete L;
            E.Afficher();
        }
    }

}

void Dessin::importRectangles(const char *NomFichier)
{
    ifstream Fichier(NomFichier,ios::out);
    if(Fichier==NULL)
        throw BaseException((char*)"Erreur d'ouverture de fichier");
    int Tmp;
    char *split;
    char Buffer[150];
    char NomCouleur[80];
    char idForme[80];
    Rectangle *R;
    Point point;


    Fichier>>Buffer;

    while(Fichier>>Buffer)
    {
        try
        {
            R= new Rectangle;
            sprintf(idForme,"R%.4d",(R->getCompteur()));
            R->setId(idForme);

            split = strtok(Buffer, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setX(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setY(Tmp);
            }
            R->setPosition(point);

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                R->setDimX(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                R->setDimY(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                R->setRempli(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                R->setProfondeur(Tmp);
            }

            split = strtok(NULL, "\n");
            if (split != NULL)
            {
                strcpy(NomCouleur,split);
            }

            AjouteForme(R,NomCouleur);

        }
        catch(BaseException& E)
        {
            delete R;
            E.Afficher();
        }
    }

}

void Dessin::importCercles(const char *NomFichier)
{
    ifstream Fichier(NomFichier,ios::out);
    if(Fichier==NULL)
        throw BaseException((char*)"Erreur d'ouverture de fichier");
    int Tmp;
    char *split;
    char Buffer[150];
    char NomCouleur[80];
    char idForme[80];
    Cercle *C;
    Point point;


    Fichier>>Buffer;

    while(Fichier>>Buffer)
    {
        try
        {
            C= new Cercle;
            sprintf(idForme,"C%.4d",(C->getCompteur()));
            C->setId(idForme);

            split = strtok(Buffer, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setX(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                point.setY(Tmp);
            }
            C->setPosition(point);

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                C->setRayon(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                C->setRempli(Tmp);
            }

            split = strtok(NULL, ";");
            if (split != NULL)
            {
                Tmp = atoi(split);
                C->setProfondeur(Tmp);
            }

            split = strtok(NULL, "\n");
            if (split != NULL)
            {
                strcpy(NomCouleur,split);
            }

            AjouteForme(C,NomCouleur);

        }
        catch(BaseException& E)
        {
            delete C;
            E.Afficher();
        }
    }

}

void Dessin::dessine()
{
    Iterateur<SmartPointer<Forme> > Tmp(Formes);
    WindowSDL::setBackground(getFond().getRouge(),getFond().getVert(),getFond().getBleu());

    for (Tmp.reset() ; !Tmp.end(); Tmp++)
    {
        (((SmartPointer<Forme>)Tmp).getVal())->dessine();
    }
    WindowSDL::setMenu(getFill());


}

Forme* Dessin::RechercheProximite ()
{
    int Petit, X, Y, Test, clickX,clickY;
    Iterateur<SmartPointer<Forme> > Rech(Formes);
    Forme* Trouve ;
    WindowSDLclick click1=WindowSDL::waitClick();
    clickX=click1.getX();
    clickY=click1.getY();


    Rech.reset();

    X=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getX();
    Y=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getY();

    Petit=CalculeProximite(clickX,clickY,X,Y);
    Trouve=((SmartPointer<Forme>)Rech).getVal();
    Rech++;

    while (!Rech.end())
    {
        X=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getX();
        Y=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getY();
        Test=CalculeProximite(clickX,clickY,X,Y);

        if(Test<Petit)
        {
            Petit=Test;
            Trouve=((SmartPointer<Forme>)Rech).getVal();
        }

        Rech++;
    }

    return Trouve;


}

int CalculeProximite(int X1,int Y1,int X2,int Y2)
{
    int Reponse=0;

    X1=X1-X2;
    Y1=Y1-Y2;

    Reponse=abs(X1)+abs(Y1);

    return Reponse;
}

Forme* Dessin::RechercheFormeAff (int X1, int Y1)
{
    int Petit, X, Y, Test;
    Iterateur<SmartPointer<Forme> > Rech(Formes);
    Forme* Trouve ;

    Rech.reset();

    X=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getX();
    Y=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getY();

    Petit=CalculeProximite(X1,Y1,X,Y);
    Trouve=((SmartPointer<Forme>)Rech).getVal();
    Rech++;

    while (!Rech.end())
    {
        X=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getX();
        Y=((((SmartPointer<Forme>)Rech).getVal())->getPosition()).getY();
        Test=CalculeProximite(X1,Y1,X,Y);

        if(Test<Petit)
        {
            Petit=Test;
            Trouve=((SmartPointer<Forme>)Rech).getVal();
        }

        Rech++;
    }

    return Trouve;


}

int Dessin::VerifId (const char *S)
{
    Iterateur<SmartPointer<Forme> > Fo(Formes);


    for ( Fo.reset() ; !Fo.end(); Fo++)
    {

        if(strcmp((((SmartPointer<Forme>)Fo).getVal()->getId()),S)== 0)
        {
            break;
            //((SmartPointer<Forme>)Fo)->setInfos();
        }

    }

    if(!Fo.end())
    {
        int NewId=1;
        char LigneId[20], PixelId[20], CercleId[20], RectangleId[20];

        sprintf(LigneId,"L%.4d",NewId);
        for ( Fo.reset() ; !Fo.end(); Fo++)
        {
            sprintf(LigneId,"L%.4d",NewId);
            sprintf(PixelId,"P%.4d",NewId);
            sprintf(CercleId,"C%.4d",NewId);
            sprintf(RectangleId,"R%.4d",NewId);

            if(strcmp((((SmartPointer<Forme>)Fo).getVal()->getId()),LigneId)!= 0
                && strcmp((((SmartPointer<Forme>)Fo).getVal()->getId()),PixelId)!= 0
                && strcmp((((SmartPointer<Forme>)Fo).getVal()->getId()),CercleId)!= 0
                && strcmp((((SmartPointer<Forme>)Fo).getVal()->getId()),RectangleId)!= 0)
            {
                return NewId;
            }
        }

    }

    return -1;

}