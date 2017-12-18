#pragma once
#include "Celda.h"
#include "Renderer.h"
#include "Mapa.h"

class Mapa
{
	// Mapa.h:

	Celda *Map[13][11];
	int random;

public:
	
	Mapa();

	int nLevel;
	void InitMapa(int);
	void DrawMap();
	void ModifyCell(int, int,  TipoCelda, int &_e);
	Point GetCelda(int, int);
	TipoCelda GetTypeCell(int, int);

	~Mapa();

};

