#include "stdafx.h"
#include "red_worm.h"


red_worm::red_worm()
{
}


red_worm::~red_worm()
{
}

HRESULT red_worm::init()
{
	return S_OK;
}

HRESULT red_worm::init(int x, int y)
{
	_worm.img = IMAGEMANAGER->addFrameImage("worm", "image/Enemy/worm.bmp", 135, 72, 3, 2, true, RGB(0, 255, 0));
	_worm.x = x;
	_worm.y = y;
	_worm.hp = 1;
	_worm.isBoss = false;
	_worm.rc = RectMake(_worm.x + 3, _worm.y + 12, _worm.img->getFrameWidth() - 10, _worm.img->getFrameHeight() - 15);
	_worm.img->setFrameY(0);

	_moveX = 1;
	_maxMoveX = 0;
	_isRight = true;

	return S_OK;
}

void red_worm::release()
{
}

void red_worm::update()
{
	move();
	frameCount();
	_worm.rc = RectMake(_worm.x + 3, _worm.y + 12, _worm.img->getFrameWidth() - 10, _worm.img->getFrameHeight() - 15);
}

void red_worm::render()
{
	_worm.img->frameRender(getMemDC(), _worm.x, _worm.y, _worm.img->getFrameX(), _worm.img->getFrameY());
}

void red_worm::frameCount()
{
	_worm.count++;
	if (_worm.count % 7 == 0)
	{
		if (_worm.img->getFrameX() >= _worm.img->getMaxFrameX())
		{
			_worm.img->setFrameX(0);
		}
		else
		{
			_worm.img->setFrameX(_worm.img->getFrameX() + 1);
		}
		_worm.count = 0;
	}
}

void red_worm::move()
{
	if (_isRight)
	{
		_worm.x += _moveX;
		_maxMoveX += _moveX;
		if (_maxMoveX == 100)
		{
			_isRight = false;
			_worm.img->setFrameY(1);
			_maxMoveX = 0;
		}
	}
	else if (!_isRight)
	{
		_worm.x -= _moveX;
		_maxMoveX += _moveX;
		if (_maxMoveX == 100)
		{
			_isRight = true;
			_worm.img->setFrameY(0);
			_maxMoveX = 0;
		}
	}
}
