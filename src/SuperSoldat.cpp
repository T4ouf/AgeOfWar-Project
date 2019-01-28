#include "SuperSoldat.hpp"
#include "Enums.hpp"
#include "Unite.hpp"

//ID pour numeroté le nombre de super soldat
unsigned int SuperSoldat::ID = 0;

//SuperSoldat est un singleton
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

}

//destruction le singleton
SuperSoldat::~SuperSoldat(){
    delete instance;
}


std::string SuperSoldat::getNom() {
	return "S" + std::to_string(ID);
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

// on verifie si on peut attaquer une case supplementaire
unsigned int SuperSoldat::getCaseSuppDegats(){
	return 0;
}

// on verifie si il y a des ennemis a porté, et on renvoie l'indice du premier
int SuperSoldat::verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e){

	if (e==EquipeA){

		for(unsigned int i=positionActuelle; i<=TAILLE_PLATEAU; i++){
		
			//si la case n'est pas vide et dans la portée du supersoldat
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
			
			
			if((p.getCase(i)!=nullptr)  
				&& (p.getCase(i)->getEquipe()==EquipeA )
					&& i>=(positionActuelle - getPorteeMin()) 
					&& i<=(positionActuelle -getPorteeMax())){
				return i;
				
			}else if ((p.getCase(i)==nullptr) && (i==BASE_A)){
				return BASE_A;
			}
		}
	}

	return -1;
}

//on return le singleton vers lequel on peut evoluer
Categorie* SuperSoldat::promotion(){
	return SuperSoldat::getInstance();
}


std::string SuperSoldat::genNom(){
	ID = ID+1;
	std::string nom = "S"+std::to_string(ID);
	return nom;
}

//methode pour reset l'id
void SuperSoldat::resetID(){ID=0;}