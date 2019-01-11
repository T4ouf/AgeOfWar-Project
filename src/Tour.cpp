#include "Tour.hpp"


Tour::Tour(EnumEquipe equipe) : Entite(VIE_TOUR,equipe){
	//TODO = le reste...
	if(equipe==EquipeA){
		position = 0;
	}else {
		position=11;
	}
}

Tour::~Tour(){
	//TODO
}

int Tour::getPosition(){
	return position;
}
