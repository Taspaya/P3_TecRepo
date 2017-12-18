#pragma once
#include "Renderer.h"
#include "SDL.h"
#include "Types.h"

class Scene
{
public:
	
	typeScene currentScene;

public:
	virtual void HandleEvents(); //metodo virtual que controlara eventos 
	virtual void Update();//metodo virtual que controlara la logica del juego
	virtual void Draw();//metodo virtual que controlara lo que se muestra por pantalla
	typeScene GetTypeScene();	// Metodo que nos retorna el tipo de la escena en el que estamos o queremos canviar

	Scene();
	~Scene();
};

