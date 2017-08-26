#pragma once
#include "enemy.h"

class bat : public enemy
{
protected:
	stENEMY Wallbat;

	int _moveY;
	int _maxMoveY;
	bool _isDown;

public:
	bat();
	~bat();

	virtual HRESULT init();
	virtual HRESULT init(int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();
	void frameCount();
	void move();

	virtual void setHp(int damage) { Wallbat.hp -= damage; }

	virtual RECT getRect() { return Wallbat.rc; }
	virtual stENEMY getEnemy() { return Wallbat; }
	virtual int getHp() { return Wallbat.hp; }
};

