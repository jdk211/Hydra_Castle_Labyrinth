#pragma once
#include "gameNode.h"

struct stENEMY
{
	image* img;
	RECT rc;
	int hp;
	int x, y;
	int count;
	bool isBoss;
};

class enemy : public gameNode
{
protected:
	stENEMY _enemy;

public:
	enemy();
	~enemy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void frameCount();
	virtual bool bulletFire();

	virtual void setHp(int damage) { _enemy.hp -= damage; }

	virtual RECT getRect() { return _enemy.rc; }
	virtual image* getEnemyImg() { return _enemy.img; }
	virtual stENEMY getEnemy() { return _enemy; }
	virtual int getHp() { return _enemy.hp; }
};

