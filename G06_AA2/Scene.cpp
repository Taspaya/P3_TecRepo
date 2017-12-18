#pragma once
#include "Scene.h"



Scene::Scene() 
{
	
}


Scene::~Scene()
{
}

//Definicion de los metodos virtual
// Metodos que van a heredar los hijos

void Scene::HandleEvents() {

}

void Scene::Update() {

}

void Scene::Draw() {

}


typeScene Scene::GetTypeScene() {

	return currentScene; 
}
