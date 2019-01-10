#pragma once

#include <vector>

#include "Enums.hpp"
#include "Tour.hpp"


#define OR_INITIAL 10

class Unite;

class Joueur{

private :

    EnumEquipe m_equipe;
    std::vector<Unite*> m_listeUnite;
    Tour m_tour;

    int m_piecesOr;
    bool m_ia;

public:

	Joueur(EnumEquipe equipe, bool IA);

    void EnleveUnite(Unite* u);

};
