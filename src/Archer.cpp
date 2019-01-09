#include "Archer.hpp"
#include "Enums.hpp"

unsigned int Archer::ID = 0;

Archer::Archer(){
		ID = ID +1;
}

Archer::~Archer(){

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

int Archer::verifPortee(Plateau_t p, unsigned int positionActuelle, int direction, EnumEquipe e){

	if (e==EquipeA){
		for(int i=positionActuelle; i<TAILLE_TABLEAU; i+direction){
			if(p.getCase(i).getEquipe()==EquipeB && i>=getPorteeMin() && i<=getPorteeMax()){
				return i;
			}
		}
	}
	else{
		for(int i=positionActuelle; i>TAILLE_TABLEAU; i+direction){
			if(p.getCase(i).getEquipe()==EquipeA && i>=(positionActuelle - getPorteeMin()) && i<=(positionActuelle - getPorteeMax())){
				return i;
			}
		}
	}
	
	return positionActuelle;
}
