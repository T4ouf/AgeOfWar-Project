#pragma once

#include "Archer.hpp"
#include "Catapulte.hpp"
#include "Fantassin.hpp"
#include "SuperSoldat.hpp"


/* METTRE LE PLATEAU DANS UN FICHIER SEPARE DE L'APPLICATION ? */

class _Application{

public:
	//On crée ici les singletons de categorie (que l'on initialisera via _Init())
	/*Archer archer;
	Catapulte catapulte;
	Fantassin fantassin; 
	SuperSoldat super_soldat;*/

	//fonctions qui commencent par _ sont les fonctions de l'application
	void _Init();

};

