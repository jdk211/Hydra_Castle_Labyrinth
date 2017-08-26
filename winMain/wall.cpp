#include "stdafx.h"
#include "wall.h"
#include "hero.h"

wall::wall()
{
}


wall::~wall()
{
}

HRESULT wall::init()
{
	
	return S_OK;
}

HRESULT wall::init(char * mapName)
{
	_vWall.clear();
	if (mapName == "map01")
	{
		map01();
	}
	else if (mapName == "map02")
	{
		map02();
	}
	else if (mapName == "map03")
	{
		map03();
	}
	else if (mapName == "map04")
	{
		map04();
	}
	else if (mapName == "map05")
	{
		map05();
	}


	return S_OK;
}

void wall::release()
{
}

void wall::update()
{
}

void wall::render()
{
	/*for (_viWall = _vWall.begin(); _viWall != _vWall.end(); _viWall++)
	{
		Rectangle(getMemDC(), _viWall->rc.left, _viWall->rc.top, _viWall->rc.right, _viWall->rc.bottom);
	}*/
}

void wall::setRect(int x, int y, int width, int height, eRECTSTATE state)
{
	stRECT rcWall;

	ZeroMemory(&rcWall, sizeof(rcWall));

	rcWall.rc = RectMake(x, y, width, height);
	rcWall.state = state;

	_vWall.push_back(rcWall);
}