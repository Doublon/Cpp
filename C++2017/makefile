.SILENT:
COULEUR=.
OBJS=Couleur.o Point.o Forme.o Pixel.o Ligne.o Rectangle.o BaseException.o InvalidColorException.o ListeBase.o Liste.o  ListeTriee.o Iterateur.o SmartPointer.o Dessin.o WindowSDL.o WindowSDLexception.o WindowSDLclick.o Cercle.o
PROGRAM=Paint

all:$(PROGRAM)

GPP= g++ -m64 -Wall -D SUN -I $(COULEUR)

Paint: $(COULEUR)/Paint.cpp $(OBJS) $(COULEUR)/Paint.h
	echo creation de Paint
	$(GPP) $(OBJS) $(COULEUR)/Paint.cpp -o Paint -lpthread -lSDL
 
Couleur.o: $(COULEUR)/Couleur.cpp $(COULEUR)/Couleur.h
	echo creation de Couleur.o
	$(GPP) $(COULEUR)/Couleur.cpp -c

Point.o: $(COULEUR)/Point.cpp $(COULEUR)/Point.h
	echo creation de Point.o
	$(GPP) $(COULEUR)/Point.cpp -c

Forme.o: $(COULEUR)/Forme.cpp $(COULEUR)/Forme.h
	echo creation de Forme.o
	$(GPP) $(COULEUR)/Forme.cpp -c

Pixel.o: $(COULEUR)/Pixel.cpp $(COULEUR)/Pixel.h
	echo creation de Pixel.o
	$(GPP) $(COULEUR)/Pixel.cpp -c

Ligne.o: $(COULEUR)/Ligne.cpp $(COULEUR)/Ligne.h
	echo creation de Ligne.o
	$(GPP) $(COULEUR)/Ligne.cpp -c

Rectangle.o: $(COULEUR)/Rectangle.cpp $(COULEUR)/Rectangle.h
	echo creation de Rectangle.o
	$(GPP) $(COULEUR)/Rectangle.cpp -c

Cercle.o: $(COULEUR)/Cercle.cpp $(COULEUR)/Cercle.h
	echo creation de Cercle.o
	$(GPP) $(COULEUR)/Cercle.cpp -c

BaseException.o: $(COULEUR)/BaseException.cpp $(COULEUR)/BaseException.h
	echo creation de BaseException.o
	$(GPP) $(COULEUR)/BaseException.cpp -c

InvalidColorException.o: $(COULEUR)/InvalidColorException.cpp $(COULEUR)/InvalidColorException.h
	echo creation de InvalidColorException.o
	$(GPP) $(COULEUR)/InvalidColorException.cpp -c

ListeBase.o: $(COULEUR)/ListeBase.cpp $(COULEUR)/ListeBase.h
	echo creation de ListeBase.o
	$(GPP) $(COULEUR)/ListeBase.cpp -c

Liste.o: $(COULEUR)/Liste.cpp $(COULEUR)/Liste.h
	echo creation de Liste.o
	$(GPP) $(COULEUR)/Liste.cpp -c

ListeTriee.o: $(COULEUR)/ListeTriee.cpp $(COULEUR)/ListeTriee.h
	echo creation de ListeTriee.o
	$(GPP) $(COULEUR)/ListeTriee.cpp -c

Iterateur.o: $(COULEUR)/Iterateur.cpp $(COULEUR)/Iterateur.h
	echo creation de Iterateur.o
	$(GPP) $(COULEUR)/Iterateur.cpp -c

SmartPointer.o: $(COULEUR)/SmartPointer.cpp $(COULEUR)/SmartPointer.h
	echo creation de SmartPointer.o
	$(GPP) $(COULEUR)/SmartPointer.cpp -c

Dessin.o: $(COULEUR)/Dessin.cpp $(COULEUR)/Dessin.h
	echo creation de Dessin.o
	$(GPP) $(COULEUR)/Dessin.cpp -c

WindowSDL.o:	$(COULEUR)/WindowSDL.cpp $(COULEUR)/WindowSDL.h
		echo Creation de WindowSDL.o
		$(GPP) -c $(COULEUR)/WindowSDL.cpp

WindowSDLexception.o:	$(COULEUR)/WindowSDLexception.cpp $(COULEUR)/WindowSDLexception.h
		echo Creation de WindowSDLexception.o
		$(GPP) -c $(COULEUR)/WindowSDLexception.cpp

WindowSDLclick.o:	$(COULEUR)/WindowSDLclick.cpp $(COULEUR)/WindowSDLclick.h
		echo Creation de WindowSDLclick.o
		$(GPP) -c $(COULEUR)/WindowSDLclick.cpp
clean:
	@rm -f $(OBJS) core

clobber:	clean
	@rm -f tags $(PROGRAM)

