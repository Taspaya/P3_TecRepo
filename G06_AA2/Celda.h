#pragma once
#include "Constants.h"
#include "Renderer.h"



class Celda
{
public: 
	//Sprites de cuadrados
	SDL_Rect celROJARect, selectorROJA;
	SDL_Rect celRect, selector;
	SDL_Rect celINDESTRect, selectorINDEST;
	TipoCelda cellID;

	int textWidth, textHeight, frameWidth, frameHeight;//tamaños
	bool Destructible;
	Point Location;

public:

	void CellMorfer(TipoCelda e);
	
	void InitINDES(int x, int y);
	void AutoDrawINDES();

	void InitGRIS(int x, int y);
	void AutoDrawGRIS();

	Point GetCellLocation();
	

	void InitROJA(int x, int y);
	void AutoDrawROJA();

	void Celda::InitVOID(int x, int y);

	Celda();
	~Celda();
};

