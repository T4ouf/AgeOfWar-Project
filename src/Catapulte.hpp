#pragma once


#include "Categorie.hpp"

class Catapulte : public Categorie{

private :

	static unsigned int ID;

	static Catapulte* instance;

	Catapulte();
	virtual ~Catapulte();

	friend class _Application;

public :

	static Catapulte* getInstance();

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
	std::string genNom() override;

	//methode pour reset l'id
	void resetID() override;

};
