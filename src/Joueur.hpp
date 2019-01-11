#pragma once

#include <vector>

#include "Enums.hpp"
#include "Tour.hpp"
#include "Categorie.hpp"


#define OR_INITIAL 10

class Unite;

class Joueur{

private :

    EnumEquipe m_equipe;
    std::vector<Unite*> m_listeUnite;
    Tour m_tour;

    unsigned int m_piecesOr;
    bool m_ia;

public:

	Joueur(EnumEquipe equipe, bool IA);
	~Joueur();
	bool recruter(Plateau_t p, Categorie* c);
   	void EnleveUnite(Unite* u);

};
