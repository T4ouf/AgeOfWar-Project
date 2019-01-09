#include "Entite.hpp"

int Entite::getVie(){
    return m_vie;
}

int Entite::getX(){
    return m_x;
}

EnumEquipe Entite::getEquipe(){
    return m_equipe;
}

//renvoit vrai si l'entite meurt après avoir subi les dégats
bool Entite::subirDegats(unsigned int degats){

    //TODO => FAIRE LA FCT

    degats++;
    return false;
}
