#pragma once
#include "gameNode.h"

enum eSELECTSTATE
{
	START = 1,
	EXIT,
	STATE_END
};

struct stSELBOX
{
	image* img;
	int x, y;
};

class title : public gameNode
{
private :
	image* _gameTitle;
	stSELBOX _selectBox;
	RECT _rc[STATE_END];

	int _isStart;

public:
	title();
	~title();

	HRESULT init();
	void release();
	void update();
	void render();

	int getStartExit() { return _isStart; }
};

