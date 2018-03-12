#include "stdafx.h"
#include "Cellule.h"

unsigned int Cellule::L = 30;
CPoint Cellule::start = CPoint(5, 5);

Cellule::Cellule()
{
	this->TopLeft() = start;
	this->BottomRight() = CPoint(L, L);
}


Cellule::~Cellule()
{
}

void Cellule::dessiner(CDC *dc)
{
	dc->Rectangle(this);
	
}
