#include "stdafx.h"
#include "mapManager.h"


mapManager::mapManager()
{
}


mapManager::~mapManager()
{
}

HRESULT mapManager::init()
{
	IMAGEMANAGER->addImage("map01", "image/Map/map01.bmp", 1100, 825, false, false);
	IMAGEMANAGER->addImage("map02", "image/Map/map02.bmp", 1100, 825, false, false);
	IMAGEMANAGER->addImage("map03", "image/Map/map03.bmp", 1100, 825, false, false);
	IMAGEMANAGER->addImage("map04", "image/Map/map04.bmp", 1100, 825, false, false);
	IMAGEMANAGER->addImage("map05", "image/Map/map05.bmp", 1100, 825, false, false);

	//���� ��ġ
	_mapName = "map01";
	_mapImg = IMAGEMANAGER->findImage(_mapName);
	//���� RECT
	_wall = new wall;
	_wall->init(_mapName);
	//�ʿ� ���� �� ��
	_enemyManager = new enemyManager;
	_enemyManager->init(_mapName);

	return S_OK;
}

HRESULT mapManager::init(char * mapName)
{
	_mapImg = IMAGEMANAGER->findImage(mapName);
	_wall->init(mapName);
	_enemyManager->init(mapName);

	return S_OK;
}

void mapManager::release()
{
	_wall->release();
	_enemyManager->release();
}

void mapManager::update()
{
	_enemyManager->update();
}

void mapManager::render()
{
	_mapImg->render(getMemDC());
	_wall->render();
	_enemyManager->render();

	/*char* str;
	str = _mapName;
	TextOut(getMemDC(), 0, 60, str, strlen(str));*/
}

