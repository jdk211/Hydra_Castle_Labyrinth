#pragma once
#include "gameNode.h"
#include "wall.h"
#include "enemyManager.h"

class mapManager : public gameNode
{
private:
	image* _mapImg;
	char* _mapName;

	wall* _wall;
	enemyManager* _enemyManager;

public:
	mapManager();
	~mapManager();

	HRESULT init();
	HRESULT init(char* mapName);
	void release();
	void update();
	void render();

	void setMapName(char* mapName) { _mapName = mapName; }

	char* getMapName() { return _mapName; }
	wall* getWall() { return _wall; }
	enemyManager* getEnemy() { return _enemyManager; }
};

