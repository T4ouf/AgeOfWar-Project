#include "Archer.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

#include <iostream>

//ID pour numeroté le nombre d'archer
unsigned int Archer::ID = 0;

//Archer est un singleton
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

//destruction le singleton
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
// on verifie si on peut attaquer une case supplementaire
unsigned int Archer::getCaseSuppDegats(){
	return 0;
}

// on verifie si il y a des ennemis a porté, et on renvoie l'indice du premier
int Archer::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){

	if (e==EquipeA){

		for(unsigned int i=positionActuelle; i<=TAILLE_PLATEAU; i++){
		
			//si la case n'est pas vide et dans la portée de l'archer
			if((p.getCase(i)!=nullptr)  && (p.getCase(i)->getEquipe()==EquipeB && i>=(positionActuelle + getPorteeMin()) && i<=(positionActuelle + getPorteeMax()))){
				return i;
				
			}
			//si c'est une base a portée
			else if ((p.getCase(i)==nullptr) && (i==BASE_B) && i>=(positionActuelle + getPorteeMin()) && i<=(positionActuelle + getPorteeMax())){
				return BASE_B;
			}
		}
	}
	else if (e==EquipeB){

		for(unsigned int i=positionActuelle; (int)i>=((int)positionActuelle)-(int)getPorteeMax(); i--){
	
			//si on sort tu tableau, on a pas rencontré d'unité
			if(((int)positionActuelle)-(int)getPorteeMax()<0){
			return -1;
			}
			
			
			if((p.getCase(i)!=nullptr)  && (p.getCase(i)->getEquipe()==EquipeA) && i>=(positionActuelle - getPorteeMin()) && i<=(positionActuelle -getPorteeMax())){
				return i;
				
			}else if ((p.getCase(i)==nullptr) && (i==BASE_A)){
				return BASE_A;
			}
		}
	}

	return -1;
}

//on return le singleton vers lequel on peut evoluer
Categorie* Archer::promotion(){
	return Archer::getInstance();
}


std::string Archer::genNom(){
	ID = ID+1;
	std::string nom = "A"+std::to_string(ID);
	return nom;
}
