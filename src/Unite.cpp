#include "Unite.hpp"
#include "Fantassin.hpp"
#include "SuperSoldat.hpp"
#include "Catapulte.hpp"
#include "Joueur.hpp"

#include <iostream>


extern std::string recapitulatifTour;

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
	
	bool succesAttaque = false;

	int caseCible = m_categorie->verifPortee(p, getX(),getEquipe());

	//Si pas d'unité adverse à portée..
	if(caseCible==-1){
		return false;
	}
	else{

		//Si c'est une case vide => c'est la base adverse
		if(p.getCase(caseCible)==nullptr){


			//si c'est bien une tour que l'on attaque (éviter le cas d'attaque d'une case vide avec la catapulte)
			if(caseCible == positionTourAdverse(m_equipe)){

				//On récupère la base adverse
				Tour* tourAdverse;

				if(m_equipe==EquipeA){
					tourAdverse = p.tourB;
					recapitulatifTour += m_nom + " attaque la tour de l'équipe B\n";
				}
				else{
					tourAdverse = p.tourA;
					recapitulatifTour += m_nom + " attaque la tour de l'équipe A\n";
				}
				


				//On lui fait subir des dégats et on stocke si la tour meurt ou non
				bool mort = tourAdverse->subirDegats(m_categorie->getPuissance());



				//si la tour est morte => on tue l'objet
				if(mort){
					tourAdverse->Mourir(p);
					recapitulatifTour += "La tour est morte !\nFIN DE PARTIE !\n";
				}

				//L'attaque est un succès !
				succesAttaque=true;
			}
			
		}
		//sinon c'est une cible adverse
		else{

			//On récupère la cible adverse
			Unite* cible = p.getCase(caseCible);

			recapitulatifTour += m_nom + " attaque " + cible->getNom() + "\n";

			//On lui fait subir des dégats et on stocke si la cible meurt ou non
			bool mort = cible->subirDegats(m_categorie->getPuissance());

			//si la cible est morte => on tue l'objet
			if(mort){

				recapitulatifTour += cible->getNom() + " meurt de l'attaque\n";

				//On récupère l'argent de la mort de l'unité
				m_proprietaire->MAJPieces(cible->getPrix()/2);
				
				//on tue la cible
				cible->Mourir(p);

				//On verif la promotion de l'unité
				if(m_categorie==Fantassin::getInstance() && cible->getCategorie()==Fantassin::getInstance()){
					std::string oldNom = m_nom;
					Promotion();
					recapitulatifTour += "Promotion de l'unite " + oldNom + ". Il devient : " + cible->getNom() + "\n";
				}

			}

			//L'attaque est un succès !
			succesAttaque=true;

		}


		//si notre unité est une catapulte, on attaque une cible supplémentaire
		if(m_categorie==Catapulte::getInstance()){

			//on récupère la case supplémentaire à attaquer
			int caseSupplementaire = (int)caseCible + direction(getEquipe());

			//si c'est en dehors du tableau => on sort...
			if(caseSupplementaire < 0 || caseSupplementaire > TAILLE_PLATEAU){
				return succesAttaque;
			}

			//Si c'est une case vide => c'est la base adverse
			if(p.getCase(caseCible)==nullptr){

				//si c'est bien une tour que l'on attaque (éviter le cas d'attaque d'une case vide avec la catapulte)
				if(caseCible == positionTourAdverse(m_equipe)){

					//On récupère la base adverse
					Tour* tourAdverse;

					if(m_equipe==EquipeA){
					tourAdverse = p.tourB;
					recapitulatifTour += m_nom + " attaque la tour de l'équipe B (degat collateral)\n";
				}
				else{
					tourAdverse = p.tourA;
					recapitulatifTour += m_nom + " attaque la tour de l'équipe A (degat collateral)\n";
				}


					//On lui fait subir des dégats et on stocke si la tour meurt ou non
					bool mort = tourAdverse->subirDegats(m_categorie->getPuissance());

					//si la tour est morte => on tue l'objet
					if(mort){
						tourAdverse->Mourir(p);
						recapitulatifTour += "La tour est morte !\nFIN DE PARTIE !\n";
					}

					//L'attaque est un succès !
					succesAttaque=true;
				}
				
			}
			else{
				//On récupère la cible adverse
				Unite* cible = p.getCase(caseCible);

				recapitulatifTour += m_nom + " attaque (degat collateral) " + cible->getNom() + "\n";

				//On lui fait subir des dégats et on stocke si la cible meurt ou non
				bool mort = cible->subirDegats(m_categorie->getPuissance());

				//si la cible est morte => on tue l'objet
				if(mort){

					recapitulatifTour += ColorerTexte(cible->getNom() + " meurt de l'attaque\n",GrasItaliqueSouligne,Rouge);

					//On récupère l'argent de la mort de l'unité
					m_proprietaire->MAJPieces(cible->getPrix()/2);
					
					//On verif la promotion de l'unité
					if(m_categorie==Fantassin::getInstance() && cible->getCategorie()==Fantassin::getInstance()){
						std::string oldNom = m_nom;
						Promotion();
						recapitulatifTour += "Promotion de l'unite " + oldNom + ". Il devient : " + cible->getNom() + "\n";
					}

					//on tue la cible
					cible->Mourir(p);

				}

				//L'attaque est un succès !
				succesAttaque=true;
			}


		}


	}

	return succesAttaque;

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

				recapitulatifTour += m_nom + " se deplace de " + std::to_string(m_x) + " vers " + std::to_string(m_x+direction(m_equipe)) + "\n";

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

				recapitulatifTour += m_nom + " se deplace de " + std::to_string(m_x) + " vers " + std::to_string(m_x+direction(m_equipe)) + "\n";

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
		m_nom = m_categorie->genNom();
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
