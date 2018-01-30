#include <iostream>



class Couleur {
	private:
		int Rouge;
		int Bleu;
		int Vert;
		char *nom;
	public:
		Couleur();
		Couleur(int, int, int, char*);
		Couleur(int, int, int);
		Couleur(Couleur&);
		~Couleur();
		
		void setNom (char*);
		void setRouge (int);
		void setBleu (int);
		void setVert (int);

		
		char *getNom() const;
		int getRouge () const;
		int getBleu () const;
		int getVert () const;
				
		void Affiche () const;
};
