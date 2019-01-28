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

    if(degats>=m_vie){
        m_vie=0;
        return true;
    }
    m_vie=m_vie-degats;
    return false;
}
