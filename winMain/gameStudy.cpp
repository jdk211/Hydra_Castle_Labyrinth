#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init(true);
	//타이틀
	_title = new title;
	_title->init();
	////맵
	_mapManager = new mapManager;
	_mapManager->init();
	//히어로
	_hero = new hero;
	_hero->init();
	//적
	_enemyManager = new enemyManager;
	_enemyManager->init();
	//메모리 링크 
	//배경 RECT와 유저
	_hero->setWallMemoryLink(_mapManager->getWall());
	_mapManager->getWall()->setHeroMemoryLink(_hero);
	//유저와 적
	_hero->setEnemyMemoryLink(_mapManager->getEnemy());
	_mapManager->getEnemy()->setHeroMemoryLink(_hero);
	//총알
	_hero->setBulletMemoryLink(_enemyManager->getBullet());

	return S_OK;
}

void gameStudy::release()
{
	_title->release();
	SAFE_DELETE(_title);

	_mapManager->release();
	SAFE_DELETE(_mapManager);

	_hero->release();
	SAFE_DELETE(_hero);

	gameNode::release();
}

void gameStudy::update()
{
	if (_title->getStartExit() == 0)//select
	{
		_title->update();
	}
	else if (_title->getStartExit() == 1)//start
	{
		_title->release();
		_mapManager->update();
		_hero->update();
	}
	else if (_title->getStartExit() == 2)//exit
	{
		PostMessage(_hWnd, WM_DESTROY, 0, 0);
	}

	mapChange();

	gameNode::update();
}

void gameStudy::render( )
{
	//백버퍼에서 뿌려줌
	/*HDC backDC = this->getBackBuffer()->getMemDC();*/
	PatBlt( getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS );
	//============================================================
	//배경
	if (_title->getStartExit() == 0)
	{
		_title->render();
	}
	else if (_title->getStartExit() == 1)
	{
		_mapManager->render();
		_hero->render();
	}

	//TIMEMANAGER->render( getMemDC() );
	//============================================================
	//백버퍼에 있는 그림을 HDC에 그리자
	this->getBackBuffer()->render( getHDC(), 0, 0 );
}



