#pragma once

#include <vector>

#include "Enums.hpp"
#include "Tour.hpp"
#include "Unite.hpp"


class Joueur{

private : 

    EnumEquipe m_equipe;
    vector<Unite> m_listeUnite;
    Tour m_tour;

    int m_piecesOr;
    bool m_ia;
        
public:

	Joueur(EnumEquipe equipe, bool IA);
	~Joueur();

};
