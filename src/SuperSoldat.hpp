#pragma once


#include "Categorie.hpp"

class SuperSoldat : public Categorie{

private :

	static unsigned int ID;
	
	static SuperSoldat* instance;
	
	SuperSoldat();
	~SuperSoldat();
	
	
	friend class _Application;

public :

	static SuperSoldat* getInstance();		
	
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
