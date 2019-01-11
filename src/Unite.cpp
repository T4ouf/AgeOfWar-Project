#include "Unite.hpp"
#include "Fantassin.hpp"
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
 * Methode d'attaque d'une unité
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

			if(m_categorie==Fantassin::getInstance()){
				Promotion();
			}

			m_proprietaire->MAJPieces(m_categorie->getPrix()/2);

		}

		for(unsigned int i=1; i<=m_categorie->getCaseSuppDegats();i++){
			Unite* cible = p.getCase(m_categorie->verifPortee(p, getX(),getEquipe())+(i*direction(getEquipe())));

			//si la cible (dégats collatéraux) meurt dans l'attaque
			if(cible->subirDegats(m_categorie->getPuissance())){
				cible->Mourir(p);

				//On verif la promotion
				if(m_categorie==Fantassin::getInstance()){
					Promotion();
				}

				m_proprietaire->MAJPieces(m_categorie->getPrix()/2);
			}

		}

		return true;
	}

}

bool Unite::Deplacer(Plateau_t& p){

	if(getEquipe()==EquipeA){

		//Si l'unité est déjà au bout => On ne bouge pas
		if(getX()==BASE_B-1){
			return false;
		}
		else{

			//Si la place est libre => on se déplace
			if((p.getCase(getX())+1)==nullptr){

				p.EnleveUnite(getX());
				p.AjouteUnite(getX()+1,this);

				return true;
			}
			else{
				return false;
			}

		}

	}
	else{

		//Si l'unité est déjà au bout => On ne bouge pas
		if(getX()==BASE_A+1){
			return false;
		}
		else{

			//Si la place est libre => on se déplace
			if((p.getCase(getX())-1)==nullptr){

				p.EnleveUnite(getX());
				p.AjouteUnite(getX()-1,this);

				return true;
			}
			else{
				return false;
			}

		}
	}

	return false;
}

bool Unite::Promotion(){

	if(m_categorie->promotion()==m_categorie){
		return false;
	}
	else{
		m_categorie=m_categorie->promotion();
		return true;
	}

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
