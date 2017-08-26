#pragma once
#include "enemy.h"
class red_worm : public enemy
{
protected:
	stENEMY _worm;

	int _moveX;
	int _maxMoveX;
	bool _isRight;

public:
	red_worm();
	~red_worm();

	virtual HRESULT init();
	virtual HRESULT init(int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();
	void frameCount();
	void move();

	virtual void setHp(int damage) { _worm.hp -= damage; }

	virtual RECT getRect() { return _worm.rc; }
	virtual stENEMY getEnemy() { return _worm; }
	virtual int getHp() { return _worm.hp; }
};

