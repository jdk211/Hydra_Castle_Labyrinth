#pragma once
#include "gameNode.h"

struct stBULLET
{
	image* img;
	RECT rc;
	float angle;
	float x, y;
	float speed;
	float startX, startY;
	int radius;
	int count;
	bool fire;
};

class bullet : public gameNode
{
private:
	vector<stBULLET> _vBossBullet;
	vector<stBULLET>::iterator _viBossBullet;

public:
	bullet();
	~bullet();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameCount();
	void fire(float x, float y, float angle);
	void move();
	void removeBullet(int arryNum);

	vector<stBULLET> getVBullet() { return _vBossBullet; }
	vector<stBULLET>::iterator getVIBullet() { return _viBossBullet; }
	RECT getBulletRc() { return _viBossBullet->rc; }
};

