#pragma once
#include "enemy.h"

class blue_slime : public enemy
{
protected:
	stENEMY blueSlime;

public:
	blue_slime();
	~blue_slime();

	virtual HRESULT init();
	virtual HRESULT init(int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();
	void frameCount();

	virtual void setHp(int damage) { blueSlime.hp -= damage; }

	virtual RECT getRect() { return blueSlime.rc; }
	virtual stENEMY getEnemy() { return blueSlime; }
	virtual int getHp() { return blueSlime.hp; }
};

