#pragma once

#include "Application.hpp"
#include "Categorie.hpp"

class Catapulte : public Categorie{

private : 
	
	static unsigned int ID;
	Catapulte();
	~Catapulte();

	friend class _Application;

public : 

	std::string getNom() override;
	EnumAction getAction1()override;
	EnumAction getAction2() override;
	EnumAction getActionAlt() override;

	unsigned int getPrix() override;
	unsigned int getVieMax() override;
	unsigned int getPuissance() override;
	
	unsigned int getPorteeMin() override;
	unsigned int getPorteeMax() override;
	unsigned int getCaseSuppDegats() override;
	int verifPortee(Plateau_t p, unsigned int positionActuelle, int direction, EnumEquipe e) override;

};


