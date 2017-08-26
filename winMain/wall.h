#pragma once
#include "gameNode.h"

class hero;

enum eRECTSTATE
{
	WALL,
	LADDER,
	WARP
};

struct stRECT
{
	RECT rc;
	eRECTSTATE state;
};

class wall : public gameNode
{
private:
	vector<stRECT> _vWall;
	vector<stRECT>::iterator _viWall;

	hero* _hero;

public:
	wall();
	~wall();

	HRESULT init();
	HRESULT init(char* mapName);
	void release();
	void update();
	void render();

	void setRect(int x, int y, int width, int height, eRECTSTATE state = WALL);
	void setHeroMemoryLink(hero* hero) { _hero = hero; }

	vector<stRECT> getvWall() { return _vWall; }
	vector<stRECT>::iterator getviWall() { return _viWall; }

	void map01();
	void map02();
	void map03();
	void map04();
	void map05();
};