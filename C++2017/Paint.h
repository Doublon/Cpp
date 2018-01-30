#ifndef PAINT_H
#define PAINT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <limits>
using namespace std;
#include "Ligne.h"
#include "Couleur.h"
#include "Pixel.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "ListeTriee.h"
#include "Liste.h"
#include "Dessin.h"
#include "WindowSDL.h"

#define QUITTER 0

//Gestion Générale//
int Menu(void);
void AjouterDessin(Dessin*);
void Specifierfond(Dessin*);
int MenuClick(int, int);
void AffichagePosition ();


//Gestion Palette//
void PaletteBase (Dessin *SuperDessin);
void AjouterCouleurPalette(Dessin*);
void ModifierCouleurPalette(Dessin*);
void SupprimerCouleurPalette(Dessin*);
void CreationPalette (Dessin* SuperDessin );

//Gestion des Formes du Dessin //
void AjouterFormeDessin (Dessin*,int);
void AjouterLigneDessin (Ligne*);
void AjouterPixelDessin(Pixel*);
void AjouterRectangleDessin(Rectangle*, bool);
void AjouterCercleDessin(Cercle*, bool);
void ModifierFormeDessin(Dessin*);
void SupprimerFormeDessin(Dessin*);
void ImporterFormeCSV (Dessin*);
char* SelectCouleur (char *Couleur, Dessin *SuperDessin);
int ChoixProfondeur();
int SelectClickFormes ();




#endif