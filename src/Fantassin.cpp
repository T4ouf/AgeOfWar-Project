#include "Fantassin.hpp"
#include "SuperSoldat.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

#include <iostream>

//ID pour numeroté le nombre de fantassin
unsigned int Fantassin::ID = 0;

//Fantassin est un singleton
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

//destruction le singleton
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

// on verifie si on peut attaquer des cases supplementaires
unsigned int Fantassin::getCaseSuppDegats(){
	return 0;
}

// on verifie si il y a des ennemis a porté, et on renvoie l'indice du premier
int Fantassin::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){

	if (e==EquipeA){
		for(unsigned int i=positionActuelle; i<=TAILLE_PLATEAU; i++){
			
			//si la case n'est pas vide et dans la portée du fantassin
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
		
		
		for(unsigned int i=positionActuelle; (int)i>=((int)positionActuelle)-(int)getPorteeMax()-1; i--){
			//si on sort tu tableau, on a pas rencontré d'unité
			if(((int)positionActuelle)-(int)getPorteeMax()<0){
			return -1;
			}
			
			
			if( (p.getCase(i)!=nullptr)  
				&& (p.getCase(i)->getEquipe()==EquipeA )&& i>=(positionActuelle - getPorteeMin()) && i<=(positionActuelle -getPorteeMax())){
				return i;
				
			}else if ((p.getCase(i)==nullptr) && (i==BASE_A)){
				return BASE_A;
			}

		}
	}


	return -1;
}

//on returne le singleton vers lequel on peut evoluer
Categorie* Fantassin::promotion(){
	return SuperSoldat::getInstance();
}

std::string Fantassin::genNom(){
	ID = ID+1;
	std::string nom = "F"+std::to_string(ID);
	return nom;
}
