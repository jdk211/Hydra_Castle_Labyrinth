#include "stdafx.h"
#include "batBoss.h"


batBoss::batBoss()
{
}


batBoss::~batBoss()
{
}

HRESULT batBoss::init()
{
	return S_OK;
}

HRESULT batBoss::init(int x, int y)
{
	_batBoss.img = IMAGEMANAGER->addFrameImage("bossBatMan", "image/Enemy/bossBatMan.bmp", 540, 144, 3, 1, true, RGB(0, 255, 0));
	_batBoss.x = x;
	_batBoss.y = y;
	_batBoss.hp = 10;
	_batBoss.isBoss = true;
	_batBoss.rc = RectMake(_batBoss.x + 3, _batBoss.y + 12, _batBoss.img->getFrameWidth() - 10, _batBoss.img->getFrameHeight() - 15);

	_moveY = 2;
	_moveX = 1;
	_maxMoveY = 0;
	_maxMoveX = 0;

	_isDown = true;
	_isRight = true;

	return S_OK;
}

void batBoss::release()
{
}

void batBoss::update()
{
	move();
	frameCount();

	_batBoss.rc = RectMake(_batBoss.x + 3, _batBoss.y + 12, _batBoss.img->getFrameWidth() - 10, _batBoss.img->getFrameHeight() - 15);
}

void batBoss::render()
{
	_batBoss.img->frameRender(getMemDC(), _batBoss.x, _batBoss.y, _batBoss.img->getFrameX(), _batBoss.img->getFrameY());
}

void batBoss::frameCount()
{
	_batBoss.count++;
	if (_batBoss.count % 5 == 0)
	{
		if (_batBoss.img->getFrameX() >= _batBoss.img->getMaxFrameX())
		{
			_batBoss.img->setFrameX(0);
		}
		else
		{
			_batBoss.img->setFrameX(_batBoss.img->getFrameX() + 1);
		}
		_batBoss.count = 0;
	}
}

void batBoss::move()
{
	if (_isDown)
	{
		_batBoss.y += _moveY;
		_maxMoveY += _moveY;
		if (_maxMoveY == 200)
		{
			_isDown = false;
			_maxMoveY = 0;
		}
	}
	else if (!_isDown)
	{
		_batBoss.y -= _moveY;
		_maxMoveY += _moveY;
		if (_maxMoveY == 200)
		{
			_isDown = true;
			_maxMoveY = 0;
		}
	}

	if (_isRight)
	{
		_batBoss.x += _moveX;
		_maxMoveX += _moveX;
		if (_maxMoveX == 400)
		{
			_isRight = false;
			_maxMoveX = 0;
		}
	}
	else if (!_isRight)
	{
		_batBoss.x -= _moveX;
		_maxMoveX += _moveX;
		if (_maxMoveX == 400)
		{
			_isRight = true;
			_maxMoveX = 0;
		}
	}
}

bool batBoss::bulletFire()
{
	_bulletTimer += TIMEMANAGER->getElapsedTime();
	if (_bulletTimer >= 5.0f)
	{
		_bulletTimer = 0.0f;
		return true;
	}
	return false;
}
