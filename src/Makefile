
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11

DEPS =
OBJ = main.o Application.o Joueur.o Entite.o Unite.o Plateau.o Tour.o Enums.o Categorie.o Archer.o Catapulte.o Fantassin.o SuperSoldat.o


%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -c -o $@

ProjetCPP: $(OBJ)
	$(CXX) $^ -o $@
#Pour un build "propre" decommenter la ligne suivante
#	rm -f *o *~ core

.PHONY: clean

clean:
	rm -f *.o *~ core
