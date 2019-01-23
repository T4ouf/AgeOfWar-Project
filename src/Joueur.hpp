#pragma once

#include <vector>

#include "Enums.hpp"
#include "Tour.hpp"
#include "Categorie.hpp"


#define OR_INITIAL 12

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
	
  bool recruter(Plateau_t& p, Categorie* c);
 	void EnleveUnite(Unite* u);
 	void MAJPieces(int piece);

  bool EstIA(){return m_ia;};
  unsigned int getArgent(){return m_piecesOr;}
  Tour getTour() const {return m_tour;}
  Tour* refTour(){return &m_tour;}

  //Faire jouer le tour de ses unités
  void  Jouer(Plateau_t &p);

};
