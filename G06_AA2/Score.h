#pragma once
#include "Scene.h"

class Score : public Scene
{
public:
	void HandleEvents() override;//permite sobreescribir las virtual 
	void Update() override;
	void Draw() override;
	Score();
	~Score();
};

