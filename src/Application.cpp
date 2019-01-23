#include "Application.hpp"

#include <time.h>	// pour la fonction time()
#include <stdlib.h>	// pour les fonctions srand et rand



extern bool FIN_JEU;
extern size_t NumTour;


/**
 * Fonction qui initialise l'application (création et initialisation des objets nécessaires au jeu)
 * @param rien...
 * @return rien...
 */
void Init(){

	resetRand(0);
}


bool VerifFinPartie(){

	if(NumTour<=TOURS_MAX){

		return FIN_JEU;
	}

	return true;
}

/**
 * Fonction qui genere l'aleatoire
 * @param mode, le mode de generation de l'aleatoire (0 -> fixe, 1 -> pseudo aleatoire)
 * @return rien...
 */
void resetRand (int mode) { srand(mode ? time(0) : 1); }        //Fonction qui permet de "moduler" l'aleatoire, utile pour les test notamment


/**
 * Fonction qui tire un nombre pseudo-aleatoire (selon resetRand) entre limite_min et limite_max
 * @param limite_min, la limite inferieure pour le tirage
 * @param limite_max, la limite superieure pour le tirage
 * @return l'entier tire
 */
unsigned int tirage( unsigned int limite_min, unsigned int limite_max) {
	
  	return (limite_min+(rand() % (limite_max+1-limite_min))) ;
}
