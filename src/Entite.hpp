#pragma once

#include "Enums.hpp"

class Entite{

private:
	int m_vie;
	int m_x;
	EnumEquipe m_equipe;

public:
	Entite(int vie, EnumEquipe equipe);
	~Entite();
	
};