#pragma once
#include "Renderer.h"
#include "SDL.h"
#include <iostream>
#include <time.h>
#include "Constants.h"
#include "Bomb.h"

class Character
{

public:

	float timer;
	bool onPwup;
	Bomb Mybomb;
	int textWidth, textHeight, frameWidth, frameHeight, inmortal;//tamaños
	SDL_Rect playerRect1, playerPosition1;//rectangulos
	bool up, down, left, right, colUp, colDown, colRight, colLeft;
	int nLifes;			//numero de vidas de los jugadores
	bool cBoom;			//booleano de si tiene una bomba ya puesta
	int score;			//valor de su puntuacion
	bool isCasc;		//tiene el powerup del casco?
	bool isPatin;		//tiene el powerup del patin?
	Point Pos;			//struct compuesto por dos INT que indican su coordenada
	Point centreP;
	Point RelativePos;	//struct compuesto por dos INT que indican su coordenada respecto las celdas
	float vel;			//valor de la velocidad del player
	Mov KEY;			//struct de teclas del player ESTA DEFINIDO EN CONSTANS.H
	
	bool isDead;		//el jugador se ha muerto?
	int posBombX;		//posicion x de la bomba
	int posBombY;		//posicion y de la bomba

public:

	 void GetEventKey(SDL_Event &event);
	 void AutoPaint(std::string);		//funcion que pinta al jugador
	 void SetBomb(Character &Player);	//funcion que planta la bomba en el suelo
	 void IsDead();						//funcion que comprueba que el jugador este vivo o muerto
	 void PowerUps();					//funcion que controla los power ups
	 void ControlMovement();
	 
	 Character();
	 ~Character();
};

