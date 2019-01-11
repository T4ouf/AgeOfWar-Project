#pragma once

#include "Entite.hpp"

//IMPORTANT LA MORT D'UNE TOUR ENTRAINE LA FIN DU JEU => GERER ça dans le destructeur

#define VIE_TOUR 100


class Tour : public Entite{

private :

	int position;
	//TODO faire les attributs
	
public : 
	
	Tour(EnumEquipe equipe);
	~Tour();
	int getPosition();


};
