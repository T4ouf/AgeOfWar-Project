#include "Unite.hpp"

Unite::Unite(Categorie* categorie, EnumEquipe equipe) : Entite(categorie->getVieMax(),equipe){

	m_actions[0]=categorie->getAction1();
	m_actions[1]=categorie->getAction2();

	m_actionAlternative=categorie->getActionAlt();

	m_nom = categorie->getNom() + "(" + getNomEquipe(equipe) + ")";

	m_categorie = categorie;
}


bool Unite::Attaquer(Plateau_t& p){

	/*//A GERER :
		- Mort Unite attaquée (y compris dommage colatéral) (dire au plateau de l'enlever, etc.)
	*/
	bool OK = false;

	//Pour chaque case dans la portée de l'unité
	for(unsigned int i = m_porteeMin; i<=m_porteeMax;i++){

		Entite* caseVisee = (p.getCase(getX() + direction(getEquipe())*i));

		//Si la case est occupée par une unité adverse
		if(caseVisee!=nullptr && caseVisee->getEquipe()!=getEquipe()){

			caseVisee->subirDegats(m_categorie->getPuissance());

			//Pour toute case en dommage collatéral
			for(unsigned int j=0;j< m_categorie->getCaseSuppDegats();j++){

				//Si la case est dans le plateau
				if( (direction(getEquipe())*(int)j + (int)getX() + direction(getEquipe())*(int)i) >=0 &&
					(direction(getEquipe())*(int)j + (int)getX() + direction(getEquipe())*(int)i)<=TAILLE_PLATEAU){

					caseVisee = (p.getCase(direction(getEquipe())*j + getX() + direction(getEquipe())*i));

					//si il y a quelqu'un sur la case de dommage collatéral
					if(caseVisee!=nullptr){
						caseVisee->subirDegats(m_categorie->getPuissance());
					}
				}
			}std::vector<Unite*> casesUnite;

			//l'attaque est un succes => on sort
			return true;

		}
		//Sinon(on attaque une case vide ou un allié(cela signifie qu'une unité est tout de même à  via les dégâts collatéraux))
		else{
			//Pour toute case en dommage collatéral
			for(unsigned int j=0;j< m_categorie->getCaseSuppDegats();j++){

				//Si la case est dans le plateau
				if( (direction(getEquipe())*(int)j + (int)getX() + direction(getEquipe())*(int)m_porteeMax) >=0 &&
					(direction(getEquipe())*(int)j + (int)getX() + direction(getEquipe())*(int)m_porteeMax)<=TAILLE_PLATEAU){

					caseVisee = (p.getCase(direction(getEquipe())*j + getX() + direction(getEquipe())*i));

					//si il y a quelqu'un sur la case de dommage collatéral
					if(caseVisee!=nullptr){
						caseVisee->subirDegats(m_categorie->getPuissance());
						OK = true;
					}
				}
			}
		}
	}

	return OK;

}
