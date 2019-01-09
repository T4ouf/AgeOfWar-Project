#pragma once

#include <string>
#include "Enums.hpp"

/** Classe abstraite qui représente la catégorie d'une unité (on utilise ici le design Pattern State)
 * @author
 *
 */
class Categorie{

	//LES CATEGORIES NE SERONT INSTANCIE QU'UNE SEULE FOIS DANS L'APPLICATION

private:

protected:
	//Méthode abstraite qui doit être redef dans les classes filles (chaque sous-classe gère son nommage)
	//virtual void setNom(std::string nom) = 0;

public:

	Categorie(){};
	~Categorie(){};

	//Méthodes abstraites qui doivent être redef dans les classes filles
	virtual std::string getNom() = 0;
	virtual EnumAction getAction1() = 0;
	virtual EnumAction getAction2() = 0;
	virtual EnumAction getActionAlt() = 0;

	virtual unsigned int getPrix()= 0;
	virtual unsigned int getVieMax()= 0;
	virtual unsigned int getPuissance()= 0;

	virtual unsigned int getPorteeMin()= 0;
	virtual unsigned int getPorteeMax()= 0;

/*FCT A AJOUTER DANS TOUTES LES SOUS CLASSES*/
	virtual unsigned int getCaseSuppDegats() = 0;

	//Méthode qui vérifie si une unité ennemie est à portée (et renvoit le numéro de la case à attaquer si c'est le cas (-1 sinon))
	virtual int verifPortee(Plateau_t p, unsigned int positionActuelle, int direction) = 0;

};
