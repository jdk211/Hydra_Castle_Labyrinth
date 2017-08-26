#include "stdafx.h"
#include "enemyManager.h"
#include "hero.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	return S_OK;
}

HRESULT enemyManager::init(char * mapName)
{
	_vEnemy.clear();
	_mapName = mapName;
	setEnemy(mapName);

	_bullet = new bullet;
	_bullet->init();

	return S_OK;
}

void enemyManager::release()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); _viEnemy++)
	{
		SAFE_DELETE((*_viEnemy));
	}
}

void enemyManager::update()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); _viEnemy++)
	{
		(*_viEnemy)->update();
	}
	enemyBulletFire();
	collisionBulletHero();
	_bullet->update();
}

void enemyManager::render()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); _viEnemy++)
	{
		//Rectangle(getMemDC(), (*_viEnemy)->getRect().left, (*_viEnemy)->getRect().top, (*_viEnemy)->getRect().right, (*_viEnemy)->getRect().bottom);
		(*_viEnemy)->render();
	}
	_bullet->render();
}

void enemyManager::collisionBulletHero()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		RECT rc;
		if (IntersectRect(&rc, &_bullet->getVBullet()[i].rc, &_hero->getHeroRc()))
		{
			_hero->hitDamage(1);
			_bullet->removeBullet(i);
			if (rc.left == _hero->getHeroRc().left)
			{
				_hero->setDirect(LEFT);
			}
			else
			{
				_hero->setDirect(RIGHT);
			}
			_hero->setHeroIsDamage(true);
			
			break;
		}
	}
}

void enemyManager::enemyBulletFire()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); _viEnemy++)
	{
		if ((*_viEnemy)->bulletFire())
		{
			RECT enemyRc = (*_viEnemy)->getRect();
			RECT heroRc = _hero->getHeroRc();
			_bullet->fire(enemyRc.left + ((enemyRc.right - enemyRc.left) / 2), enemyRc.top + ((enemyRc.bottom - enemyRc.top) / 2),
			MY_UTIL::getAngle(enemyRc.left + ((enemyRc.right - enemyRc.left) / 2), enemyRc.top + ((enemyRc.bottom - enemyRc.top) / 2),
								heroRc.left + ((heroRc.right - heroRc.left) / 2), heroRc.top + ((heroRc.bottom - heroRc.top) / 2)));
		}
	}
}

void enemyManager::removeEnemy(int arryNum)
{
	SAFE_DELETE(_vEnemy[arryNum]);
	_vEnemy.erase(_vEnemy.begin() + arryNum);
}

void enemyManager::setEnemy(char* mapName)
{
	if (mapName == "map01")
	{
		
	}
	else if (mapName == "map02")
	{
		blue_slime* blueSlime;
		blueSlime = new blue_slime;
		blueSlime->init(700, 580);
		_vEnemy.push_back(blueSlime);

		blue_slime* blueSlime2;
		blueSlime2 = new blue_slime;
		blueSlime2->init(750, 580);
		_vEnemy.push_back(blueSlime2);

		bat* wallBat;
		wallBat = new bat;
		wallBat->init(280, 140);

		_vEnemy.push_back(wallBat);
	}
	else if (mapName == "map03")
	{
		bat* wallBat;
		wallBat = new bat;
		wallBat->init(550, 405);

		_vEnemy.push_back(wallBat);

		bat* wallBat2;
		wallBat2 = new bat;
		wallBat2->init(620, 135);

		_vEnemy.push_back(wallBat2);

		bat* wallBat3;
		wallBat3 = new bat;
		wallBat3->init(690, 135);

		_vEnemy.push_back(wallBat3);
	}
	else if (mapName == "map04")
	{
		red_worm* worm1;
		worm1 = new red_worm;
		worm1->init(345, 446);
		_vEnemy.push_back(worm1);

		red_worm* worm2;
		worm2 = new red_worm;
		worm2->init(550, 309);
		_vEnemy.push_back(worm2);
	}
	else if (mapName == "map05")
	{
		batBoss* batMan;
		batMan = new batBoss;
		batMan->init(275, 200);
		_vEnemy.push_back(batMan);
	}
	
}
