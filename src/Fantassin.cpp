#include "Fantassin.hpp"
#include "SuperSoldat.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

#include <iostream>

unsigned int Fantassin::ID = 0;
Fantassin* Fantassin::instance=nullptr;

Fantassin* Fantassin::getInstance()
{
    if (instance == 0)
    {
        instance = new Fantassin();
    }

    return instance;
}

Fantassin::Fantassin(){
	ID = ID +1;
}
Fantassin::~Fantassin(){
    delete instance;
}


std::string Fantassin::getNom() {
	return "F" + std::to_string(ID);
}
EnumAction Fantassin::getAction1(){
	return Attaquer;
}
EnumAction Fantassin::getAction2() {
	return Avancer;
}
EnumAction Fantassin::getActionAlt() {
	return Attaquer;
}

unsigned int Fantassin::getPrix(){
	return 10;
}
unsigned int Fantassin::getVieMax() {
	return 10;
}
unsigned int Fantassin::getPuissance() {
	return 4;
}

unsigned int Fantassin::getPorteeMin() {
	return 1;
}
unsigned int Fantassin::getPorteeMax() {
	return 1;
}

unsigned int Fantassin::getCaseSuppDegats(){
	return 0;
}

int Fantassin::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){

	std::cout << "\n\nINVerif : " <<positionActuelle+ direction(e)*getPorteeMin();

	// Cas de la case vide devant l'unité
	if(p.getCase(positionActuelle+ direction(e)*getPorteeMin())==nullptr){

		std::cout << positionActuelle+ direction(e)*getPorteeMin();

		//Si on est à portée de la tour => on l'attaque
		if((positionActuelle+ direction(e)*getPorteeMin())==(unsigned int)positionTourAdverse(e)){
			return positionTourAdverse(e);
		}

		return -1;
	}

	if (e==EquipeA){
		if(p.getCase(positionActuelle+getPorteeMin())->getEquipe()==EquipeB){
			return (positionActuelle+getPorteeMin());
		}
	}else{
		if(p.getCase(positionActuelle-getPorteeMin())->getEquipe()==EquipeA){
			return (positionActuelle+getPorteeMin());
		}
	}
	return -1;
}

Categorie* Fantassin::promotion(){
	return SuperSoldat::getInstance();
}
