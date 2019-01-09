#include "Enums.hpp"

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