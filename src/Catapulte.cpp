#include "Catapulte.hpp"
#include "Enums.hpp"

unsigned int Catapulte::ID = 0;

Catapulte::Catapulte(){
	ID = ID +1;
}
Catapulte::~Catapulte(){

}


std::string Catapulte::getNom() {
	return "Catapulte"+ID;
}
EnumAction Catapulte::getAction1(){
	return Attaquer;
}
EnumAction Catapulte::getAction2() {
	return Vide;
}
EnumAction Catapulte::getActionAlt() {
	return Avancer;
}

unsigned int Catapulte::getPrix(){
	return 20;
}
unsigned int Catapulte::getVieMax() {
	return 12;
}
unsigned int Catapulte::getPuissance() {
	return 6;
}

unsigned int Catapulte::getPorteeMin() {
	return 2;
}
unsigned int Catapulte::getPorteeMax() {
	return 3;
}

unsigned int Catapulte::Catapulte::getCaseSuppDegats(){
	return 1;
}

int Archer::verifPortee(Plateau_t p, unsigned int positionActuelle, int direction, EnumEquipe e){

	if (e==EquipeA){
		for(int i=positionActuelle; i<TAILLE_TABLEAU; i+direction){
			if(p.getCase(i).getEquipe()==EquipeB && i>=getPorteeMin() && i<=getPorteeMax()){
				return i;
			}else if(p.getCase(positionActuelle+getPorteeMax()+1).getEquipe()==EquipeB){
				return positionActuelle+getPorteeMax()+1;
			}
		}
	}
	else{
		for(int i=positionActuelle; i>TAILLE_TABLEAU; i+direction){
			if(p.getCase(i).getEquipe()==EquipeA && i>=(positionActuelle - getPorteeMin()) && i<=(positionActuelle - getPorteeMax())){
				return i;
			}else if(p.getCase(positionActuelle-(getPorteeMax()+1)).getEquipe()==EquipeB){
				return positionActuelle-(getPorteeMax()+1);
			}
		}
	}
	
	return positionActuelle;
}
