
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11
OBJ = main.o Joueur.o Entite.o Unite.o Tour.o Enums.o Categorie.o Archer.o Catapulte.o Fantassin.o SuperSoldat.o


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

ProjetCPP: $(OBJ)
	$(CXX) $^ -o $@
#Pour un build "propre" decommenter la ligne suivante
#	rm -f *o *~ core

.PHONY: clean

clean:
	rm -f *.o *~ core 


