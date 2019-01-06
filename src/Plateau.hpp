#pragma once

#include <vector>

#define TAILLE_PLATEAU 11

//Pour eviter les inclusions multiples
class Unite;

typedef struct{

	std::vector<Unite> casesUnite;

	bool VerifOK(unsigned int numCase){
		return numCase<=TAILLE_PLATEAU;
	}

}Plateau_t;