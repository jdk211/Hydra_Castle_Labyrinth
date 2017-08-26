#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init()
{
	
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	frameCount();
}

void enemy::render()
{
}

void enemy::frameCount()
{
	_enemy.count++;
	if (_enemy.count % 7 == 0)
	{
		if (_enemy.img->getFrameX() >= _enemy.img->getMaxFrameX())
		{
			_enemy.img->setFrameX(0);
		}
		else
		{
			_enemy.img->setFrameX(_enemy.img->getFrameX() + 1);
		}
		_enemy.count = 0;
	}
}

bool enemy::bulletFire()
{
	return false;
}
