.SILENT:
COULEUR=$(HOME)/labo/Ex1
OBJS=couleur.o
PROGRAM=Test1

all:$(PROGRAM)

GPP= g++ -m64 -Wall -D SUN -I $(COULEUR)

Test1: Test1.cpp $(OBJS) $(COULEUR)/couleur.h
	$(GPP) $(OBJS) Test1.cpp -o Test1 

couleur.o: $(COULEUR)/couleur.cpp $(COULEUR)/couleur.h
	$(GPP) $(COULEUR)/couleur.cpp -c
