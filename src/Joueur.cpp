#include "Joueur.hpp"
#include "Unite.hpp"

Joueur::Joueur(EnumEquipe equipe, bool IA) : m_equipe(equipe), m_tour(Tour(equipe)), m_piecesOr(OR_INITIAL), m_ia(IA){

}
Joueur::~Joueur(){

}

bool Joueur::recruter(Plateau_t& p, Categorie* c){

	if (c->getPrix()> m_piecesOr){
		return false;
	}else if(p.getCase(m_tour.getX())==nullptr){

		Unite* u = new Unite(c, m_equipe, this);
		m_listeUnite.push_back(u);
		p.AjouteUnite(m_tour.getX(),u);

		m_piecesOr = m_piecesOr - u->getCategorie()->getPrix();

		return true;
	}
	return false;
}

void Joueur::EnleveUnite(Unite* u){

	unsigned int i =0;
	while(i<m_listeUnite.size()){
		if(u == m_listeUnite.at(i)){
			m_listeUnite.erase(m_listeUnite.begin()+i);
			return;
		}

		i++;
	}
}


void Joueur::MAJPieces(int pieces){
	if((int)m_piecesOr >= -pieces){
		m_piecesOr+=pieces;
	}
}


//Faire jouer le tour de ses unités
void  Joueur::Jouer(Plateau_t &p){

	//On fait jouer chaque unité par ordre de création
	for(size_t i = 0; i<m_listeUnite.size();i++){

		Unite* unite = m_listeUnite.at(i);

		//l'unité essaye de faire ses actions
		bool reussiteAction1 = unite->Action1(p);

		unite->Action2(p);
		
		//On lance l'action alternative si elle est autorisée
		unite->ActionAlt(p, reussiteAction1);

	}


}