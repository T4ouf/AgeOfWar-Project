#include "Archer.hpp"
#include "Enums.hpp"
#include "Unite.hpp"


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
	ID = ID +1;
}

Archer::~Archer(){
    delete instance;
}

std::string Archer::getNom(){
	return "Archer"+ID;
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
	return 10;
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
			if(p.getCase(i)->getEquipe()==EquipeB && i>=getPorteeMin() && i<=getPorteeMax()){
				return i;
			}
		}
	}
	else{
		for(unsigned int i=positionActuelle; i>TAILLE_PLATEAU; i--){
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
