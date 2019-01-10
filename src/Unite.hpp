#pragma once

#include "Categorie.hpp"
#include "Entite.hpp"
#include "Enums.hpp"
#include "Plateau.hpp"
#include "Joueur.hpp"

class Unite: public Entite{

private:

	EnumAction m_actions[2];
	EnumAction m_actionAlternative;	//Correspond à l'action 3 du tableau => ne se déclenche (après l'action 2) que si l'action 1 est impossible

	Categorie* m_categorie;

	std::string m_nom;			//Correspond au nom de l'unité (pour l'affichage sur la console)

	Joueur* m_proprietaire;		//liaison de l'unité au Joueur proprietaire

public:

	//Constructeur d'une unite
	//en C++ le polymorphisme passe par des pointeurs
	Unite(Categorie* categorie, EnumEquipe equipe, Joueur* proprietaire);

	//méthode d'attaque d'une unite (renvoit vrai si l'attaque est un succès, faux sinon)
	bool Attaquer(Plateau_t& p);

	//Méthode de déplacement d'une unité (renvoit vrai si le déplacement est un succès, faux sinon)
	bool Deplacer(Plateau_t& p);

	//Gère la promotion de l'unité (verif de la condition + appel à methode promotion de la catégorie)
	bool Promotion();

	//Gère la mort de l'unité (préviens le plateau et détruit l'objet)
	void Mourir(Plateau_t& p) override;

};
