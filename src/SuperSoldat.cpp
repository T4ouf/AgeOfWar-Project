#include "SuperSoldat.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

unsigned int SuperSoldat::ID = 0;
SuperSoldat* SuperSoldat::instance=nullptr;

SuperSoldat* SuperSoldat::getInstance()
{
    if (instance == 0)
    {
        instance = new SuperSoldat();
    }

    return instance;
}



SuperSoldat::SuperSoldat(){
	ID = ID +1;
}
SuperSoldat::~SuperSoldat(){
    delete instance;
}


std::string SuperSoldat::getNom() {
	return "SuperSoldat"+ID;
}
EnumAction SuperSoldat::getAction1(){
	return Attaquer;
}
EnumAction SuperSoldat::getAction2() {
	return Avancer;
}
EnumAction SuperSoldat::getActionAlt() {
	return Attaquer;
}

unsigned int SuperSoldat::getPrix(){
	return 0;
}
unsigned int SuperSoldat::getVieMax() {
	return 10;
}
unsigned int SuperSoldat::getPuissance() {
	return 4;
}

unsigned int SuperSoldat::getPorteeMin() {
	return 1;
}
unsigned int SuperSoldat::getPorteeMax() {
	return 1;
}

unsigned int SuperSoldat::getCaseSuppDegats(){
	return 0;
}

int SuperSoldat::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){
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


Categorie* SuperSoldat::promotion(){
	return SuperSoldat::getInstance();
}
