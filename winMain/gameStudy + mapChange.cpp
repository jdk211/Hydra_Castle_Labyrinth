#pragma once

#include "stdafx.h"
#include "gameStudy.h"

void gameStudy::mapChange()
{
	//01 -> 05
	if (_mapManager->getMapName() == "map01" && _hero->getHero().rc.left > WINSIZEX)
	{
		_mapManager->release();
		_mapManager->init("map05");
		_mapManager->setMapName("map05");
		_hero->setHeroXY(0, _hero->getHero().y);
	}
	//05 -> 01
	else if (_mapManager->getMapName() == "map05" && _hero->getHero().rc.right < 0)
	{
		_mapManager->release();
		_mapManager->init("map01");
		_mapManager->setMapName("map01");
		_hero->setHeroXY(WINSIZEX - _hero->getHero().img->getFrameWidth(), _hero->getHero().y);
	}
	//01 -> 02
	else if (_mapManager->getMapName() == "map01" && _hero->getHero().rc.right < 0)
	{
		_mapManager->release();
		_mapManager->init("map02");
		_mapManager->setMapName("map02");
		_hero->setHeroXY(WINSIZEX - _hero->getHero().img->getFrameWidth(), _hero->getHero().y);
	}
	//02 -> 01
	else if (_mapManager->getMapName() == "map02" && _hero->getHero().rc.left > WINSIZEX)
	{
		_mapManager->release();
		_mapManager->init("map01");
		_mapManager->setMapName("map01");
		_hero->setHeroXY(0,  _hero->getHero().y);
	}
	//02 -> 03
	else if (_mapManager->getMapName() == "map02" && _hero->getHero().rc.right < 0)
	{
		_mapManager->release();
		_mapManager->init("map03");
		_mapManager->setMapName("map03");
		_hero->setHeroXY(WINSIZEX - _hero->getHero().img->getFrameWidth(), _hero->getHero().y);
	}
	//03 -> 02
	else if (_mapManager->getMapName() == "map03" && _hero->getHero().rc.left > WINSIZEX)
	{
		_mapManager->release();
		_mapManager->init("map02");
		_mapManager->setMapName("map02");
		_hero->setHeroXY(0, _hero->getHero().y);
	}
	//03 -> 04
	else if (_mapManager->getMapName() == "map03" && _hero->getHero().rc.bottom < 0)
	{
		_mapManager->release();
		_mapManager->init("map04");
		_mapManager->setMapName("map04");
		_hero->setHeroRcNum(1);
		_hero->setHeroXY(_hero->getHero().x, WINSIZEY - 50);
	}
	//04 -> 03
	else if (_mapManager->getMapName() == "map04" && _hero->getHero().rc.top > WINSIZEY)
	{
		_mapManager->release();
		_mapManager->init("map03");
		_mapManager->setMapName("map03");
		_hero->setHeroXY(_hero->getHero().x, 0 - 50);
	}


}