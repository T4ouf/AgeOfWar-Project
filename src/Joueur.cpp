#include "Joueur.hpp"
#include "Unite.hpp"


Joueur::Joueur(EnumEquipe equipe, bool IA) : m_equipe(equipe), m_tour(Tour(equipe)), m_piecesOr(OR_INITIAL), m_ia(IA){

}


void Joueur::EnleveUnite(Unite* u){
	//TODO
}