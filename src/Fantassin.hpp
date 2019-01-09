#pragma once

#include "Application.hpp"
#include "Categorie.hpp"

class Fantassin : public Categorie{

private :

	static unsigned int ID;
	Fantassin();
	~Fantassin();

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

	//Méthode qui vérifie si une unité ennemie est à portée (et renvoit le numéro de la case à attaquer si c'est le cas (-1 sinon))
	int verifPortee(Plateau_t p, unsigned int positionActuelle, int direction) override;

};

unsigned int Fantassin::ID = 0;
