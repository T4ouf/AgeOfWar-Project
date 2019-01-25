#include "Enums.hpp"
#include <sstream>

//////////////////////////////////////////
//            ENUM EnumEquipe			//
//////////////////////////////////////////

int positionTour(EnumEquipe e){
	if(e==EquipeA){
		return BASE_A;
	}else{
		return BASE_B;
	}
}

int positionTourAdverse(EnumEquipe e){
	if(e==EquipeA){
		return BASE_B;
	}else{
		return BASE_A;
	}
}

/**
 * Fonction qui donne le sens de l'attaque de l'équipe
 * @param e, l'enum qui représente l'équipe
 * @return un entier (à multiplier) qui représente la direction
 */
int direction(EnumEquipe e){
	if(e==EquipeA){
		//l'équipeA attaque vers la droite (sens +)
		return 1;
	}else{
		//l'équipeB attaque vers la gauche (sens -)
		return -1;
	}
}

std::string getNomEquipe(EnumEquipe e){
	if(e==EquipeA){
		return "Equipe A";
	}
	else{
		return "Equipe B";
	}
}

//////////////////////////////////////////
//            ENUM EnumAction			//
//////////////////////////////////////////

//rien pour l'instant...


//////////////////////////////////////////
//         Enum Affichage texte			//
//////////////////////////////////////////

std::string ColorerTexte(const std::string& texte,int couleur,int type){

	std::stringstream sstm;
	sstm << "\033[" << type << ";" << couleur << "m" << texte << "\033[0m";
	return sstm.str();

} 


//////////////////////////////////////////
//         	Outils Utiles				//
//////////////////////////////////////////

unsigned int max(int i1, int i2){
	if(i1 < 0 && i2<0){
		return 0;
	}
	if(i1>i2){
		return i1;
	}
	return i2;
}

unsigned int min(int i1, int i2){
	if(i1 < 0 && i2<0){
		return 0;
	}
	if(i1<i2){
		return i1;
	}
	return i2;
}