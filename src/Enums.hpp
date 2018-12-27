#pragma once

const unsigned int BASE_A=0;
const unsigned int BASE_B=11;

enum EnumEquipe{
	EquipeA=1,
	EquipeB=2
};
 

enum EnumAction{
	Vide = 0,
	Avancer = 1,
	Attaquer =2
};


int positionTour(EnumEquipe e);




