#pragma once

#include "Enums.hpp"

class Entite{

private:
	unsigned int m_vie;
	unsigned int m_x;
	EnumEquipe m_equipe;

public:
	//Le constructeur d'Entite gère la position initiale des objets en fonction de leur équipe
	Entite(int vie, EnumEquipe equipe):m_vie(vie),  m_x(positionTour(equipe)), m_equipe(equipe){};
	
	//destructeur virtuel (pour le polymorphisme)
	virtual ~Entite(){};


	//TODO => A IMPLEMENTER
	int getVie();
	int getX();
	EnumEquipe getEquipe();

	//renvoit vrai si l'entite meurt après avoir subi les dégats
	bool subirDegats(unsigned int degats);

	//Gère la mort d'une entité
	virtual void Mourir(Plateau_t& p);


};
