#pragma once
#include "enemy.h"
#include "bullet.h"

class batBoss : public enemy
{
private:
	stENEMY _batBoss;

	int _moveY, _moveX;
	int _maxMoveY, _maxMoveX;
	bool _isDown;
	bool _isRight;

	bullet* _bossBullet;
	float _bulletTimer;

public:
	batBoss();
	~batBoss();

	virtual HRESULT init();
	virtual HRESULT init(int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void frameCount();
	virtual void move();
	virtual bool bulletFire();

	virtual void setHp(int damage) { _batBoss.hp -= damage; }

	virtual RECT getRect() { return _batBoss.rc; }
	virtual image* getEnemyImg() { return _batBoss.img; }
	virtual stENEMY getEnemy() { return _batBoss; }
	virtual int getHp() { return _batBoss.hp; }
	virtual bullet* getBullet() { return _bossBullet; }
};

