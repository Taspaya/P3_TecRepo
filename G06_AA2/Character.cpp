#pragma once
#include "Character.h"
#include "Renderer.h"



Character::Character()
{
	//INICIALIZACION DE LOS VALORES DE CHARACTER
	
	timer = 10;
	nLifes = PLAYER_START_N_LIFES;
	vel = PLAYER_START_VELOCITY;
	score = PLAYER_START_SCORE;
	textWidth = PLAYER_TEXTURE_WIDTH;
	textHeight = PLAYER_TEXTURE_HEIGHT;
	textWidth = PLAYER_TEXTURE_WIDTH;
	textHeight = PLAYER_TEXTURE_HEIGHT;

	onPwup = false;
	cBoom = false;
	isCasc = false;
	isPatin = false;
	colUp = false;
	colDown = false;
	colLeft = false;
	colRight = false;
	isDead = false;

	KEY = Mov::Nula;	
	
}


Character::~Character()
{
}


void Character::AutoPaint(std::string _tag) {
	
	//FUNCION EXACTA A LA DE BOMB PARA EL AUTO PINTADO
	frameWidth = textWidth / 3;//el tamaño del frame de la animacion es el tamaño total / 6 ya que son 6 movimientos
	frameHeight = textHeight / 4;//exactamente lo mismo pero con el largo
	
	playerPosition1.x = Pos.x;
	playerPosition1.y = Pos.y;
	
	playerRect1.x = playerRect1.y = 0;
	int frameTime = 0;

	playerPosition1.h = playerRect1.h = frameHeight;
	playerPosition1.w = playerRect1.w = frameWidth;
	
	Renderer::Instance()->PushSprite(_tag, playerRect1, playerPosition1);
	
	//COMPROBAMOS QUE HAYA PLANTADO UNA BOMBA SI LA HA PLANTADO LLAMAMOS A LA FUNCION PARA QUE LA PINTE
	if (cBoom) {
		Mybomb.AutoDraw();
	}
}

//li pases el player al que li vols fer mal
void Character::SetBomb(Character &Player) {
	
	if (Mybomb.Toched) {
		Player.nLifes = Player.nLifes - 1;
		Mybomb.Toched = false;
	}

}

void Character::IsDead(){
	if (nLifes <= 0) {			//comprobamos que no se muera el player
		std::cout << "Muerto" << std::endl;
		isDead = true;
	}
}

void Character::PowerUps() {
	//SI EL PLAYER TIENE UN POWER UP MODIFICAMOS SU ATRIBUTO
	if (!onPwup) {
		vel = 2;
		if (isCasc) onPwup = true;
		if (isPatin)
		{
			vel = vel * 1.8;
			isPatin = false;
			onPwup = true;
		}
	}
	else
	{
		timer -= SCREEN_TICKS_PER_FRAME; // empieza el contador del cooldown
		if (timer <= 0) 
		{ 
		onPwup = false; 
		std::cout << "EEEND OF COOLDOWNS  " << timer << std::endl;
		isCasc = false;
		timer = 10;
		}
	}
}
	
void Character::ControlMovement() 
{
		// CALCULAMOS LA POSICION RELATIVA DEL PLAYER SOBRE LAS CELDAS DEL MAP
		centreP.x = Pos.x + (frameHeight / 2);
		centreP.y = Pos.y + (frameWidth / 2);
			
		RelativePos.x = (int)((RELATIVE_START_X - centreP.x)  / -RELATIVE_START_X);
		RelativePos.y = (int)((RELATIVE_START_Y - centreP.y)  / -RELATIVE_START_X);

}

Mov Character::GetEventKey(SDL_Event &event){
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym)
			{
			/*case SDLK_ESCAPE:
				currentScene = MENU;
				break;*/
			case SDLK_a://Si le das a la 
				return Mov::A;//ponemos la tecla a la tecla actual que el jugador a pulsado 
				break;
			case SDLK_d: //lo mismo con D
				return Mov::D;
				break;
			case SDLK_s://lo mismo con S
				return Mov::S;
				break;
			case SDLK_w: //lo mismo con W
				return Mov::W;
				break;
			case SDLK_SPACE: //lo mismo con SPACE
				return Mov::Space;
				break;
			case SDLK_LEFT: //Lo mismo para el player 2 
				return Mov::Left;//aqui cogemos el otro struct de teclas
				break;
			case SDLK_RIGHT:
				return Mov::Right;
				break;
			case SDLK_DOWN:
				return Mov::Down;
				break;
			case SDLK_UP:
				return Mov::Up;
				break;
			case SDLK_RCTRL:
				return Mov::CTRL;
				break;
			default:
				break;
			}
		}
		/*else if (event.type == SDL_KEYUP) { // Quando levantamos la tecla...

			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				currentScene = MENU;
				break;
			case SDLK_a://Si le das a la 
				P1.Tecla = Mov::Nula;//ponemos la tecla a la tecla actual que el jugador a pulsado 
				break;
			case SDLK_d: //lo mismo con D
				P1.Tecla = Mov::Nula;
				break;
			case SDLK_s://lo mismo con S
				P1.Tecla = Mov::Nula;
				break;
			case SDLK_w: //lo mismo con W
				P1.Tecla = Mov::Nula;
				break;
			case SDLK_LEFT: //Lo mismo para el player 2 
				P2.Tecla = Mov::Nula;//aqui cogemos el otro struct de teclas
				break;
			case SDLK_RIGHT:
				P2.Tecla = Mov::Nula;
				break;
			case SDLK_DOWN:
				P2.Tecla = Mov::Nula;
				break;
			case SDLK_UP:
				P2.Tecla = Mov::Nula;
				break;
			default:
				break;
			}*/
		}
	return Mov::Nula;
   }



