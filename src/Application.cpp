#include "Application.hpp"

#include <time.h>	// pour la fonction time()
#include <stdlib.h>	// pour les fonctions srand et rand

#include <fstream>  //Pour écrire dans un fichier texte
#include <sstream>  //Pour concaténer des chaines aisément + gestion des flux
#include <iostream>

extern bool FIN_JEU;
extern size_t NumTour;

/**
 * Fonction qui initialise l'application (création et initialisation des objets nécessaires au jeu)
 * @param rien...
 * @return rien...
 */
void Application::Init(){

	resetRand(0);
}

/**
 * Fontion qui vérifie si le jeu est fini
 * @param rien...
 * @return un booléen indiquant si la partie est finie (true) ou non
 */
bool Application::VerifFinPartie(){

	if(NumTour<=TOURS_MAX){

		return FIN_JEU;
	}

	return true;
}

/**
 * Fonction qui genere l'aleatoire
 * @param mode, le mode de generation de l'aleatoire (0 -> fixe, 1 -> pseudo aleatoire)
 * @return rien...
 */
void resetRand (int mode) { srand(mode ? time(0) : 1); }        //Fonction qui permet de "moduler" l'aleatoire, utile pour les test notamment


/**
 * Fonction qui tire un nombre pseudo-aleatoire (selon resetRand) entre limite_min et limite_max
 * @param limite_min, la limite inferieure pour le tirage
 * @param limite_max, la limite superieure pour le tirage
 * @return l'entier tire
 */
unsigned int tirage( unsigned int limite_min, unsigned int limite_max) {
	
  	return (limite_min+(rand() % (limite_max+1-limite_min))) ;
}


/**
 * Fontion qui sauvegarde l'état du jeu
 * @param nomFichier, le nom du fichier de sauvegarde
 * @param J1, le joueur 1 (dont on doit sauvegarder l'état)
 * @param J2, le joueur 2 (dont on doit sauvegarder l'état)
 * @param plateau, le plateau (dont on doit sauvegarder l'état)
 * @return rien...
 */
void Application::Sauvegarder(std::string nomFichier, Joueur& J1, Joueur& J2, Plateau_t& plateau){

	//Ici on sauvegarde selon un format que l'on défini nous même

	plateau=plateau;

	std::stringstream s;
	s << NumTour << '\n';
	s <<  J1.m_nom << " " << J1.m_piecesOr << " " << J1.m_ia << " " << J1.m_tour.getVie() << " " << J1.m_listeUnite.size() <<"\n";

	for(size_t i =0; i<J1.m_listeUnite.size();i++){
		Unite* unite = J1.m_listeUnite.at(i);
		s << unite->getNom() << " " << unite->getVie() << " " << unite->getEquipe() << " " << unite->getX() << "\n";
	}

	s << "\n";

	s <<  J2.m_nom << " " << J2.m_piecesOr << " " << J2.m_ia << " " << J2.m_tour.getVie() << " " << J2.m_listeUnite.size() <<"\n";

	for(size_t i =0; i<J2.m_listeUnite.size();i++){
		Unite* unite = J2.m_listeUnite.at(i);
		s << unite->getNom() << " " << unite->getVie() << " " << unite->getEquipe() << " " << unite->getX() << "\n";
	}

	//Creation du fichier.txt (on l'efface s'il existe déjà (pour éviter les erreurs))
	std::ofstream sauvegarde(nomFichier+".lol", std::ios::trunc);        
    sauvegarde << s.str();                              //On ajoute la sauvegarde au fichier
    sauvegarde.close();                                //On ferme le fichier
}


//Fonction de chargement d'une sauvegarde
bool Application::Charger(std::string nomFichier, Joueur& J1, Joueur& J2, Plateau_t& plateau){

	std::ifstream f(nomFichier+".lol", std::ios::in);        //On ouvre le fichier de sauvegarde en mode lecture


    if (f){                                          //Si on a réussi à ouvrir le fichier...
        std::cout << "Ouverture du fichier reussie !\n"; //On le dit
    }
    else{                                           //Sinon, on sort directement de la fonction
        std::cerr << "ERREUR ! Lecture impossible !\n";
        return false;
    }



    //On reinitialise le plateau
    plateau.Init(J1.refTour(), J2.refTour(),false);

	f >> NumTour;	//On met le tour à la bonne valeur

    f >> J1.m_nom;     				// la 1ere valeur est le nom du joueur
    f >> J1.m_piecesOr;            	// la 2e valeur est l'argent du joueur
    f >> J1.m_ia;            		// la 3e valeur est le booléen indiquant si le joueur est une IA
    f >> J1.m_tour.m_vie;			// la 4e valeur représente la vie de la tour
    size_t nbUnit = 0;
   	f >> nbUnit;

    for(size_t i=0; i<nbUnit;i++){
    	std::string nom = "";
    	f >> nom;

		unsigned int vie = 0;
		f >> vie;
		int e;	//représente la valeur de l'énum de l'équipe
		f >> e;

		unsigned int x = 0;
		f >> x;

		Categorie* c;

		switch(toupper(nom.at(0))) {
			case 'F' : 	c=Fantassin::getInstance();
		    			break;
		    case 'A' :	c=Archer::getInstance();
		    			break;
		    case 'C' : 	c=Catapulte::getInstance();
		    			break;
		    case 'S' : 	c=SuperSoldat::getInstance();
		    			break;
		}

		J1.recruter(plateau,c, x);
		J1.m_listeUnite.at(i)->m_x=x;

    }


    f >> J2.m_nom;     				// la 1ere valeur est le nom du joueur
    f >> J2.m_piecesOr;            	// la 2e valeur est l'argent du joueur
    f >> J2.m_ia;            		// la 3e valeur est le booléen indiquant si le joueur est une IA
    f >> J2.m_tour.m_vie;			// la 4e valeur représente la vie de la tour
	size_t nbUnit2 = 0;
   	f >> nbUnit2;

    for(size_t i=0; i<nbUnit2;i++){
    	std::string nom = "";

    	f >> nom;

		unsigned int vie = 0;
		f >> vie;
		int e;	//représente la valeur de l'énum de l'équipe
		f >> e;

		unsigned int x = 0;
		f >> x;

		Categorie* c;

		switch(toupper(nom.at(0))) {
			case 'F' : 	c=Fantassin::getInstance();
		    			break;
		    case 'A' :	c=Archer::getInstance();
		    			break;
		    case 'C' : 	c=Catapulte::getInstance();
		    			break;
		    case 'S' : 	c=SuperSoldat::getInstance();
		    			break;
		}

		J2.recruter(plateau,c, x);
		J2.m_listeUnite.at(i)->m_x=x;
    }
    
    f.close(); //on ferme le fichier

    return true;

}