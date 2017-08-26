#pragma once
#include "gameNode.h"
#include "progressBar.h"

class wall;
class enemyManager;
class bullet;

enum eJUMPSTATE
{
	IDLE,
	RUN,
	JUMP_UP,
	JUMP_DOWN,
	LADDER_UP,
	LADDER_DOWN,
	AIR
};

enum DIRECT
{
	LEFT,
	RIGHT
};

struct stHERO
{
	RECT rc;

	image* img;
	int maxHp;
	int hp;
	int rcNum;
	float x, y;
	float moveSpd;
	float jumpPow;
	float gravity;
	bool isRight;
	bool isRun;
	bool isAttack;
	bool isLadder;
	bool isDamage;
	eJUMPSTATE state;
};

struct stSWORD
{
	RECT rc;
	image* img;
};

struct stHPBAR
{
	image* img;
	int x, y;
};

class hero : public gameNode
{
private:
	stHERO _hero;
	stSWORD _sword;

	wall* _wall;
	enemyManager* _enemyManager;
	
	stHPBAR _hpBarBg;
	progressBar* _hpProBar;

	bullet* _bullet;

	int _heroCount;
	int _swordCount;
	int _damageCount;
	
	int _collisionPow;
	int _decearsePow;
	DIRECT _collisionDirect;

	image* _enemyDie;
	bool _isEnemyDie;
	int _dieEnemyX;
	int _dieEnemyY;
	int _dieFrameCount;

public:
	hero();
	~hero();

	HRESULT init();
	void release();
	void update();
	void render();

	void action();
	void jump();
	void jumpAction();
	void frameCount();
	void enemyDieEffect();
	void enemyCollision();
	void heroHp();
	void hitDamage(int i);

	void setHeroXY(float x, float y) { _hero.x = x, _hero.y = y; }
	void setHeroIsDamage(bool damage) { _hero.isDamage = damage; }
	void setHeroRcNum(int rcNum) { _hero.rcNum = rcNum; }

	void setWallMemoryLink(wall* wall) { _wall = wall; }
	void setEnemyMemoryLink(enemyManager* enemyManager) { _enemyManager = enemyManager; }
	void setBulletMemoryLink(bullet* bullet) { _bullet = bullet; }
	void setDirect(DIRECT direct) { _collisionDirect = direct; }
	stHERO getHero() { return _hero; }
	RECT getHeroRc() { return _hero.rc; }
	float getHeroX() { return _hero.x; }
	float getHeroY() { return _hero.y; }
};

