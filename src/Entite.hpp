#pragma once

#include "Enums.h"

class Entite{

private:
	int m_vie;
	int m_x;
	EnumEquipe m_equipe;

public:
	Entite(int vie, EnumEquipe equipe);
	~Entite();
	
}