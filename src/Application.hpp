#pragma once

#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Tour.hpp"
#include "Entite.hpp"
#include "Unite.hpp"
#include "Enums.hpp"
#include "Categorie.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include "Fantassin.hpp"
#include "SuperSoldat.hpp"

const size_t TOURS_MAX=200;

struct Application{

	void Init();
	bool VerifFinPartie();

	//Fonction de sauvegarde de l'état du jeu 
	void Sauvegarder(std::string nomFichier, Joueur& J1, Joueur& J2, Plateau_t& plateau);

	//Fonction de chargement d'une sauvegarde
	bool Charger(std::string nomFichier, Joueur& J1, Joueur& J2, Plateau_t& plateau);

};


void resetRand(int mode);       //Fonction qui permet de "moduler" l'aleatoire, utile pour les test notamment
unsigned int tirage(unsigned int limite_min, unsigned int limite_max);