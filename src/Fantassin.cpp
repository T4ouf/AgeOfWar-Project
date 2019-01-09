#include "Fantassin.hpp"
#include "Enums.hpp"

unsigned int Fantassin::ID = 0;

Fantassin::Fantassin(){
	ID = ID +1;
}
Fantassin::~Fantassin(){

}


std::string Fantassin::getNom() {
	return "Fantassin"+ID;
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

int SuperSoldat::verifPortee(Plateau_t p, unsigned int positionActuelle, int direction){
	if (e==EquipeA){
		if(p.getCase(positionActuelle+getPorteeMin()==EquipeB){
			return (positionActuelle+getPorteeMin());
		}
	}else{
		if(p.getCase(positionActuelle-getPorteeMin()==EquipeA){
			return (positionActuelle+getPorteeMin());
		}
	}
	return positionActuelle;
}
