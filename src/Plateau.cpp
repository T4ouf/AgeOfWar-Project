#include "Plateau.hpp"
#include "Unite.hpp"
#include "Tour.hpp"

#include <sstream>

void Plateau_t::Init(Tour* tourJ1, Tour* tourJ2){

	tourA = tourJ1;
	tourB = tourJ2;

	for(unsigned int i=0; i<=TAILLE_PLATEAU; i++){
		//init le plateau avec des cases vides
		casesUnite.push_back(nullptr);
	}
}

bool Plateau_t::VerifOK(unsigned int numCase){
	return numCase<=TAILLE_PLATEAU;
}

Unite* Plateau_t::getCase(unsigned int numCase){
	
	//renverra le bon type sauf exception (index out of bound)
	return (casesUnite.at(numCase));
}

bool Plateau_t::EnleveUnite(unsigned int numCase){

	
	if(casesUnite.at(numCase) != nullptr){
	
		casesUnite.at(numCase) = nullptr;
		return true;
	}
	return false;
}


bool Plateau_t::AjouteUnite(unsigned int numCase, Unite* unite){
	
	if(casesUnite.at(numCase) == nullptr){
		casesUnite.at(numCase) = unite;
		return true;
	}
	return false;
}


std::string Plateau_t::decalChateau(size_t decalage, std::string chateau){

	std::stringstream res;

	std::string dec = "";

	for(size_t i=0; i<decalage;i++){
		dec+= "\t";
	}

	for(size_t i=0;i<chateau.size();i++){

		if(i==0){
			res << dec << chateau.at(i);
		}
		if(chateau.at(i)=='\n'){
			res << chateau.at(i) << dec;
		}
		else{
			res << chateau.at(i);
		}
	}

	return res.str();
}

std::string Plateau_t::deuxChateaux(size_t decalage, std::string chateau){

	std::stringstream res;

	std::string ligne = "";

	std::string dec = "";

	for(size_t i=0; i<decalage;i++){
		dec+= "\t";
	}

	for(size_t i=0;i<chateau.size();i++){
		
		if(chateau.at(i)=='\n'){
			res << ColorerTexte(ligne,Gras,COULEUR_EQUIPE_A) << dec << ColorerTexte(ligne,Gras,COULEUR_EQUIPE_B) << '\n';
			ligne="";
			continue;
		}

		ligne+=chateau.at(i);
	}

	return res.str();
}

std::string Plateau_t::toString(){

	std::stringstream sstm;

	//On compte exactement le nombre de char pour faire une bordure adaptative
	size_t taille = 0;

	//ASCII art du chateau
	std::string chateau = "               T~~\n               |\n              /\"\\ \n      T~~     |'| T~~\n  T~~ |    T~ WWWW|\n  |  /\"\\   |  |  |/\\T~~\n /\"\\ WWW  /\"\\ |' |WW|\nWWWWW/\\| /   \\|'/\\|/\"\\\n|   /__\\/]WWW[\\/__\\WWWW\n|\"  WWWW'|I_I|'WWWW'  |\n|   |' |/  -  \\|' |'  |\n|'  |  |LI=H=LI|' |   |\n|   |' | |[_]| |  |'  |\n|   |  |_|###|_|  |   |\n'---'--'-/___\\-'--'---'\n";

	for(size_t i=0; i<=TAILLE_PLATEAU;i++){

		sstm << "|";
		taille++;

		if(i==BASE_A){

			if(getCase(i)==nullptr){
				sstm << ColorerTexte("BASE A",Inverse,COULEUR_EQUIPE_A);
				taille+=6;
			}
			else{
				//c'est forcément une unité alliée sur la case de la base
				sstm  << ColorerTexte(getCase(i)->getNom(),Gras,COULEUR_EQUIPE_A);
				taille += getCase(i)->getNom().size();
			}

		}
		else if(i==BASE_B){

			if(getCase(i)==nullptr){
				sstm << ColorerTexte("BASE B",Inverse,COULEUR_EQUIPE_B);
				taille+=6;
			}
			else{
				sstm  << ColorerTexte(getCase(i)->getNom(),Gras,COULEUR_EQUIPE_B);
				taille += getCase(i)->getNom().size();
			}

		}
		else{

			if(getCase(i)==nullptr){
				sstm << "    ";
				taille += 4;
			}
			else if(getCase(i)->getEquipe()==EquipeA){

				sstm  << ColorerTexte(getCase(i)->getNom() + "(" +
				 std::to_string(100*getCase(i)->getVie()/getCase(i)->getCategorie()->getVieMax()) + "%)",Gras,COULEUR_EQUIPE_A);
				taille += getCase(i)->getNom().size() + std::to_string(getCase(i)->getVie()/getCase(i)->getCategorie()->getVieMax()).size() + 5;

			}
			else if(getCase(i)->getEquipe()==EquipeB){
				sstm  << ColorerTexte(getCase(i)->getNom() + "(" +
				 std::to_string(100*getCase(i)->getVie()/getCase(i)->getCategorie()->getVieMax()) + "%)",Gras,COULEUR_EQUIPE_B);
				taille += getCase(i)->getNom().size() + std::to_string(getCase(i)->getVie()/getCase(i)->getCategorie()->getVieMax()).size() + 5;
			}

		}

		
	}
	sstm << "|";
	taille++;

	std::string tirets = "";

	for(size_t i=0; i<taille;i++){
		tirets += '-';
	}

	std::stringstream res;

	res << deuxChateaux(6,chateau) << "\n          " << ColorerTexte(std::to_string(100*tourA->getVie()/VIE_TOUR) + "%",GrasInverse,COULEUR_EQUIPE_A) << 
								 "\t\t\t\t\t\t\t          " << ColorerTexte(std::to_string(100*tourB->getVie()/VIE_TOUR) +"%",GrasInverse,COULEUR_EQUIPE_B) << 
									  "\n\t   " << tirets << "\n\t   " << sstm.str() << "\n\t   " << tirets << '\n';
	/*DebugLine : /res << "\n" << tirets << "\n" << sstm.str() << "\n" << tirets << '\n';*/
	return res.str();

}
