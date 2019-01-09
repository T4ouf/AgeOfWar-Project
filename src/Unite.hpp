#pragma once

#include "Categorie.hpp"
#include "Entite.hpp"
#include "Enums.hpp"
#include "Plateau.hpp"

class Unite: public Entite{

private:

	EnumAction m_actions[2];
	EnumAction m_actionAlternative;	//Correspond à l'action 3 du tableau => ne se déclenche (après l'action 2) que si l'action 1 est impossible

	Categorie* m_categorie;

	std::string m_nom;			//Correspond au nom de l'unité (pour l'affichage sur la console)

	unsigned int prix;
	unsigned int vieMax;		//Correspond à la vie max de l'unité / Les points de vie actuels de l'unité sont gérés au niveau de la classe Entite
	unsigned int puissance; 	//représente les points d'attaque du sujet

	//Portee de l'unite (bornes comprises)
	unsigned int m_porteeMin;
	unsigned int m_porteeMax;

public:

	//Constructeur d'une unite
	//en C++ le polymorphisme passe par des pointeurs
	Unite(Categorie* categorie, EnumEquipe equipe);

	//méthode d'attaque d'une unite (renvoit vrai si l'attaque est un succès, faux sinon)
	bool Attaquer(Plateau_t& p);

	//Méthode de déplacement d'une unité (renvoit vrai si le déplacement est un succès, faux sinon)
	bool Deplacer(Plateau_t& p);

	bool Promotion();

};
