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

Categorie* Archer::promotion(){
	return Archer::getInstance();
}


std::string Archer::genNom(){
	ID = ID+1;
	std::string nom = "A"+std::to_string(ID);
	return nom;
}
