#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <sstream>

#include "Application.hpp"

size_t NumTour = 0;
bool FIN_JEU = false;

extern const size_t TOURS_MAX;

std::string recapitulatifTour = "";

#define Affiche_Joueur1(nom) std::cout << '\n' << ColorerTexte(nom +" :",Souligne,COULEUR_EQUIPE_A) << ColorerTexte("\n\tPieces : ",Gras,Jaune) << J1.getArgent()\
			<< "\n\t" << ColorerTexte("Base : ",Gras,Jaune)  << J1.getTour().getVie() << '/' << VIE_TOUR << "\n"

#define Affiche_Joueur2(nom) std::cout << '\n' << ColorerTexte(nom + " :",Souligne,COULEUR_EQUIPE_B) << ColorerTexte("\n\tPieces : ",Gras,Jaune) << J2.getArgent()\
			<< "\n\t" << ColorerTexte("Base : ",Gras,Jaune) << J2.getTour().getVie() << '/' << VIE_TOUR << "\n"

int main(){

	Application app;

	std::cout << "\n\n" <<ColorerTexte("\n\t\t\tAGE OF WAR PROJECT\nEurydice Ruggieri\t\t-\t\tThomas von Ascheberg\n", Gras, Fond_NoirClair);

	std::string reponse = "";

	std::string nomJ1="";
	bool IAJ1 = false;

	std::string nomJ2="";
	bool IAJ2 = false;

	Joueur J1 = Joueur(EquipeA,"Joueur1",IAJ1);
	Joueur J2= Joueur(EquipeB, "Joueur2",IAJ2);

	Plateau_t plateau;	
	plateau.Init(J1.refTour(),J2.refTour(),true);

	while(reponse == ""){
		std::cout << ColorerTexte("\n\nBienvenue dans Age of War !\nQue voulez vous faire ?", GrasSouligne,NoirClair) 
				  << "\n\n-Charger une partie " << ColorerTexte("(Charger)", Dim, Vert) << "\n-Demarrer une nouvelle partie " << ColorerTexte("(Demarrer)\n\n", Dim, Vert);

		std::getline(std::cin,reponse);

		//si rien n'est rentré => on attend
		if(reponse==""){
			std::cout << ColorerTexte("Entree invalide !\n",Gras, Fond_Rouge);
			continue;
		}

		//Initialisation d'une nouvelle partie
		if(toupper(reponse.at(0))=='D'){

			std::string reponseIA = "";

			std::cout <<"\nNouvelle Partie en cours...\nEntrez le nom du Joueur 1 : ";
			std::cin >> nomJ1;
			std::cout << "Est-ce une IA ? (Oui ou Non) ";
			std::cin >> reponseIA;

			//si rien n'est rentré => on attend
			if(reponseIA==""){
				std::cout << ColorerTexte("\nEntree invalide ! Debut de partie annule...\n",Gras, Fond_Rouge);
				continue;
			}

			switch(toupper(reponseIA.at(0))) {
				case 'O' : 	IAJ1=true;
			    			break;
			    case 'N' : 	IAJ1=false;
			    			break;
			}
			reponseIA = "";

			std::cout << "\nEntrez le nom du Joueur 2 : ";
			std::cin >> nomJ2;
			std::cout << "Est-ce une IA ? (Oui ou Non) ";
			std::cin >> reponseIA;

			//si rien n'est rentré => on attend
			if(reponseIA=="" ){
				std::cout << ColorerTexte("\nEntree invalide ! Debut de partie annule...\n",Gras, Fond_Rouge);
				continue;
			}

			switch(toupper(reponseIA.at(0))) {
				case 'O' : 	IAJ2=true;
			    			break;
			    case 'N' : 	IAJ2=false;
			    			break;
			}


			//On met les joueurs à jour avec les données correctes
			J1.setNom(nomJ1);
			J1.setIA(IAJ1);

			J2.setNom(nomJ2);
			J2.setIA(IAJ2);

			//On vide le buffer cin
			std::getline(std::cin,reponseIA);

		}
		//Chargement d'une partie
		else if(toupper(reponse.at(0))=='C'){
			std::string nomfichier="";
			std::cout << "Veuillez rentrer le nom de la sauvegarde (sans l'extension) : ";
			std::getline(std::cin,nomfichier);

			bool OK = app.Charger(nomfichier,J1,J2,plateau);

			//si il y a un echec lors du chargement => on repart au début
			if(!OK){
				reponse = "";
				continue;
			}

		}
		else{
			//si rien n'est rentré => on attend une réponse valide !
			reponse = "";
			std::cout << ColorerTexte("\nEntree invalide !\n",Gras, Fond_Rouge);
			continue;
		}

	}

	app.Init();

	while(!app.VerifFinPartie()){
		
		//On efface la console
		//system("clear");

		std::stringstream sstm;
		sstm << "\n\nTour : " << NumTour << "/" << TOURS_MAX << "\n\nF = Fantassin (10 pieces)  |  A = Archer (12 pieces)  |  C = Catapulte (20 pieces)  |  S = Super Soldat (pas en vente)\n";
		std::cout << '\n' << ColorerTexte(sstm.str(), Gras, Fond_NoirClair) << "\n";
		
		//On vide le récap des actions
		recapitulatifTour = "\nDétail des actions : \n";

		if((NumTour%2)==0){

			//Gain de 8 pièces en début de tour
			J1.MAJPieces(8);

			//Le joueur fait jouer ses unités
			J1.Jouer(plateau);

AfficheActions : 

			//Puis on affiche l'état de la partie pour qu'il puisse avoir les infos à jour pour décider de son action
			Affiche_Joueur1(J1.getNom());
			std::cout << '\n' << plateau.toString();


			//si c'est une IA => on simule son comportement
			if(J1.EstIA()){
				int actionIA = tirage(0,2);

				//On ne peut agir que si la case est libre
				if(plateau.getCase(BASE_A)==nullptr){
					
					//Les recrues de l'IA sont aléatoires
					//cependant s'il n'a pas l'argent nécéssaire, il essayera d'acheter une unité moins chère

					if(actionIA==0){
						
						bool OK = J1.recruter(plateau,Catapulte::getInstance());
						if(!OK){
							bool OK2 = J1.recruter(plateau,Archer::getInstance());

							if(!OK2){
								J1.recruter(plateau,Fantassin::getInstance());
							}
						}
					}
					else if(actionIA==1){
						
						bool OK = J1.recruter(plateau,Archer::getInstance());

						if(!OK){
							J1.recruter(plateau,Fantassin::getInstance());
						}


					}
					else if(actionIA==2){
						
						J1.recruter(plateau,Fantassin::getInstance());

					}
				}					
			}
			//Sinon c'est un joueur humain
			else{
				std::string ActionUtilisateur = "";
				std::cout << "\nQue voulez vous faire " << ColorerTexte("(Recruter, Sauvegarder, Charger, Attendre, Detail du tour en cours)",Dim, VertClair) << " ? ";
				std::getline(std::cin,ActionUtilisateur);

				bool afficheMenuRecrue = false;

				//si rien n'est rentré => on attend
				if(ActionUtilisateur==""){
					ActionUtilisateur = "Attendre";
				}

				std::string repMenu2 = "";

				switch(toupper(ActionUtilisateur.at(0))) {
					case 'R' : 	{
						afficheMenuRecrue = true;
				   		break;
				   	}
				    case 'S' :{
				     	std::cout << "Veuillez entrer le nom de la sauvegarde : ";
		    			std::getline(std::cin,repMenu2);
		    			app.Sauvegarder(repMenu2,J1,J2,plateau);
		    			goto AfficheActions;		//façon la plus simple de repartir à l'affichage juste au dessus
		    			break;
				    }

				    case 'C' :{
				     	std::string nomfichier="";
						std::cout << "Veuillez rentrer le nom de la sauvegarde (sans l'extension) : ";
						std::getline(std::cin,nomfichier);
						if(!app.Charger(nomfichier,J1,J2,plateau)) goto AfficheActions; //façon la plus simple de repartir à l'affichage juste au dessus
		    			break;
				    }

				    case 'D' :{ 	
				    	std::cout << "\n\n" << ColorerTexte(recapitulatifTour, Gras, Fond_NoirClair) << '\n';
		    			goto AfficheActions;		//façon la plus simple de repartir à l'affichage juste au dessus
		    			break;
		    		}

				    case 'A' : {break;}
				}

				if(afficheMenuRecrue){
					std::string commande = "";
					std::cout << "\nEntrez le nom de l'unité que vous souhaitez recruter : ";

					//Empeche de jouer plusieurs commandes en une fois
					std::getline(std::cin,commande);

					//si rien n'est rentré => on ne recrute pas
					if(commande==""){
						commande = " vide";
					}

					switch(toupper(commande.at(0))) {
						case 'F' : 	J1.recruter(plateau, Fantassin::getInstance());
					    			break;
					    case 'A' : 	J1.recruter(plateau, Archer::getInstance());
					    			break;
					    case 'C' : 	J1.recruter(plateau, Catapulte::getInstance());
					    			break;
					}
				}
			}	

		}
		//Joueur 2
		else{

			//Gain de 8 pièces en début de tour
			J2.MAJPieces(8);

			//Le joueur fait jouer ses unités 
			J2.Jouer(plateau);
			
			//DEBUGstd::cout << "\n\nTour du J2 : " << ColorerTexte(recapitulatifTour, Gras, Fond_NoirClair) << '\n';

			//Puis on affiche l'état de la partie pour qu'il puisse avoir les infos à jour pour décider de son action
			Affiche_Joueur2(J2.getNom());
			std::cout << '\n' << plateau.toString();
			
			//si c'est une IA => on simule son comportement
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
			}
			//si c'est un joueur humain
			else{
				std::string ActionUtilisateur = "";
				std::cout << "\nQue voulez vous faire " << ColorerTexte("(Recruter, Sauvegarder, Charger, Attendre, Detail du tour en cours)",Dim, VertClair) << " ? ";
				std::getline(std::cin,ActionUtilisateur);

				bool afficheMenuRecrue = false;

				//si rien n'est rentré => on attend
				if(ActionUtilisateur==""){
					ActionUtilisateur = "Attendre";
				}

				std::string repMenu2 = "";

				//switch sur l'action voulue
				switch(toupper(ActionUtilisateur.at(0))) {
					case 'R' : 	{
						afficheMenuRecrue = true;
				   		break;
				   	}
				    case 'S' :{
				     	std::cout << "Veuillez entrer le nom de la sauvegarde : ";
		    			std::getline(std::cin,repMenu2);
		    			app.Sauvegarder(repMenu2,J1,J2,plateau);
		    			goto AfficheActions;		//façon la plus simple de repartir à l'affichage juste au dessus
		    			break;
				    }

				    case 'C' :{
				     	std::string nomfichier="";
						std::cout << "Veuillez rentrer le nom de la sauvegarde (sans l'extension) : ";
						std::getline(std::cin,nomfichier);
						if(!app.Charger(nomfichier,J1,J2,plateau)) goto AfficheActions; //façon la plus simple de repartir à l'affichage juste au dessus
		    			break;
				    }

				    case 'D' :{ 	
				    	std::cout << "\n\n" << ColorerTexte(recapitulatifTour, Gras, Fond_NoirClair) << '\n';
		    			goto AfficheActions;		//façon la plus simple de repartir à l'affichage juste au dessus
		    			break;
		    		}

				    case 'A' : {break;}
				}

				if(afficheMenuRecrue){
					std::string commande = "";
					std::cout << "\nEntrez le nom de l'unité que vous souhaitez recruter : ";

					//Empeche de jouer plusieurs commandes en une fois
					std::getline(std::cin,commande);

					//si rien n'est rentré => on ne recrute pas
					if(commande==""){
						commande = " vide";
					}

					switch(toupper(commande.at(0))) {
						case 'F' : 	J2.recruter(plateau, Fantassin::getInstance());
					    			break;
					    case 'A' : 	J2.recruter(plateau, Archer::getInstance());
					    			break;
					    case 'C' : 	J2.recruter(plateau, Catapulte::getInstance());
					    			break;
					}
				}

			}
		}

		//et on passe au tour suivant
		NumTour++;
	}

	//Message de fin de partie 
	if(plateau.tourA->getVie()==0){
		std::cout << ColorerTexte( "\n" + nomJ2 + "gagne la partie !\n",GrasItaliqueSouligne,Fond_NoirClair);
	}
	else if(plateau.tourB->getVie()==0){
		std::cout << ColorerTexte( "\n" + nomJ1 + "gagne la partie !\n",GrasItaliqueSouligne,Fond_NoirClair);
	}

	return 0;

}
