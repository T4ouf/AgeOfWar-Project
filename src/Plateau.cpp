#include "Plateau.hpp"
#include "Unite.hpp"

	void Plateau_t::Init(){
		for(unsigned int i=0; i<TAILLE_PLATEAU; i++){
			//init le plateau avec des cases vides
			casesUnite.push_back(nullptr);
		}
	}

	bool Plateau_t::VerifOK(unsigned int numCase){
		return numCase<=TAILLE_PLATEAU;
	}

	Unite* Plateau_t::getCase(unsigned int numCase){
		//renverra le bon type sauf exception (index out of bound)
		return (casesUnite.at(numCase));
	}
