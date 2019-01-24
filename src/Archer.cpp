#include "Archer.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

#include <iostream>

unsigned int Archer::ID = 0;
Archer* Archer::instance=nullptr;

Archer* Archer::getInstance()
{
    if (instance == 0)
    {
        instance = new Archer();
    }

    return instance;
}

Archer::Archer(){

}

Archer::~Archer(){
    delete instance;
}

std::string Archer::getNom(){
	return "A" + std::to_string(ID);
}

EnumAction Archer::getAction1(){
	return Attaquer;
}

EnumAction Archer::getAction2(){
	return Avancer;
}

EnumAction Archer::getActionAlt(){
	return Vide;
}


unsigned int Archer::getPrix(){
	return 12;
}
unsigned int Archer::getVieMax() {
	return 8;
}
unsigned int Archer::getPuissance() {
	return 3;
}

unsigned int Archer::getPorteeMin() {
	return 1;
}

unsigned int Archer::getPorteeMax() {
	return 3;
}

unsigned int Archer::getCaseSuppDegats(){
	return 0;
}

int Archer::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){

	if (e==EquipeA){

		for(unsigned int i=positionActuelle; i<TAILLE_PLATEAU; i++){

			//case vide 
			if(p.getCase(i)==nullptr){
				//si on tombe sur la tour
				if(i==(unsigned int)positionTourAdverse(e)){
					return positionTourAdverse(e);
				}

				continue;
			}
			if(p.getCase(i)->getEquipe()==EquipeB && i>=getPorteeMin() && i<=getPorteeMax()){
				return i;
			}
		}
	}
	else{

		std::cout << "\npositionActuelle-3 = " << ((int)positionActuelle)-3 ;

		for(unsigned int i=positionActuelle; (int)i>=((int)positionActuelle)-3; i--){

			//case vide
			if(p.getCase(i)==nullptr){

				//si on tombe sur la tour
				std::cout << "\n\n\nIN\n" << i << "=" << positionTourAdverse(e);
				if(i==(unsigned int)positionTourAdverse(e)){
					return positionTourAdverse(e);
				}

				continue;
			}

			std::cout << "\n---------------------\nOUT0\n" <<  p.getCase(i)->getNom();
			
			if(p.getCase(i)->getEquipe()==EquipeA && i>=(positionActuelle - getPorteeMin()) && i<=(positionActuelle - getPorteeMax())){
				return i;
			}
		}
	}

	return -1;
}

Categorie* Archer::promotion(){
	return Archer::getInstance();
}


std::string Archer::genNom(){
	ID = ID+1;
	std::string nom = "A"+std::to_string(ID);
	return nom;
}
