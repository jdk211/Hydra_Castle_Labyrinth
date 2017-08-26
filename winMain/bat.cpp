#include "stdafx.h"
#include "bat.h"


bat::bat()
{
}


bat::~bat()
{
}

HRESULT bat::init()
{
	return S_OK;
}

HRESULT bat::init(int x, int y)
{
	Wallbat.img = IMAGEMANAGER->addFrameImage("bat", "image/Enemy/bat.bmp", 360, 42, 6, 1, true, RGB(0, 255, 0));
	Wallbat.x = x;
	Wallbat.y = y;
	Wallbat.hp = 1;
	Wallbat.isBoss = false;
	Wallbat.rc = RectMake(Wallbat.x + 3, Wallbat.y + 12, Wallbat.img->getFrameWidth() - 10, Wallbat.img->getFrameHeight() - 15);

	_moveY = 2;
	_maxMoveY = 0;
	_isDown = true;

	return S_OK;
}

void bat::release()
{
}

void bat::update()
{
	move();
	frameCount();
	Wallbat.rc = RectMake(Wallbat.x + 3, Wallbat.y + 12, Wallbat.img->getFrameWidth() - 10, Wallbat.img->getFrameHeight() - 15);
}

void bat::render()
{
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	Wallbat.img->frameRender(getMemDC(), Wallbat.x, Wallbat.y, Wallbat.img->getFrameX(), Wallbat.img->getFrameY());
}

void bat::frameCount()
{
	Wallbat.count++;
	if (Wallbat.count % 7 == 0)
	{
		if (Wallbat.img->getFrameX() >= Wallbat.img->getMaxFrameX())
		{
			Wallbat.img->setFrameX(0);
		}
		else
		{
			Wallbat.img->setFrameX(Wallbat.img->getFrameX() + 1);
		}
		Wallbat.count = 0;
	}
}

void bat::move()
{
	if (_isDown)
	{
		Wallbat.y += _moveY;
		_maxMoveY += _moveY;
		if (_maxMoveY == 120)
		{
			_isDown = false;
			_maxMoveY = 0;
		}
	}
	else if(!_isDown)
	{
		Wallbat.y -= _moveY;
		_maxMoveY += _moveY;
		if (_maxMoveY == 120)
		{
			_isDown = true;
			_maxMoveY = 0;
		}
	}
}
