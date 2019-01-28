#include "Joueur.hpp"
#include "Unite.hpp"

#include <iostream>

Joueur::Joueur(EnumEquipe equipe, std::string nom, bool IA) : m_equipe(equipe), m_tour(Tour(equipe)), m_piecesOr(OR_INITIAL), m_nom(nom), m_ia(IA){

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

//recrutement gratuit pour le chargement d'une partie
bool Joueur::recruter(Plateau_t& p, Categorie* c, unsigned int position){

	if(p.getCase(position)==nullptr){

		Unite* u = new Unite(c, m_equipe, this);
		m_listeUnite.push_back(u);
		p.AjouteUnite(position,u);

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


//MAJ du nb de piece du joueur
void Joueur::MAJPieces(int pieces){
	if((int)m_piecesOr >= -pieces){
		m_piecesOr+=pieces;
	}
}


//Faire jouer le tour de ses unités
void  Joueur::Jouer(Plateau_t &p){

	std::vector<bool> reussiteAction1;

	//Init de la liste des actions réussie
	//(ordre de création croissant)
	for(size_t i = 0; i<m_listeUnite.size();i++){
		reussiteAction1.push_back(false);
	}

	//On fait jouer chaque unité par ordre décroissant de création (Phase d'action 1)
	for(size_t i = 0; i<m_listeUnite.size();i++){

		Unite* unite = m_listeUnite.at(m_listeUnite.size()-1-i);

		bool OK = unite->Action1(p);

		//l'unité essaye de faire ses actions
		reussiteAction1.at(m_listeUnite.size()-1-i) = OK;

		
	}

	//On fait jouer chaque unité par ordre croissant de création (Phase d'action 2)
	for(size_t i = 0; i<m_listeUnite.size();i++){
		Unite* unite = m_listeUnite.at(i);
		unite->Action2(p);

	}

	//On fait jouer chaque unité par ordre croissant de création (Phase d'action 3)
	for(size_t i = 0; i<m_listeUnite.size();i++){
		Unite* unite = m_listeUnite.at(i);

		//On lance l'action alternative si elle est autorisée
		unite->ActionAlt(p, reussiteAction1.at(i));

	}
		

}