#pragma once
class Cellule:public CRect
{
public:
	Cellule();
	~Cellule();
	void dessiner(CDC*);
private :
	friend class grille;
	CPoint static start;
	unsigned int static L;
};

