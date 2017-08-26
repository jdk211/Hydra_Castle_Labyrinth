#include "stdafx.h"
#include "blue_slime.h"


blue_slime::blue_slime()
{
}


blue_slime::~blue_slime()
{
}

HRESULT blue_slime::init()
{
	return S_OK;
}

HRESULT blue_slime::init(int x, int y)
{

	blueSlime.img = IMAGEMANAGER->addFrameImage("blue_slime", "image/Enemy/blue_slime.bmp", 420, 39, 7, 1, true, RGB(0, 255, 0));
	blueSlime.hp = 1;
	blueSlime.x = x;
	blueSlime.y = y;
	blueSlime.isBoss = false;
	blueSlime.rc = RectMake(blueSlime.x + 12, blueSlime.y + 15, blueSlime.img->getFrameWidth() - 24, blueSlime.img->getFrameHeight() - 15);

	return S_OK;
}

void blue_slime::release()
{
}

void blue_slime::update()
{
	frameCount();
}

void blue_slime::render()
{
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	blueSlime.img->frameRender(getMemDC(), blueSlime.x, blueSlime.y, blueSlime.img->getFrameX(), blueSlime.img->getFrameY());
}

void blue_slime::frameCount()
{
	blueSlime.count++;
	if (blueSlime.count % 7 == 0)
	{
		if (blueSlime.img->getFrameX() >= blueSlime.img->getMaxFrameX())
		{
			blueSlime.img->setFrameX(0);
		}
		else
		{
			blueSlime.img->setFrameX(blueSlime.img->getFrameX() + 1);
		}
		blueSlime.count = 0;
	}
}
