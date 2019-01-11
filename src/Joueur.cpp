#include "Joueur.hpp"
#include "Unite.hpp"


Joueur::Joueur(EnumEquipe equipe, bool IA) : m_equipe(equipe), m_tour(Tour(equipe)), m_piecesOr(OR_INITIAL), m_ia(IA){

}
Joueur::~Joueur(){

}

bool Joueur::recruter(Plateau_t p, Categorie* c){
	if (c->getPrix()> m_piecesOr){
		return false;
	}else if(p.getCase(m_tour.getPosition())==nullptr){
		Unite u = Unite(c, m_equipe, this);
		m_listeUnite.push_back(&u);
		return true;
	}
	return false;
}

void Joueur::EnleveUnite(Unite* u){
	//TODO
	unsigned int i =0;
	while(i<m_listeUnite.size()){
		if(u == m_listeUnite.at(i)){
			m_listeUnite.erase(m_listeUnite.begin()+i);
		}
	}
}


void Joueur::MAJPieces(int pieces){
	if((int)m_piecesOr >= -pieces){
		m_piecesOr+=pieces;
	}
}


