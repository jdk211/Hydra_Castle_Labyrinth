#pragma once
#include "gameNode.h"
#include "bullet.h"
#include "blue_slime.h"
#include "red_worm.h"
#include "bat.h"
#include "batBoss.h"

class hero;

class enemyManager : public gameNode
{
private: 
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

private:
	vEnemy _vEnemy;
	viEnemy _viEnemy;

	bullet* _bullet;
	hero* _hero;
	char* _mapName;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	HRESULT init(char* mapName);
	void release();
	void update();
	void render();
	
	void collisionBulletHero();
	void enemyBulletFire();
	void removeEnemy(int arryNum);

	void setEnemy(char* mapName);

	inline bullet* getBullet() { return _bullet; }
	inline vector<enemy*> getVEnemy() { return _vEnemy; }
	inline vector<enemy*>::iterator getVIEnemy() { return _viEnemy; }

	inline void setHeroMemoryLink(hero* hero) { _hero = hero; }

};

