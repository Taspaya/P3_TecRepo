#pragma once
#include <iostream>
#include <windows.h>
#include "Renderer.h"
#include <time.h>
#include "Constants.h"
#include "Mapa.h"


class Bomb
{
public:

	SDL_Rect bombrect, selector;//rectangulos
	int textWidth, textHeight, frameWidth, frameHeight;//tamaños
	bool Explosion; //booleano que cuando se active la bomba estallara
	bool Toched;
	Point Center;
	Point LocationInCuadricula;

	float timeBomb;
	bool plantedBomb;

	void DamagePlayers(int PosPlayerX, int PosPlayerY, int, int, int &_vida, int &_punts);//funcion que compara las posciciones del player enemigo 
	void AutoDraw();//funcion que pinta la bomba en el luegar que le indiquemos 
	void Init(int, int);

	Bomb();

	~Bomb();
};

