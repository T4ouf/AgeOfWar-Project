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
	virtual unsigned int getCaseSuppDegats() = 0;
	virtual int verifPortee(Plateau_t p, unsigned int positionActuelle, EnumEquipe e)=0;

	virtual Categorie* promotion()=0;
	
	virtual std::string genNom() = 0; 
	


};
