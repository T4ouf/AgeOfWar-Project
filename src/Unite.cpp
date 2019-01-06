#include "Unite.hpp"

Unite::Unite(Categorie* categorie, EnumEquipe equipe) : Entite(categorie->getVieMax(),equipe){

	m_actions[0]=categorie->getAction1();
	m_actions[1]=categorie->getAction2();

	m_actionAlternative=categorie->getActionAlt();

	m_nom = categorie->getNom() + "(" + getNomEquipe(equipe) + ")";

	m_categorie = categorie;
}