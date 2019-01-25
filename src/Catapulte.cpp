#include "Catapulte.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

#include <iostream>

unsigned int Catapulte::ID = 0;
Catapulte* Catapulte::instance=nullptr;

Catapulte* Catapulte::getInstance()
{
    if (instance == 0)
    {
        instance = new Catapulte();
    }

    return instance;
}

Catapulte::Catapulte(){
	
}
Catapulte::~Catapulte(){
    delete instance;
}


std::string Catapulte::getNom() {
	return "C"+ std::to_string(ID);
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

unsigned int Catapulte::getCaseSuppDegats(){
	return 1;
}

int Catapulte::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){

	if (e==EquipeA){
		for(unsigned int i=positionActuelle; i<TAILLE_PLATEAU; i++){
		std::cout<<"min : "<< (i>=(positionActuelle + getPorteeMin())) << " max : "<<(i<= (positionActuelle + getPorteeMax()))<<std::endl;
			//case vide => on passe à la suivante
			if((p.getCase(i)!=nullptr)  && (p.getCase(i)->getEquipe()==EquipeB && i>=(positionActuelle + getPorteeMin()) && i<=(positionActuelle + getPorteeMax()))){
				return i;
				
			}
			else if((positionActuelle+getPorteeMax()+1<=TAILLE_PLATEAU)&&(p.getCase(positionActuelle+getPorteeMax()+1)!=nullptr)&& (p.getCase(positionActuelle+getPorteeMax()+1)->getEquipe()==EquipeB)){
				return positionActuelle+getPorteeMax();
				
			}else if ((p.getCase(i)==nullptr) && (i==BASE_B)){
				return BASE_B;
			}else if ((positionActuelle+getPorteeMax()+1<=TAILLE_PLATEAU)&&(p.getCase(positionActuelle+getPorteeMax()+1)==nullptr) && ( positionActuelle+getPorteeMax()+1 ==BASE_B)){
				return positionActuelle+getPorteeMax();
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
				
			}
			else if( (((int)positionActuelle-(int)getPorteeMax()-1)>=0)
			&&(p.getCase((int)positionActuelle-(int)getPorteeMax()-1)!=nullptr)
			&& (p.getCase((int)positionActuelle-(int)getPorteeMax()-1)->getEquipe()==EquipeA)){
				return positionActuelle-getPorteeMax();
				
			}else if ((p.getCase(i)==nullptr) && (i==BASE_A)){
				return BASE_A;
			}else if (((int)positionActuelle-(int)getPorteeMax()-1>=0)&&(p.getCase((int)positionActuelle-(int)getPorteeMax()-1)==nullptr) && ( (int)positionActuelle-(int)getPorteeMax()-1 ==BASE_A)){
				return positionActuelle-getPorteeMax();
			}
		}
	}

	return -1;
}

Categorie* Catapulte::promotion(){
	return Catapulte::getInstance();
}

std::string Catapulte::genNom(){
	ID = ID+1;
	std::string nom = "C"+std::to_string(ID);
	return nom;
}
