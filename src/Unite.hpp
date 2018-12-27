#pragma once

#include "Categorie.hpp"
#include "Entite.hpp"
#include "Enums.hpp"


class Unite: public Entite{

private:

	EnumAction m_actions[2];
	EnumAction m_actionAlternative;	//Correspond à l'action 3 du tableau => ne se déclenche (après l'action 2) que si l'action 1 est impossible

	Categorie* m_categorie;

	unsigned int prix;
	unsigned int vieMax;	//Correspond à la vie max de l'unité / Les points de vie actuels de l'unité sont gérés au niveau de la classe Entite
	unsigned int puissance; 	//représente les points d'attaque du sujet

	unsigned int m_porteeMin;
	unsigned int m_porteeMax;

public:

	Unite(Categorie* categorie, EnumEquipe equipe);

};