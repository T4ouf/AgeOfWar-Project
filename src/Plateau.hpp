#pragma once

//#include <stdexcept>	//pour l'exception std::out_of_range
#include <vector>

#define TAILLE_PLATEAU 11

//Pour eviter les inclusions multiples
class Unite;

typedef struct{

	std::vector<Unite*> casesUnite;

	void Init();
	bool VerifOK(unsigned int numCase);
	Unite* getCase(unsigned int numCase);

}Plateau_t;