#include "stdafx.h"
#include "grille.h"


grille::grille()
{

	int L = Cellule::L;
	int i, j;

	
	for (i = 0; i < 8; i++)
		for (j = 0; j < 30; j++)
		{
			gr[i][j].TopLeft() = CPoint(L + j * L, L + i * L);
			gr[i][j].BottomRight() = gr[i][j].TopLeft() + CPoint(L, L);
		}

}


grille::~grille()
{
}

void grille::dessiner(CDC *dc)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 30; j++)
		{
			gr[i][j].dessiner(dc);
		}
	CPen cp(PS_SOLID, 5, RGB(255, 0, 0));
	//CBrush cb(RGB(0, 0, 255));
	dc->SelectObject(&cp);
	dc->MoveTo(CPoint(30, 150));
	dc->LineTo(CPoint(930, 150));
	
}
