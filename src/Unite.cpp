#include "Unite.hpp"
#include "Fantassin.hpp"
#include "SuperSoldat.hpp"
#include "Joueur.hpp"

#include <iostream>

Unite::Unite(Categorie* categorie, EnumEquipe equipe, Joueur* proprietaire) : Entite(categorie->getVieMax(),equipe){

	m_proprietaire=proprietaire;

	m_actions[0]=categorie->getAction1();
	m_actions[1]=categorie->getAction2();

	m_actionAlternative=categorie->getActionAlt();

	m_categorie = categorie;

	m_nom = categorie->genNom();
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
		Entite* cible = p.getCase(m_categorie->verifPortee(p, getX(),getEquipe()));

		//S'il faut attaquer une case vide => soit c'est une tour soit c'est une case adjacente qu'il faut attaquer
		if(cible==nullptr){

			if(m_categorie->verifPortee(p, getX(),getEquipe()) == BASE_A){

				//si la tour n'a plus de vie...
				if(p.tourA->subirDegats(m_categorie->getPuissance())){

					//...alors elle meurt
					p.tourA->Mourir(p);

				}

			}
			else if (m_categorie->verifPortee(p, getX(),getEquipe()) == BASE_B){

				//Si la tour n'a plus de vie...
				if(p.tourB->subirDegats(m_categorie->getPuissance())){
					///... alors elle meurt
					p.tourB->Mourir(p);

				}
			}
			else{
				//rien à faire
			}

		}
		//si la cible meurt dans l'attaque
		else if(cible->subirDegats(m_categorie->getPuissance())){

			//On récupère l'argent de la mort de l'unité
			m_proprietaire->MAJPieces(cible->getPrix()/2);

			//La cible meurt
			cible->Mourir(p);

			if(m_categorie==Fantassin::getInstance()){
				Promotion();
			}

		}

		for(unsigned int i=1; i<=m_categorie->getCaseSuppDegats();i++){
			Unite* cible = p.getCase(m_categorie->verifPortee(p, getX(),getEquipe())+(i*direction(getEquipe())));

			//S'il faut attaquer une case vide => c'est une tour
			if(cible==nullptr){

				if(m_categorie->verifPortee(p, getX(),getEquipe()) == BASE_A){

					//si la tour n'a plus de vie...
					if(p.tourA->subirDegats(m_categorie->getPuissance())){

						//...alors elle meurt
						p.tourA->Mourir(p);

					}

				}
				else if (m_categorie->verifPortee(p, getX(),getEquipe()) == BASE_B){

					//Si la tour n'a plus de vie...
					if(p.tourB->subirDegats(m_categorie->getPuissance())){
						///... alors elle meurt
						p.tourB->Mourir(p);

					}
				}
				else{
					//rien à faire
				}

			}
			//si la cible (dégats collatéraux) meurt dans l'attaque
			else if(cible->subirDegats(m_categorie->getPuissance())){

				//On récupère l'argent de la mort de l'unité
				m_proprietaire->MAJPieces(cible->getPrix()/2);
				
				cible->Mourir(p);

				//On verif la promotion
				if(m_categorie==Fantassin::getInstance()){
					Promotion();
				}

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
			if(p.getCase(getX()+1)==nullptr){

				p.EnleveUnite(getX());
				m_x += direction(m_equipe);
				p.AjouteUnite(getX(),this);

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
			if(p.getCase(getX()-1)==nullptr){

				p.EnleveUnite(getX());
				m_x += direction(m_equipe);
				p.AjouteUnite(getX(),this);

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

//getter sur le nom
std::string Unite::getNom(){return m_nom;}

//getter sur la catégorie
Categorie* Unite::getCategorie(){return m_categorie;}

//getter sur le prix de l'unité
unsigned int Unite::getPrix(){return m_categorie->getPrix();}

//L'unité effectue son action principale
bool Unite::Action1(Plateau_t& p){
	
	switch (m_actions[0]){
		case EnumAction::Attaquer : return this->Attaquer(p);
		case EnumAction::Avancer : 	return this->Deplacer(p);
		case EnumAction::Vide :		break;
	}

	return false;

}

//L'unité effectue son action secondaire
bool Unite::Action2(Plateau_t& p){

	switch (m_actions[1]){
		case EnumAction::Attaquer : return this->Attaquer(p);
		case EnumAction::Avancer : 	return this->Deplacer(p);
		case EnumAction::Vide : break;
	}

	return false;

}

//L'unité effectue son action alternative
bool Unite::ActionAlt(Plateau_t& p, bool SuccesAction1){


	if(SuccesAction1){

		if(m_categorie==SuperSoldat::getInstance()){
			switch (m_actionAlternative){
				case EnumAction::Attaquer : return this->Attaquer(p);

				case EnumAction::Avancer : return this->Deplacer(p);

				case EnumAction::Vide : break;
			}
		}

	}
	else{
		switch (m_actionAlternative){
			case EnumAction::Attaquer : return this->Attaquer(p);

			case EnumAction::Avancer : return this->Deplacer(p);

			case EnumAction::Vide : break;
		}
	}
	

	return false;
}
