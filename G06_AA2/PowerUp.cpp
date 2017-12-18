#include "PowerUp.h"



PowerUp::PowerUp()
{
	textWidth = 144;//tama�o de la spritesheet
	textHeight = 96;//tama�od de la spritesheet
}


PowerUp::~PowerUp()
{

}

void PowerUp::InitCasc(int x, int y) {
	frameWidth = textWidth / 3;//el tama�o del frame de la animacion es el tama�o total /3 por que hay 3 sprites y solo queremos coger el de la bomba
	frameHeight = textHeight / 2;//exactamente lo mismo pero con el largo
	CasRect.x = 96;//posicionamos el rectangulo para coger el sprite de la bomba
	CasRect.y = 48;
	SelectorCasc.x = x;//le decimos donde pintar la bomba
	SelectorCasc.y = y;
	CasRect.h = SelectorCasc.h = frameHeight;
	CasRect.w = SelectorCasc.w = frameWidth;

}

void PowerUp::InitSpeed(int x, int y) {
	frameWidth = textWidth / 3;//el tama�o del frame de la animacion es el tama�o total /3 por que hay 3 sprites y solo queremos coger el de la bomba
	frameHeight = textHeight / 2;//exactamente lo mismo pero con el largo
	SpeedRect.x = 48;//posicionamos el rectangulo para coger el sprite de la bomba
	SpeedRect.y = 48;
	SelectorSpeed.x = x;//le decimos donde pintar la bomba
	SelectorSpeed.y = y;
	SpeedRect.h = SelectorSpeed.h = frameHeight;
	SpeedRect.w = SelectorSpeed.w = frameWidth;
}

void PowerUp::AutodrawCasc() {
	Renderer::Instance()->PushSprite("Bomb", CasRect, SelectorCasc);
}

void PowerUp::AutodrawSpeed() {
	Renderer::Instance()->PushSprite("Bomb", SpeedRect, SelectorSpeed);
}

