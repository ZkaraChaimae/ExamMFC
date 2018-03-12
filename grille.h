#pragma once
#include "Cellule.h"
class grille
{
public:
	grille();
	~grille();
	void dessiner(CDC *);
private:
	Cellule gr[8][30];
};

