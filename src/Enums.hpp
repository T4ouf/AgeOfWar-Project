#pragma once

#include <string>
#include "Plateau.hpp"


//////////////////////////////////////////
//            ENUM EnumEquipe			//
//////////////////////////////////////////

const unsigned int BASE_A=0;
const unsigned int BASE_B=TAILLE_PLATEAU;

enum EnumEquipe{
	EquipeA=1,
	EquipeB=2
};
 
int positionTour(EnumEquipe e);
std::string getNomEquipe(EnumEquipe e);

//////////////////////////////////////////
//            ENUM EnumAction			//
//////////////////////////////////////////

enum EnumAction{
	Vide = 0,
	Avancer = 1,
	Attaquer =2
};



