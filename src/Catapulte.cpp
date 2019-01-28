#include "Catapulte.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

#include <iostream>

//ID pour numeroté le nombre de catapulte
unsigned int Catapulte::ID = 0;

//Catapulte est un singleton
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

//destruction le singleton
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

// on verifie si on peut attaquer une case supplementaire
unsigned int Catapulte::getCaseSuppDegats(){
	return 1;
}

// on verifie si il y a des ennemis a portée, et on renvoie l'indice du premier
int Catapulte::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){

	if (e==EquipeA){
		for(unsigned int i=positionActuelle; i<=TAILLE_PLATEAU; i++){
		
			//si la case n'est pas vide et dans la portée de la catapulte
			if((p.getCase(i)!=nullptr)  && (p.getCase(i)->getEquipe()==EquipeB && i>=(positionActuelle + getPorteeMin()) && i<=(positionActuelle + getPorteeMax()))){
				return i;
				
			}
			// si une case plus loin que la portée est un ennemi, on attaque la case avant
			else if((positionActuelle+getPorteeMax()+1<=TAILLE_PLATEAU)&&(p.getCase(positionActuelle+getPorteeMax()+1)!=nullptr)&& (p.getCase(positionActuelle+getPorteeMax()+1)->getEquipe()==EquipeB)){
				return positionActuelle+getPorteeMax();
				
			}
			//si c'est une base a portée
			else if ((p.getCase(i)==nullptr) && (i==BASE_B) && i>=(positionActuelle + getPorteeMin()) && i<=(positionActuelle + getPorteeMax())){
				return BASE_B;
			}else if ((positionActuelle+getPorteeMax()+1<=TAILLE_PLATEAU)&&(p.getCase(positionActuelle+getPorteeMax()+1)==nullptr) && ( positionActuelle+getPorteeMax()+1 ==BASE_B)){
				return positionActuelle+getPorteeMax();
			}
		}
	}
	else if (e==EquipeB){
		for(int i=(int)positionActuelle-(int)getPorteeMin(); (int)i>=((int)positionActuelle)-(int)getPorteeMax(); i--){
	
			//si on sort tu tableau, on a pas rencontré d'unité
			if(((int)positionActuelle)-(int)getPorteeMax()<0){
			return -1;
			}
			
			if((p.getCase(i)!=nullptr)  && (p.getCase(i)->getEquipe()==EquipeA) && i>=(int)(positionActuelle - getPorteeMax()) && i<=(int)(positionActuelle -getPorteeMin())){
				return i;
				
			}
			//On cherche pour d'éventuel dégat collatéral
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

//on return le singleton vers lequel on peut evoluer
Categorie* Catapulte::promotion(){
	return Catapulte::getInstance();
}

std::string Catapulte::genNom(){
	ID = ID+1;
	std::string nom = "C"+std::to_string(ID);
	return nom;
}

//methode pour reset l'id
void Catapulte::resetID(){ID=0;}