#pragma once

#include "gameNode.h"
#include "title.h"
#include "hero.h"
#include "bullet.h"
#include "mapManager.h"
#include "enemyManager.h"


class gameStudy : public gameNode
{
private:
	title* _title;
	mapManager* _mapManager;
	enemyManager* _enemyManager;
	hero* _hero;
	bullet* _bullet;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void mapChange();
};

