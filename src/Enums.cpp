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