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

const size_t TOURS_MAX=100;

void Init();
bool VerifFinPartie();

void resetRand(int mode);       //Fonction qui permet de "moduler" l'aleatoire, utile pour les test notamment
unsigned int tirage(unsigned int limite_min, unsigned int limite_max);
