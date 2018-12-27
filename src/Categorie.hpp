#pragma once 

#include <string>
#include "Enums.hpp"

/** Classe qui représente la catégorie d'une unité (on utilise ici le design Pattern State)
 * @author 
 *
 */
class Categorie{

private:

	std::string m_nom;
	
protected:
	//Méthode abstraite qui doit être redef dans les classes filles (chaque sous-classe gère son nommage)
	virtual void setNom(std::string nom) = 0;	

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


};