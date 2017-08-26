#include "stdafx.h"
#include "bullet.h"

bullet::bullet()
{
}


bullet::~bullet()
{
}

HRESULT bullet::init()
{
	return S_OK;
}

void bullet::release()
{
}

void bullet::update()
{
	move();
	frameCount();
}

void bullet::render()
{
	for (_viBossBullet = _vBossBullet.begin(); _viBossBullet != _vBossBullet.end(); _viBossBullet++)
	{
		//Rectangle(getMemDC(), _viBossBullet->rc.left, _viBossBullet->rc.top, _viBossBullet->rc.right, _viBossBullet->rc.bottom);
		_viBossBullet->img->frameRender(getMemDC(), _viBossBullet->rc.left, _viBossBullet->rc.top, _viBossBullet->img->getFrameX(), 0);
	}

}

void bullet::frameCount()
{
	for (_viBossBullet = _vBossBullet.begin(); _viBossBullet != _vBossBullet.end(); _viBossBullet++)
	{
		_viBossBullet->count++;
		if (_viBossBullet->count % 3 == 0)
		{
			if (_viBossBullet->img->getFrameX() >= _viBossBullet->img->getMaxFrameX())
			{
				_viBossBullet->img->setFrameX(0);
				_viBossBullet->count = 0;
			}
			else
			{
				_viBossBullet->img->setFrameX(_viBossBullet->img->getFrameX() + 1);
			}
		}
	}
}

void bullet::fire(float x, float y, float angle)
{
	stBULLET bossBullet;
	ZeroMemory(&bossBullet, sizeof(bossBullet));

	bossBullet.angle = angle;
	bossBullet.x = bossBullet.startX = x;
	bossBullet.y = bossBullet.startY = y;
	bossBullet.img = IMAGEMANAGER->addFrameImage("bossBullet", "image/Misc/bossBullet.bmp", bossBullet.startX, bossBullet.startY, 360, 45, 8, 1, true, RGB(0, 255, 0));
	bossBullet.fire = true;
	bossBullet.speed = 6.f;
	bossBullet.rc = RectMakeCenter(bossBullet.x, bossBullet.y, bossBullet.img->getFrameWidth(), bossBullet.img->getFrameHeight());

	_vBossBullet.push_back(bossBullet);

}

void bullet::move()
{
	for (_viBossBullet = _vBossBullet.begin(); _viBossBullet != _vBossBullet.end(); )
	{
		_viBossBullet->x += cosf(_viBossBullet->angle) * _viBossBullet->speed;
		_viBossBullet->y += -sinf(_viBossBullet->angle) * _viBossBullet->speed;
		_viBossBullet->rc = RectMakeCenter(_viBossBullet->x, _viBossBullet->y, _viBossBullet->img->getFrameWidth(), _viBossBullet->img->getFrameHeight());

		if (WINSIZEY < _viBossBullet->y)
		{
			_viBossBullet = _vBossBullet.erase(_viBossBullet);
		}
		else if (0 > _viBossBullet->x)
		{
			_viBossBullet = _vBossBullet.erase(_viBossBullet);
		}
		else if (WINSIZEX < _viBossBullet->x)
		{
			_viBossBullet = _vBossBullet.erase(_viBossBullet);
		}
		else
		{
			_viBossBullet++;
		}
	}
}

void bullet::removeBullet(int arryNum)
{
	_vBossBullet.erase(_vBossBullet.begin() + arryNum);
}
