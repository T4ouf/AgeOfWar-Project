#pragma once

#include <vector>

#include "Enums.hpp"
#include "Tour.hpp"
#include "Categorie.hpp"


#define OR_INITIAL 2

class Unite;

class Joueur{

private :

  friend struct Application;

  EnumEquipe m_equipe;

  std::vector<Unite*> m_listeUnite;
  Tour m_tour;

  unsigned int m_piecesOr;
  std::string m_nom;
  bool m_ia;

public:

	Joueur(EnumEquipe equipe, std::string nom ,bool IA);
	~Joueur();
	
  bool recruter(Plateau_t& p, Categorie* c);
 	void EnleveUnite(Unite* u);
 	void MAJPieces(int piece);

  bool EstIA(){return m_ia;};
  unsigned int getArgent(){return m_piecesOr;}
  std::string getNom(){return m_nom;}
  Tour getTour() const {return m_tour;}
  Tour* refTour(){return &m_tour;}

  void setIA(bool ia){ m_ia = ia; }
  void setNom(std::string nom){ m_nom = nom; }

  //Faire jouer le tour de ses unités
  void  Jouer(Plateau_t &p);

};
