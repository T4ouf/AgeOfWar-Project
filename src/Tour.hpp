#pragma once

#include "Entite.hpp"

//IMPORTANT LA MORT D'UNE TOUR ENTRAINE LA FIN DU JEU => GERER ça dans le destructeur

#define VIE_TOUR 100

class Tour : public Entite{

private :
	
public : 
	
	Tour(EnumEquipe equipe);
	~Tour();

	//Gère la mort de l'unité (préviens le plateau et détruit l'objet)
	void Mourir(Plateau_t& p) override;

	//getter du prix d'une tour = 0
	unsigned int getPrix() override;
};
