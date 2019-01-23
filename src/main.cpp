#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <sstream>

#include "Application.hpp"

size_t NumTour = 0;
bool FIN_JEU = false;

extern const size_t TOURS_MAX;

#define Affiche_Joueur1() std::cout << '\n' << ColorerTexte("Joueur 1 :",Souligne,COULEUR_EQUIPE_A) << ColorerTexte("\n\tPieces : ",Gras,Jaune) << J1.getArgent()\
			<< "\n\t" << ColorerTexte("Base : ",Gras,Jaune)  << J1.getTour().getVie() << '/' << VIE_TOUR << "\n"

#define Affiche_Joueur2() std::cout << '\n' << ColorerTexte("Joueur 2 :",Souligne,COULEUR_EQUIPE_B) << ColorerTexte("\n\tPieces : ",Gras,Jaune) << J2.getArgent()\
			<< "\n\t" << ColorerTexte("Base : ",Gras,Jaune) << J2.getTour().getVie() << '/' << VIE_TOUR << "\n"


int main(){


	Joueur J1 = Joueur(EquipeA,false);
	Joueur J2= Joueur(EquipeB, true);

	Plateau_t plateau;	
	plateau.Init(J1.refTour(),J2.refTour());

	Init();

	while(!VerifFinPartie()){

		

		/*std::cout << "\t \t||\tBase1\t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\tBase2\t||"<<std::endl;
		std::cout << "Unité de :\t||\tJoueur1\t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\tJoueur2\t||"<<std::endl;
		std::cout << "Type Unité :\t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||"<<std::endl;
		std::cout << "Type Unité :\t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||"<<std::endl;
		std::cout << "point vie :\t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||\t \t||"<<std::endl;
		*/

		
		//On efface la console
		//system("clear");

		std::stringstream sstm;
		sstm << "\nTour : " << NumTour << "/" << TOURS_MAX << "\t\tF = Fantassin\tA = Archer\tC = Catapulte\tS = Super Soldat\n";
		std::cout << '\n' << ColorerTexte(sstm.str(), Gras, Fond_NoirClair) << "\n";
		
		if((NumTour%2)==0){
			//Gain de 8 pièces en début de tour
			J1.MAJPieces(8);
			Affiche_Joueur1();
			std::cout << '\n' << plateau.toString();

			std::string commande = "";
			std::cout << "\nEntrez le nom de l'unité que vous souhaitez recruter : ";
			std::cin >> commande;

			switch(toupper(commande.at(0))) {
				case 'F' : 	J1.recruter(plateau, Fantassin::getInstance());
			    			break;
			    case 'A' : 	J1.recruter(plateau, Archer::getInstance());
			    			break;
			    case 'C' : 	J1.recruter(plateau, Catapulte::getInstance());
			    			break;
			}

			J1.Jouer(plateau);
		}
		else{
			//Gain de 8 pièces en début de tour
			J2.MAJPieces(8);
			Affiche_Joueur2();
			std::cout << '\n' << plateau.toString();
			
			if(J2.EstIA()){
				int actionIA = tirage(0,2);

				//On ne peut agir que si la case est libre
				if(plateau.getCase(BASE_B)==nullptr){
					
					//Les recrues de l'IA sont aléatoires
					//cependant s'il n'a pas l'argent nécéssaire, il essayera d'acheter une unité moins chère

					if(actionIA==0){
						
						bool OK = J2.recruter(plateau,Catapulte::getInstance());

						if(!OK){
							bool OK2 = J2.recruter(plateau,Archer::getInstance());

							if(!OK2){
								J2.recruter(plateau,Fantassin::getInstance());
							}

						}


					}
					else if(actionIA==1){
						
						bool OK = J2.recruter(plateau,Archer::getInstance());

						if(!OK){
							J2.recruter(plateau,Fantassin::getInstance());
						}


					}
					else if(actionIA==2){
						
						J2.recruter(plateau,Fantassin::getInstance());

					}
				}


				J2.Jouer(plateau);
					
			}
		}

		NumTour++;
	}

	return 0;

}
