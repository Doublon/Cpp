using namespace std;
#include "Paint.h"
#include <math.h>

int main(void)
{
    char NomFichier[80];
    Dessin *SuperDessin;
    SuperDessin=NULL;


    int Choix;
    while(1) {
        fflush(stdin);
        Choix=0;
        Choix=Menu();

        switch (Choix)
        {
            case 0:
                if (SuperDessin != NULL) {
                    delete SuperDessin;
                    SuperDessin = NULL;
                    WindowSDL::close();
                }
                exit(0);

            case 1:
                if (SuperDessin == NULL) {
                    try {
                        SuperDessin = new Dessin;
                        AjouterDessin(SuperDessin);
                        WindowSDL::open(SuperDessin->getLargeur(), SuperDessin->getHauteur());
                        WindowSDL::setBackground((SuperDessin->getFond()).getRouge(),
                                              (SuperDessin->getFond()).getVert(),
                                              (SuperDessin->getFond()).getBleu());
                        WindowSDL::setMenu(SuperDessin->getFill());
                    }
                    catch (BaseException &E) {
                        delete SuperDessin;
                        SuperDessin = NULL;
                        E.Afficher();
                    }

                    if(SuperDessin!=NULL)
                        try{
                            PaletteBase(SuperDessin);
                        }
                        catch (BaseException &E) {
                            E.Afficher();
                        }


                } else
                    cout << "Un dessin est déjà ouvert" << endl;


                break;

            case 2:
                if (SuperDessin == NULL) {
                    try {
                        SuperDessin = new Dessin;
                        fflush(stdin);
                        cout << "Entrez le nom du fichier: ";
                        cin.getline(NomFichier, 80);
                        SuperDessin->Load(NomFichier);
                        WindowSDL::open(SuperDessin->getLargeur(), SuperDessin->getHauteur());
                        WindowSDL::setBackground((SuperDessin->getFond()).getRouge(),
                                              (SuperDessin->getFond()).getVert(),
                                              (SuperDessin->getFond()).getBleu());
                        SuperDessin->dessine();

                    }
                    catch (BaseException &E) {
                        delete SuperDessin;
                        SuperDessin = NULL;
                        E.Afficher();
                    }

                    if(SuperDessin!=NULL)
                        try{
                            PaletteBase(SuperDessin);
                        }
                        catch (BaseException &E) {
                            E.Afficher();
                        }

                } else
                    cout << "Un dessin est déjà ouvert" << endl;
                break;

        }


        while (SuperDessin!=NULL)
        {
            Choix = 0;

           // AffichagePosition();

            fflush(stdin);
            WindowSDLclick click1=WindowSDL::waitClick();
            Choix = MenuClick(click1.getX(),click1.getY());

            cout<<endl<<endl<<"###################################"<<endl;

            switch (Choix) {

                case 3:
                    if (SuperDessin != NULL) {
                        fflush(stdin);
                        cout << "Entrez le nom du fichier: ";
                        cin.getline(NomFichier, 80);
                        SuperDessin->Save(NomFichier);
                    } else
                        cout << "Aucun dessin ouvert" << endl;

                    break;

                case 4:
                    if (SuperDessin != NULL) {
                        delete SuperDessin;
                        SuperDessin = NULL;
                        WindowSDL::close();
                    } else
                        cout << "Aucun dessin ouvert" << endl;

                    break;

                case 5:
                    if (SuperDessin != NULL)
                        SuperDessin->AfficherParametre();
                    else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 6:
                    if (SuperDessin != NULL) {
                        Specifierfond(SuperDessin);
                        SuperDessin->dessine();
                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 7: {

                      cout<<"Nombre de couleurs en mémoire: "<<(Couleur::getCompteur())<<endl;
                      cout<<"Nombre de formes en mémoire: "<<(Forme::getCompteur())<<endl;


                }
                    break;

                case 8:
                    if (SuperDessin != NULL){
                        AjouterCouleurPalette(SuperDessin);}
                    else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 9:
                    if (SuperDessin != NULL) {
                        try {
                            ModifierCouleurPalette(SuperDessin);
                            SuperDessin->dessine();
                        }
                        catch (BaseException &E) {
                            E.Afficher();
                        }

                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 10:
                    if (SuperDessin != NULL) {
                        SupprimerCouleurPalette(SuperDessin);
                        SuperDessin->dessine();
                        cout<<"Couleur supprimée"<<endl;
                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 11:
                    if (SuperDessin != NULL) {
                        CreationPalette(SuperDessin);
                        SuperDessin->AffichePalette();
                        WindowSDL::waitClick();
                        WindowSDL::setBackground((SuperDessin->getFond()).getRouge(),
                                              (SuperDessin->getFond()).getVert(),
                                              (SuperDessin->getFond()).getBleu());
                        SuperDessin->dessine();
                    }
                    else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 12:
                    if (SuperDessin != NULL) {
                        try {
                            fflush(stdin);
                            cout << "Entrez le nom du fichier: ";
                            cin.getline(NomFichier, 80);
                            SuperDessin->importCouleurs(NomFichier);
                            SuperDessin->dessine();
                        }
                        catch (BaseException &E) {
                            E.Afficher();
                        }
                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 13:
                    if (SuperDessin != NULL) {
                        AjouterFormeDessin(SuperDessin,1);
                        SuperDessin->dessine();
                    }
                    break;

                case 14:
                    if (SuperDessin != NULL) {
                        if (Forme::getCompteur() > 0) {
                            SupprimerFormeDessin(SuperDessin);
                            SuperDessin->dessine();
                        } else
                            cout << "Aucune forme dans le dessin en cours!" << endl;
                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 15:
                    if (SuperDessin != NULL) {
                        if (Forme::getCompteur() > 0) {
                            ModifierFormeDessin(SuperDessin);

                            SuperDessin->dessine();
                        } else
                            cout << "Aucune forme dans le dessin en cours!" << endl;
                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 16:
                    if (SuperDessin != NULL) {
                        if (Forme::getCompteur() > 0) {
                            cout << *(SuperDessin->RechercheFormeAff (click1.getX(),click1.getY())) << endl;
                        } else
                            cout << "Aucune forme dans le dessin en cours!" << endl;
                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 17:
                    if (SuperDessin != NULL)
                        SuperDessin->AfficheFormes();
                    else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 18:
                    if (SuperDessin != NULL) {
                        ImporterFormeCSV(SuperDessin);
                        SuperDessin->dessine();
                    } else
                        cout << "Aucun dessin en cours!" << endl;
                    break;

                case 19:
                    if (SuperDessin != NULL) {
                        AjouterFormeDessin(SuperDessin,2);
                        SuperDessin->dessine();
                    }
                    break;

                case 20:
                    if (SuperDessin != NULL) {
                        AjouterFormeDessin(SuperDessin,3);
                        SuperDessin->dessine();
                    }
                    break;

                case 21:
                    if (SuperDessin != NULL) {
                        AjouterFormeDessin(SuperDessin,4);
                        SuperDessin->dessine();
                    }
                    break;

                default:
                    cout << "Vous n'avez pas sélectionné un élément du menu." << endl;

                case 22:
                    if (SuperDessin != NULL) {
                        if(SuperDessin->getFill()==true)
                            SuperDessin->setFill(false);
                        else
                            SuperDessin->setFill(true);

                        WindowSDL::setMenu(SuperDessin->getFill());
                    }
                    break;

            }

        }
    }
}

int Menu()
{

    cout << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "--- Inpres Paint ----------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << " 0. Quitter" << endl;
    cout << " 1. Nouveau Dessin" << endl;
    cout << " 2. Ouvrir Dessin" << endl<<endl;

    int Choix;
    cout << "  Choix : ";
    fflush(stdin);
    cin >> Choix;
    cin.ignore();

    return Choix;
}


void AjouterDessin(Dessin *NewDessin)
{

    int H, L;
    Couleur C;
    cout<<"Entrez la largeur du dessin: " ; cin>> L;
    NewDessin->setLargeur(L);
    cout<<"Entrez la hauteur du dessin: " ; cin>> H;
    NewDessin->setHauteur(H);
    NewDessin->setFond(C);


}

void Specifierfond(Dessin *SuperDessin)
{
    try
    {
        char NomCouleur[80];

        cout<<"Sélectionnez la nouvelle couleur de fond"<<endl;
        CreationPalette(SuperDessin);
        SuperDessin->setFond(*(SuperDessin->RechercheCouleur(SelectCouleur(NomCouleur,SuperDessin))));
    }
    catch(BaseException& E)
    {
        E.Afficher();
    }

}

//Gestion de la palette des couleurs

void AjouterCouleurPalette(Dessin* SuperDessin)
{
    try
    {
        Couleur C;
        cin>>C;
        SuperDessin->AjouteCouleur(C);
    }
    catch(BaseException& E)
    {
        E.Afficher();
    }

}
void ModifierCouleurPalette(Dessin* SuperDessin)
{
    try
    {
        char NomCouleur[80];
        cout<<"Entrez la couleur que vous voulez modifier: ";
        //cout<<""<<endl;
        fflush(stdin);
        CreationPalette(SuperDessin);
        SuperDessin->ModifCouleur(SelectCouleur(NomCouleur,SuperDessin));
    }
    catch(BaseException& E)
    {
        E.Afficher();
    }
}
void SupprimerCouleurPalette(Dessin* SuperDessin)
{
    try
    {
        char NomCouleur[80];
        cout<<"Entrez la couleur que vous voulez supprimer: ";
        fflush(stdin);
        //cin.getline(NomCouleur,80);
        CreationPalette(SuperDessin);
        SuperDessin->DeleteCouleur(SelectCouleur(NomCouleur,SuperDessin));
    }
    catch(BaseException& E)
    {
        E.Afficher();
    }
}

//Gestion de la liste des Formes

void AjouterFormeDessin (Dessin* SuperDessin, int ChoixForme)
{
    char NomCouleur[80];
    Forme *New;

    switch (ChoixForme)
    {
        case 1:
            try
            {
                New=new Ligne;
                AjouterLigneDessin((Ligne*)New);
                cout<<"Selectionner la couleur  de la ligne"<<endl;
                fflush(stdin);
                CreationPalette(SuperDessin);
                SuperDessin->AjouteForme(New,SelectCouleur(NomCouleur,SuperDessin));
            }
            catch(BaseException& E)
            {
                delete New;
                E.Afficher();
            }

            break;
        case 2:
            try
            {

                New=new Pixel;
                AjouterPixelDessin((Pixel*)New);
                cout<<"Selectionner la couleur  du pixel"<<endl;
                CreationPalette(SuperDessin);
                SuperDessin->AjouteForme(New,SelectCouleur(NomCouleur,SuperDessin));
            }
            catch(BaseException& E)
            {
                delete New;
                E.Afficher();
            }
            break;
        case 3:
            try
            {

                New=new Rectangle;
                AjouterRectangleDessin((Rectangle*)New,SuperDessin->getFill());
                cout<<"Selectionner la couleur  du Rectangle"<<endl;
                CreationPalette(SuperDessin);
                SuperDessin->AjouteForme(New,SelectCouleur(NomCouleur,SuperDessin));
            }
            catch(BaseException& E)
            {
                delete New;
                E.Afficher();
            }
            break;

        case 4:
            try
            {

                New=new Cercle;
                AjouterCercleDessin((Cercle*)New,SuperDessin->getFill());
                cout<<"Selectionner la couleur  du cercle"<<endl;
                CreationPalette(SuperDessin);
                SuperDessin->AjouteForme(New,SelectCouleur(NomCouleur,SuperDessin));
            }
            catch(BaseException& E)
            {
                delete New;
                E.Afficher();
            }
            break;
        default:
            cout << "Aucun type de formes selectionné" << endl;
    }


}

void AjouterLigneDessin(Ligne *L)
{
    char idForme[80];
    int Prof;

    sprintf(idForme,"L%.4d",(L->getCompteur()));
    L->setId(idForme);
    cout<<"Cliquez sur la fenêtre graphique pour entrer l'extrémité de ligne: "<<endl;
    WindowSDLclick click1 = WindowSDL::waitClick();
    Point Pos(click1.getX(),click1.getY());
    L->setPosition(Pos);
    cout<<"Cliquez sur la fenêtre graphique pour entrer l'autre extrémité de ligne: "<<endl;
    WindowSDLclick click2 = WindowSDL::waitClick();
    Point Ext(click2.getX(),click2.getY());
    L->setExtremite(Ext);
    fflush(stdin);
    Prof=ChoixProfondeur();
    L->setProfondeur(Prof);



}

void AjouterCercleDessin(Cercle *C, bool Fill)
{
    char idForme[80];
    //char Choix;
    int Prof;
    int y, x, R;

    sprintf(idForme,"C%.4d",(C->getCompteur()));
    C->setId(idForme);
    cout<<"Cliquez sur la fenêtre graphique pour positionner le centre du cercle: "<<endl;
    WindowSDLclick click1 = WindowSDL::waitClick();
    Point Pos(click1.getX(),click1.getY());
    C->setPosition(Pos);

    cout<<"Cliquez sur la fenêtre graphique l'extrémité : "<<endl;
    WindowSDLclick click2 = WindowSDL::waitClick();
    x=(click1.getX()*2)-click2.getX();
    y=(click1.getY()*2)-click2.getY();
    R=(x-click2.getX())*(x-click2.getX())+(y-click2.getY())*(y-click2.getY());
    R=((double) sqrt((double)R))/2;
    C->setRayon(R);
    Prof=ChoixProfondeur();
    C->setProfondeur(Prof);
    C->setRempli(Fill);

}
void AjouterPixelDessin(Pixel *P)
{
    char idForme[80];
    int Prof;

    sprintf(idForme,"P%.4d",(P->getCompteur()));
    P->setId(idForme);
    cout<<"Cliquez sur la fenêtre graphique pour entrez la position: "<<endl;
    WindowSDLclick click1 = WindowSDL::waitClick();
    Point Pos(click1.getX(),click1.getY());
    P->setPosition(Pos);
    Prof=ChoixProfondeur();
    P->setProfondeur(Prof);

}


void AjouterRectangleDessin(Rectangle *R, bool Fill)
{
    char idForme[80];
    //char Choix;
    int Prof;

    sprintf(idForme,"R%.4d",(R->getCompteur()));
    R->setId(idForme);
    cout<<"Cliquez sur la fenêtre graphique pour le coin du dessus gauche du rectangle: "<<endl;
    WindowSDLclick click1 = WindowSDL::waitClick();
    Point Pos(click1.getX(),click1.getY());
    R->setPosition(Pos);

    cout<<"Cliquez sur la fenêtre graphique pour le coin du bas droit du rectangle: "<<endl;
    WindowSDLclick click2 = WindowSDL::waitClick();
    R->setDimX(click2.getX()-click1.getX());
    R->setDimY(click2.getY()-click1.getY());
    Prof=ChoixProfondeur();
    R->setProfondeur(Prof);
    /*cout<<"Est-ce que le rectangle est rempli? (O/N):  ";
    fflush(stdin);
    cin>>Choix;
    if(Choix=='O'||Choix=='o')
    R->setRempli(true);*/
    R->setRempli(Fill);

}

void ModifierFormeDessin(Dessin* SuperDessin)
{
    try
    {
        cout<<"Choisissez une nouvelle couleur"<<endl;
        char IdForme[80];
        char NomCouleur[80];
        fflush(stdin);
        CreationPalette(SuperDessin);
        SuperDessin->ModifForme(IdForme,SelectCouleur(NomCouleur,SuperDessin));
    }
    catch(BaseException& E)
    {
        E.Afficher();
    }
}
void SupprimerFormeDessin(Dessin* SuperDessin)
{
    try
    {
        char IdForme[80];
        cout<<"Clicker sur la forme que vous désirez supprimer: "<<endl;
        fflush(stdin);
        SuperDessin->DeleteForme(IdForme);
    }
    catch(BaseException& E)
    {
        E.Afficher();
    }
}

void ImporterFormeCSV (Dessin* SuperDessin)
{
    int ChoixForme;
    char NomFichier[80];

    cout<<"Quelles formes désirez-vous rajouter? "<<endl;
    ChoixForme=SelectClickFormes();

    try
    {

        switch (ChoixForme) {
            case 1:
                cout << "Entrez le nom du fichier :";
                fflush(stdin);
                cin.getline(NomFichier, 80);
                SuperDessin->importLignes(NomFichier);
                break;
            case 2:
                cout << "Entrez le nom du fichier :";
                fflush(stdin);
                cin.getline(NomFichier, 80);
                SuperDessin->importPixels(NomFichier);
                break;
            case 3:
                cout << "Entrez le nom du fichier :";
                fflush(stdin);
                cin.getline(NomFichier, 80);
                SuperDessin->importRectangles(NomFichier);
                break;
            case 4:
                cout << "Entrez le nom du fichier :";
                fflush(stdin);
                cin.getline(NomFichier, 80);
                SuperDessin->importCercles(NomFichier);
                break;
            default:
                cout << "Aucun type de formes selectionné" << endl;
        }
    }
    catch(BaseException& E)
    {
        E.Afficher();
    }
}

int MenuClick (int clickX,int clickY)
{



    if(clickX>=35 && clickY>=5 && clickX<=59 && clickY<=31)
        return 3; // Enregister dessin

    if(clickX>=39 && clickY>=34 && clickX<=63 && clickY<=57)
        return 4; // Fermer dessin

    if(clickX>=123 && clickY>=5 && clickX<=148&& clickY<=31)
        return 5; //Paramètre dessin

    if(clickX>=121 && clickY>=40 && clickX<=145&& clickY<=61)
        return 6; //Set Background

    if(clickX>=268 && clickY>=8 && clickX<=282 && clickY<=35)
        return 7; // Etat mémoire

    if(clickX>=471 && clickY>=8 && clickX<=486 && clickY<=21)
        return 13; // Ajouter une ligne

    if(clickX>=513 && clickY>=9 && clickX<=526 && clickY<=21)
        return 21; // Ajouter Cercle

    if(clickX>=534 && clickY>=9 && clickX<=545 && clickY<=21)
        return 20; //Ajouter Rectangle

    if(clickX>=494 && clickY>=11 && clickX<=506 && clickY<=22)
        return 19; //Ajouter Pixel

    if(clickX>=393 && clickY>=11 && clickX<=408 && clickY<=23)
        return 14; //Supprimer une forme

    if(clickX>=391 && clickY>=34 && clickX<=406 && clickY<=51)
        return 17; //Afficher les infos des formes

    if(clickX>=472 && clickY>=37 && clickX<=486 && clickY<=53)
        return 22; //Modifier remplissage

    if(clickX>=441 && clickY>=8 && clickX<=450 && clickY<=21)
        return 15; //Modifier la couleur d'une forme

    if(clickX>=420 && clickY>=8 && clickX<=431 && clickY<=23)
        return 18; //Importer forme CSV

    if(clickX>=850 && clickY>=8 && clickX<=864 && clickY<=22)
        return 8; // Ajouter une couleur

    if(clickX>=874 && clickY>=8 && clickX<=887 && clickY<=22)
        return 10; // Supprimer une couleur

    if(clickX>=849 && clickY>=36 && clickX<=862 && clickY<=47)
        return 9; //Modifier une couleur

    if(clickX>=898 && clickY>=8 && clickX<=913 && clickY<=22)
        return 11; //Afficher Palette

    if(clickX>=876 && clickY>=36 && clickX<=886 && clickY<=51)
        return 12; //Importer couleur CSV



    return 16; //Afficher forme sélectionnée
}


void AffichagePosition ()
{
    while (1) {

        WindowSDLclick click1 = WindowSDL::waitClick();
        click1.getX();
        click1.getY();

        cout << "X: " << click1.getX() << endl;
        cout << "Y: " << click1.getY() << endl;
    }
}

void PaletteBase (Dessin *SuperDessin)
{
    Couleur C;

    C=Couleur(0,0,0,"Noir");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(127,127,127,"Gris Foncé");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(136,0,21,"Bordeaux");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(255,0,0,"Rouge");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(255,127,39,"Orange");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(255,255,0,"Jaune");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(134,177,76,"Vert Foncé");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(0,162,232,"Bleu Ciel");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(63,72,204,"Bleu Marine");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(163,73,164,"Mauve");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(255,255,255,"Blanc");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(195,195,195,"Gris Clair");
    SuperDessin->AjouteCouleur(C);


    C=Couleur(185,122,87,"Brun");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(255,174,201,"Rose");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(255,201,14,"Jaune Foncé");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(239,228,176,"Beiche");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(181,230,29,"Vert Clair");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(153,217,234,"Bleu Clair");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(112,146,190,"Bleu Pale");
    SuperDessin->AjouteCouleur(C);

    C=Couleur(200,191,231,"Pervenche");
    SuperDessin->AjouteCouleur(C);



}

char* SelectCouleur (char *NomCouleur, Dessin *SuperDessin)
{
    int clickX, clickY;

    while(1) {
        cout<<"Wait Click"<<endl;
        WindowSDLclick click1 = WindowSDL::waitClick();
        clickX = click1.getX();
        clickY = click1.getY();



        if (clickX >= 570 && clickY >= 5 && clickX <= 587 && clickY <= 23)
            return (char *) "Noir";

        if (clickX >= 592 && clickY >= 5 && clickX <= 609 && clickY <= 23)
            return (char *) "Gris Foncé";

        if (clickX >= 614 && clickY >= 5 && clickX <= 631 && clickY <= 23)
            return (char *) "Bordeaux";

        if (clickX >= 636 && clickY >= 5 && clickX <= 653 && clickY <= 23)
            return (char *) "Rouge";

        if (clickX >= 658 && clickY >= 5 && clickX <= 675 && clickY <= 23)
            return (char *) "Orange";

        if (clickX >= 680 && clickY >= 5 && clickX <= 697 && clickY <= 23)
            return (char *) "Jaune";

        if (clickX >= 702 && clickY >= 5 && clickX <= 719 && clickY <= 23)
            return (char *) "Vert Foncé";

        if (clickX >= 724 && clickY >= 5 && clickX <= 741 && clickY <= 23)
            return (char *) "Bleu Ciel";

        if (clickX >= 746 && clickY >= 5 && clickX <= 763 && clickY <= 23)
            return (char *) "Bleu Marine";

        if (clickX >= 766 && clickY >= 5 && clickX <= 785 && clickY <= 23)
            return (char *) "Mauve";

        if (clickX >= 570 && clickY >= 27 && clickX <= 587 && clickY <= 45)
            return (char *) "Blanc";

        if (clickX >= 592 && clickY >= 27 && clickX <= 609 && clickY <= 45)
            return (char *) "Gris Clair";

        if (clickX >= 614 && clickY >= 27 && clickX <= 631 && clickY <= 45)
            return (char *) "Brun";

        if (clickX >= 636 && clickY >= 27 && clickX <= 653 && clickY <= 45)
            return (char *) "Rose";

        if (clickX >= 658 && clickY >= 27 && clickX <= 675 && clickY <= 45)
            return (char *) "Jaune Foncé";

        if (clickX >= 680 && clickY >= 27 && clickX <= 697 && clickY <= 45)
            return (char *) "Beiche";

        if (clickX >= 702 && clickY >= 27 && clickX <= 719 && clickY <= 45)
            return (char *) "Vert Clair";

        if (clickX >= 724 && clickY >= 27 && clickX <= 741 && clickY <= 45)
            return (char *) "Bleu Clair";

        if (clickX >= 746 && clickY >= 27 && clickX <= 763 && clickY <= 45)
            return (char *) "Bleu Pale";

        if (clickX >= 768 && clickY >= 27 && clickX <= 785 && clickY <= 45)
            return (char *) "Pervenche";

        if (clickX >= 799 && clickY >= 137 && clickX <= 841 && clickY <= 175)
        {
            cout << "Entrez la couleur de la forme :";
            fflush(stdin);
            cin.getline(NomCouleur, 80);
            return (char*) NomCouleur;
        }


        int Colonne, Case, i, x ,y ;
        Liste<Couleur> Pal;
        Pal = SuperDessin->getPalette();
        Iterateur<Couleur> Rech(Pal);


       for (Rech.reset(), i = 0; !Rech.end() && i < 20; Rech++, i++);

        for (Colonne = 0; !Rech.end() && Colonne < 6; Colonne++)
        {
            y=99+(Colonne*22);
            for (Case = 0; !Rech.end() && Case < 8; Rech++, Case++)
            {
                x=582+(26*Case);
                if (clickX >= x && clickY >= y && clickX <= x+15 && clickY <= y+13) {
                    strcpy(NomCouleur,((Couleur) Rech).getNom());
                    return (char *) NomCouleur;
                }
            }

        }

    }

}

int ChoixProfondeur()
{
    int continuer=1;
    int prof=0;
    char Ev=0;


    while (continuer)
    {
        cout<<"La profondeur est de "<<prof<<endl;
        cout<<"Appuyez sur la touche flèche vers le haut ou flèche vers le bas de votre clavier pour augmenter ou diminuer"<<endl;
        cout<<"Appuyez sur la touche espace ou enter pour valider la profondeur"<<endl;

        Ev = WindowSDL::waitKey();

        switch(Ev)
        {
            case 'V':
                    continuer = 0;
                    break;
            case '+':
                    prof++ ;
                    break;
            case '-':
                    prof-- ;
                    break;
        }
    }

    return prof;
}


void CreationPalette (Dessin* SuperDessin )
{
    int Colonne, Case, i;
    Liste<Couleur> Pal;
    Pal=SuperDessin->getPalette();
    Iterateur<Couleur> Rech(Pal);

    WindowSDL::setPalette();


       for (Rech.reset(), i=0 ; !Rech.end() && i<20; Rech++,i++);

        for (Colonne=0; !Rech.end() && Colonne<6 ; Colonne++)
        {
            for(Case=0; !Rech.end() && Case<=7 ;Rech++, Case++)
            {
                WindowSDL::RemplirPalette(Case, Colonne,((Couleur)Rech).getRouge(),((Couleur)Rech).getVert(),((Couleur)Rech).getBleu());
            }

        }
}

int SelectClickFormes ()
{
    int clickX, clickY;
    WindowSDLclick click1=WindowSDL::waitClick();

    clickX=click1.getX();
    clickY=click1.getY();

    if(clickX>=471 && clickY>=8 && clickX<=486 && clickY<=21)
        return 1; // Ajouter une ligne

    if(clickX>=513 && clickY>=9 && clickX<=526 && clickY<=21)
        return 4; // Ajouter Cercle

    if(clickX>=534 && clickY>=9 && clickX<=545 && clickY<=21)
        return 3; //Ajouter Rectangle

    if(clickX>=494 && clickY>=11 && clickX<=506 && clickY<=22)
        return 2; //Ajouter Pixel

    return 1000;
}
