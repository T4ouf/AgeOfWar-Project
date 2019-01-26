#pragma once

#include <string>
#include "Plateau.hpp"


#define Gras "1"
#define Dim "2"
#define Italique "3"
#define Souligne "4"
#define Inverse "7"

#define GrasItalique "1;3"
#define GrasSouligne "1;4"
#define GrasInverse "1;7"
#define SouligneInverse "4;7"

#define GrasSouligneInvers "1;4;7"
#define GrasItaliqueSouligne "1;3;4"

//////////////////////////////////////////
//            ENUM EnumEquipe			//
//////////////////////////////////////////

const unsigned int BASE_A=0;
const unsigned int BASE_B=TAILLE_PLATEAU;

enum EnumEquipe{
	EquipeA=1,
	EquipeB=2
};

int positionTour(EnumEquipe e);
int positionTourAdverse(EnumEquipe e);
int direction(EnumEquipe e);
std::string getNomEquipe(EnumEquipe e);


//////////////////////////////////////////
//            ENUM EnumAction			//
//////////////////////////////////////////

enum EnumAction{
	Vide = 0,
	Avancer = 1,
	Attaquer =2
};

//////////////////////////////////////////
//         Enum Affichage texte			//
//////////////////////////////////////////

enum Couleurs{
	Noir = 30,
	Rouge = 31,
	Vert = 32,
	Jaune = 33,
	Bleu = 34, 
	Magenta = 35,
	Cyan = 36,
	Blanc = 37,

	NoirClair	= 90,
	RougeClair 	= 91,
	VertClair	= 92,
	JauneClair 	= 93,
	BleuClair 	= 94, 
	MagentaClair = 95,
	CyanClair 	= 96,
	BlancClair 	= 97,

	Fond_Noir = 40,
	Fond_Rouge = 41,
	Fond_Vert = 42,
	Fond_Jaune = 43,
	Fond_Bleu = 44, 
	Fond_Magenta = 45,
	Fond_Cyan = 46,
	Fond_Blanc = 47,

	Fond_NoirClair	= 100,
	Fond_RougeClair	= 101,
	Fond_VertClair	= 102,
	Fond_JauneClair = 103,
	Fond_BleuClair 	= 104, 
	Fond_MagentaClair = 105,
	Fond_CyanClair 	= 106,
	Fond_BlancClair = 107
};

std::string ColorerTexte(const std::string& texte,std::string type, Couleurs couleur);


#define COULEUR_EQUIPE_A BleuClair
#define COULEUR_EQUIPE_B RougeClair

//////////////////////////////////////////
//         	Outils Utiles				//
//////////////////////////////////////////

unsigned int max(int i1, int i2);
unsigned int min(int i1, int i2);