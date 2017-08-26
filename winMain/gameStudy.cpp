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
	//Ÿ��Ʋ
	_title = new title;
	_title->init();
	////��
	_mapManager = new mapManager;
	_mapManager->init();
	//�����
	_hero = new hero;
	_hero->init();
	//��
	_enemyManager = new enemyManager;
	_enemyManager->init();
	//�޸� ��ũ 
	//��� RECT�� ����
	_hero->setWallMemoryLink(_mapManager->getWall());
	_mapManager->getWall()->setHeroMemoryLink(_hero);
	//������ ��
	_hero->setEnemyMemoryLink(_mapManager->getEnemy());
	_mapManager->getEnemy()->setHeroMemoryLink(_hero);
	//�Ѿ�
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
	//����ۿ��� �ѷ���
	/*HDC backDC = this->getBackBuffer()->getMemDC();*/
	PatBlt( getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS );
	//============================================================
	//���
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
	//����ۿ� �ִ� �׸��� HDC�� �׸���
	this->getBackBuffer()->render( getHDC(), 0, 0 );
}



