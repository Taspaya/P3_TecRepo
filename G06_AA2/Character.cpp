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
	w= a = s = d = up = down = left = right = false;
	KEY = Mov::Nula;	
	
}


Character::~Character()
{
}


void Character::AutoPaint(std::string _tag) {
	
	//FUNCION EXACTA A LA DE BOMB PARA EL AUTO PINTADO
	frameWidth = textWidth / 3;//el tama�o del frame de la animacion es el tama�o total / 6 ya que son 6 movimientos
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
	
void Character::ControlMovement(Mov _mov) 
{
		// CALCULAMOS LA POSICION RELATIVA DEL PLAYER SOBRE LAS CELDAS DEL MAP
		

	switch (_mov)
	{
	case Mov::A:
		centreP.x = Pos.x;
		centreP.y = Pos.y + (frameHeight / 2);
		break;
	case Mov::Left:
		centreP.x = Pos.x;
		centreP.y = Pos.y + (frameHeight / 2);
		break;
	case Mov::D:
		centreP.x = Pos.x + frameWidth;
		centreP.y = Pos.y + (frameHeight / 2);
		break;
	case Mov::Right:
		centreP.x = Pos.x + frameWidth;
		centreP.y = Pos.y + (frameHeight / 2);
		break;
	case Mov::W:
		centreP.x = Pos.x + (frameWidth / 2);
		centreP.y = Pos.y;
		break;
	case Mov::Up:
		centreP.x = Pos.x + (frameWidth / 2);
		centreP.y = Pos.y;
		break;
	case Mov::Down:
		centreP.x = Pos.x + (frameWidth / 2);
		centreP.y = Pos.y + frameHeight;
		break;
	case Mov::S:
		centreP.x = Pos.x + (frameWidth / 2);
		centreP.y = Pos.y + frameHeight;
		break;
	default:
		centreP.x = Pos.x + (frameHeight / 2);
		centreP.y = Pos.y + (frameWidth / 2);
		break;
	}



		RelativePos.x = (int)((RELATIVE_START_X - centreP.x)  / -RELATIVE_START_X);
		RelativePos.y = (int)((RELATIVE_START_Y - centreP.y)  / -RELATIVE_START_X);

}

void Character::GetEventKey(SDL_Event &_event) {
	
	
		if (_event.type == SDL_KEYDOWN) {
			switch (_event.key.keysym.sym)
			{
			case SDLK_a://Si le das a la 
				KEY =  Mov::A;//ponemos la tecla a la tecla actual que el jugador a pulsado 
				a = true;
				break;
			case SDLK_d: //lo mismo con D
				KEY =  Mov::D;
				d = true;
				break;
			case SDLK_s://lo mismo con S
				KEY = Mov::S;
				s = true;
				break;
			case SDLK_w: //lo mismo con W
				KEY = Mov::W;
				w = true;
				break;
			case SDLK_SPACE: //lo mismo con SPACE
				KEY =  Mov::Space;
				break;
			case SDLK_LEFT: //Lo mismo para el player 2 
				KEY = Mov::Left;//aqui cogemos el otro struct de teclas
				left = true;
				break;
			case SDLK_RIGHT:
				right = true;
				KEY = Mov::Right;
				break;
			case SDLK_DOWN:
				down = true;
				KEY = Mov::Down;
				break;
			case SDLK_UP:
				up = true;
				KEY = Mov::Up;
				break;
			case SDLK_RCTRL:
				KEY = Mov::CTRL;
				break;
			default:
				break;
			}
		}
		else if (_event.type == SDL_KEYUP) { // Quando levantamos la tecla...

			switch (_event.key.keysym.sym)
			{
			case SDLK_a://Si le das a la 
				KEY =  Mov::Nula;//ponemos la tecla a la tecla actual que el jugador a pulsado 
				a = false;
				break;
			case SDLK_d: //lo mismo con D
				KEY = Mov::Nula;
				d = false;
				break;
			case SDLK_s://lo mismo con S
				KEY = Mov::Nula;
				s = false;
				break;
			case SDLK_w: //lo mismo con W
				w = false;
				KEY = Mov::Nula;
				break;
			case SDLK_LEFT:
				left = false; //Lo mismo para el player 2 
				KEY = Mov::Nula;//aqui cogemos el otro struct de teclas
				break;
			case SDLK_RIGHT:
				right = false;
				KEY = Mov::Nula;
				break;
			case SDLK_DOWN:
				down = false;
				KEY = Mov::Nula;
				break;
			case SDLK_UP:
				up = false;
				KEY = Mov::Nula;
				break;
			default:
				break;
			}
		}
}


