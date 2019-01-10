#include "Unite.hpp"
#include "Joueur.hpp"

Unite::Unite(Categorie* categorie, EnumEquipe equipe, Joueur* proprietaire) : Entite(categorie->getVieMax(),equipe){

	m_proprietaire=proprietaire;

	m_actions[0]=categorie->getAction1();
	m_actions[1]=categorie->getAction2();

	m_actionAlternative=categorie->getActionAlt();

	m_nom = categorie->getNom() + "(" + getNomEquipe(equipe) + ")";

	m_categorie = categorie;
}

/**
 *
 *
 */
bool Unite::Attaquer(Plateau_t& p){

	//Si pas d'unité adverse à portée..
	if( m_categorie->verifPortee(p, getX(),getEquipe())==-1){
		return false;
	}
	else{
		Unite* cible = p.getCase(m_categorie->verifPortee(p, getX(),getEquipe()));
		
		//si la cible meurt dans l'attaque
		if(cible->subirDegats(m_categorie->getPuissance())){
			cible->Mourir(p);
		}

		for(unsigned int i=1; i<=m_categorie->getCaseSuppDegats();i++){
			Unite* cible = p.getCase(m_categorie->verifPortee(p, getX(),getEquipe())+(i*direction(getEquipe())));
			
			//si la cible (dégats collatéraux) meurt dans l'attaque
			if(cible->subirDegats(m_categorie->getPuissance())){
				cible->Mourir(p);
			}

		}

		return true;
	}

}

bool Unite::Deplacer(Plateau_t& p){
	//TODO
	return false;
}

bool Unite::Promotion(){

	//TODO
	return false;
}

void Unite::Mourir(Plateau_t& p){

	//On enlève l'unité du plateau
	p.EnleveUnite(getX());

	//On l'enlève de la liste des unités
	m_proprietaire->EnleveUnite(this);

	//et on supprime l'unité
	delete this;

}
