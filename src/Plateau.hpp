#pragma once

//#include <stdexcept>	//pour l'exception std::out_of_range
#include <vector>
#include <string>


#define TAILLE_PLATEAU 11

//Pour eviter les inclusions multiples
class Unite;
class Tour;

typedef struct Plateau{

	Tour* tourA;
	Tour* tourB;

	std::vector<Unite*> casesUnite;

	void Init(Tour* tourJ1, Tour* tourJ2);
	bool VerifOK(unsigned int numCase);
	Unite* getCase(unsigned int numCase);
	bool EnleveUnite(unsigned int numCase);
	bool AjouteUnite(unsigned int numCase, Unite* unite);

	std::string toString();
	std::string decalChateau(size_t decalage, std::string chateau);
	std::string deuxChateaux(size_t decalage, std::string chateau);

}Plateau_t;
