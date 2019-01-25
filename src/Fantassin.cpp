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

	if (e==EquipeA){

		for(unsigned int i=positionActuelle; i<TAILLE_PLATEAU; i++){
		
			//case vide => on passe à la suivante
			if((p.getCase(i)!=nullptr)  && (p.getCase(i)->getEquipe()==EquipeB && i>=(positionActuelle + getPorteeMin()) && i<=(positionActuelle + getPorteeMax()))){
				return i;
				
			}
			else if ((p.getCase(i)==nullptr) && (i==BASE_B)){
				return BASE_B;
			}
		}
	}
	else if (e==EquipeB){

		for(unsigned int i=positionActuelle; (int)i>=((int)positionActuelle)-(int)getPorteeMax(); i--){
	
			if(((int)positionActuelle)-(int)getPorteeMax()<0){
			return -1;
			}
			
			//case vide => on passe à la suivante
			if((p.getCase(i)!=nullptr)  && (p.getCase(i)->getEquipe()==EquipeA && i>=getPorteeMin() && i<=getPorteeMax())){
				return i;
				
			}else if ((p.getCase(i)==nullptr) && (i==BASE_A)){
				return BASE_A;
			}
		}
	}

	return -1;
}

Categorie* Fantassin::promotion(){
	return SuperSoldat::getInstance();
}

std::string Fantassin::genNom(){
	ID = ID+1;
	std::string nom = "F"+std::to_string(ID);
	return nom;
}
