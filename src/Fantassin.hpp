#pragma once


#include "Categorie.hpp"

class Fantassin : public Categorie{

private :

	static unsigned int ID;

	static Fantassin* instance;

	Fantassin();
	virtual ~Fantassin();

public :

	static Fantassin* getInstance();

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
	int verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e) override;

	Categorie* promotion() override;

};
