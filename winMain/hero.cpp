#include "stdafx.h"
#include "hero.h"
#include "wall.h"
#include "enemyManager.h"

hero::hero()
{
}

hero::~hero()
{
}

HRESULT hero::init()
{
	ZeroMemory(&_hero, sizeof(_hero));

	_hero.img = IMAGEMANAGER->addFrameImage("hero_run", "image/Hero/hero_run.bmp", 112, 112, 2, 2, true, RGB(0, 255, 0));
	_hero.x = CENTERX;
	_hero.y = 565;
	_hero.maxHp = 10;
	_hero.hp = _hero.maxHp;
	_hero.rc = RectMake(_hero.x, _hero.y, _hero.img->getFrameWidth(), _hero.img->getFrameHeight());
	_hero.state = IDLE;
	_hero.isRight = true;
	_hero.isAttack = false;
	_hero.isRun = false;
	_hero.isLadder = false;
	_hero.isDamage = false;
	_hero.jumpPow = 13.0f;
	_hero.gravity = 0.0f;

	_collisionPow = 15;
	_decearsePow = 1;

	_heroCount = 0;
	_damageCount = 0;

	_sword.img = IMAGEMANAGER->addFrameImage("sword", "image/Hero/sword_attack2.bmp", 200, 112, 4, 2, true, RGB(0, 255, 0));
	_sword.rc = RectMake(0, 0, 0, 0);
	_swordCount = 0;

	_wall = new wall;
	_wall->init();

	_hpBarBg.img = IMAGEMANAGER->addImage("hero_hpBar", "image/Hero/hero_hpBar.bmp", 492, 93, true, RGB(0, 255, 0));
	_hpBarBg.x = 20;
	_hpBarBg.y = 20;

	_hpProBar = new progressBar;
	_hpProBar->init(_hpBarBg.x, _hpBarBg.y, 387, 15);

	_enemyDie = IMAGEMANAGER->addFrameImage("dieEnemy", "image/Enemy/enemyDie.bmp", 960, 75, 10, 1, true, RGB(0, 255, 0));
	_isEnemyDie = false;
	_dieEnemyX = 0;
	_dieEnemyY = 0;
	_dieFrameCount = 0;

	return S_OK;
}

void hero::release()
{
	_wall->release();
	_hpProBar->release();
}

void hero::update()
{
	//유저 컨트롤
	action();
	jumpAction();
	//적과의 충돌
	enemyCollision();
	//프레임
	frameCount();
	//유저 HP바
	heroHp();
	//적 죽을시
	if (_isEnemyDie)
	{
		enemyDieEffect();
	}
	_hero.rc = RectMake(_hero.x + 5, _hero.y + 5, _hero.img->getFrameWidth() - 10, _hero.img->getFrameHeight() - 5);
}

void hero::render()
{
	if (_hero.isAttack)
	{
		//Rectangle(getMemDC(), _sword.rc.left, _sword.rc.top, _sword.rc.right, _sword.rc.bottom);
		//오른쪽
		if (_sword.img->getFrameY() == 0 && _sword.img->getFrameX() == 0)
		{
			_sword.img->frameRender(getMemDC(), _hero.x + 12, _hero.y - 26, _sword.img->getFrameX(), _sword.img->getFrameY());
		}
		else if(_sword.img->getFrameY() == 0 && _sword.img->getFrameX() != 0)
		{
			_sword.img->frameRender(getMemDC(), _hero.x + 50, _hero.y + 8, _sword.img->getFrameX(), _sword.img->getFrameY());
			//렉트 생성
			_sword.rc = RectMake(_hero.x + 50, _hero.y + 12, 40, 40);
		}
		//왼쪽
		else if (_sword.img->getFrameY() == 1 && _sword.img->getFrameX() == 0)
		{
			_sword.img->frameRender(getMemDC(), _hero.x - 3, _hero.y - 26, _sword.img->getFrameX(), _sword.img->getFrameY());
		}
		else if (_sword.img->getFrameY() == 1 && _sword.img->getFrameX() != 0)
		{
			_sword.img->frameRender(getMemDC(), _hero.x - 43, _hero.y + 8, _sword.img->getFrameX(), _sword.img->getFrameY());
			//렉트 생성
			_sword.rc = RectMake(_hero.x - 32, _hero.y + 12, 40, 40);
		}
		
	}
	else
	{
		_sword.rc = RectMake(0,0,0,0);
	}
	//유저 렉트
	//Rectangle(getMemDC(), _hero.rc.left, _hero.rc.top, _hero.rc.right, _hero.rc.bottom);

	_hero.img->frameRender(getMemDC(), _hero.x, _hero.y, _hero.img->getFrameX(), _hero.img->getFrameY());
	_hpBarBg.img->render(getMemDC(), _hpBarBg.x, _hpBarBg.y);
	_hpProBar->render();

	if (_isEnemyDie)
	{
		_enemyDie->frameRender(getMemDC(), _dieEnemyX, _dieEnemyY, _enemyDie->getFrameX(), 0);
	}
	

	/*char str2[128];
	sprintf_s(str2, "user Hp : %d", _hero.hp);
	TextOut(getMemDC(), 0, 80, str2, strlen(str2));

	char str[128];
	sprintf_s(str, "monster : %d", _enemyManager->getVEnemy().size());
	TextOut(getMemDC(), 0, 100, str, strlen(str));*/
}