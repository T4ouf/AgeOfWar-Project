#pragma once

#include "Application.hpp"
#include "Categorie.hpp"

class Archer : public Categorie{

private : 
	
	static unsigned int ID;
	Archer();
	~Archer();

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

};

unsigned int Archer::ID = 0;