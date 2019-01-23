#include "Tour.hpp"
#include "Enums.hpp"

extern bool FIN_JEU;

Tour::Tour(EnumEquipe equipe) : Entite(VIE_TOUR,equipe){
}

Tour::~Tour(){}


//Gère la mort de l'unité (préviens le plateau et détruit l'objet)
void Tour::Mourir(Plateau_t& p){

	//pour éviter le warning de paramètre inutile
	p.getCase(0);

	//La mort d'une tour entraine la fin du jeu
	FIN_JEU=true;

}

unsigned int Tour::getPrix(){return 0;}