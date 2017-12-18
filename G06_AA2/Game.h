#pragma once
#include "Play.h"
#include "Menu.h"
#include "Score.h"
#include "Types.h"


class Game
{
public:
	
	Scene *MyScene;						//puntero de tipo Scene que nos permitira redefinir los metodos
	typeScene tipoEscena;				// variable de typeScene que ens permetra canviar d'escenes

public:
	void Run();
	Game();
	~Game();

};

