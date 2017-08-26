#pragma once

#include "stdafx.h"
#include "hero.h"
#include "enemyManager.h"

void hero::enemyCollision()
{
	//공격시 적과 충돌하면
	if (_hero.isAttack)
	{
		for (int i = 0; i < _enemyManager->getVEnemy().size(); i++)
		{
			RECT rc2;
			if (IntersectRect(&rc2, &_sword.rc, &_enemyManager->getVEnemy()[i]->getRect()))
			{
				_enemyManager->getVEnemy()[i]->setHp(1);
				_hero.isAttack = false;
			}
			if (_enemyManager->getVEnemy()[i]->getHp() == 0)
			{
				_dieEnemyX = _enemyManager->getVEnemy()[i]->getEnemy().x - 15;
				_dieEnemyY = _enemyManager->getVEnemy()[i]->getEnemy().y - 15;
				_isEnemyDie = true;
				_enemyManager->removeEnemy(i);
			}
		}
	}
	//적과 유저가 충돌하면
	for (int i = 0; i < _enemyManager->getVEnemy().size(); i++)
	{
		RECT rc1;
		if (IntersectRect(&rc1, &_hero.rc, &_enemyManager->getVEnemy()[i]->getRect()))
		{
			if (!_hero.isDamage)
			{
				_hero.hp--;
				_hero.isDamage = true;
				if (_hero.hp <= 0)
				{
					_hero.hp = 0;
				}
			}

			if (rc1.left == _hero.rc.left)
			{
				_collisionDirect = LEFT;
			}
			else if (rc1.right == _hero.rc.right)
			{
				_collisionDirect = RIGHT;
			}

			break;
		}
	}

	if (_hero.isDamage)
	{
		if (_collisionDirect == LEFT)
		{
			_collisionPow -= _decearsePow;
			_hero.x += _collisionPow;
		}
		else if (_collisionDirect == RIGHT)
		{
			_collisionPow -= _decearsePow;
			_hero.x -= _collisionPow;
		}
		if (_collisionPow == 0)
		{
			_hero.img->setFrameX(0);
			_hero.isDamage = false;
			_collisionPow = 15;
			_decearsePow = 1;
		}
	}
}
//체력바 위치
void hero::heroHp()
{

	if (_hero.y >= CENTERY)
	{
		_hpBarBg.y = 20;
	}
	else
	{
		_hpBarBg.y = 700;
	}

	_hpProBar->setX(_hpBarBg.x + 102);
	_hpProBar->setY(_hpBarBg.y + 2);
	_hpProBar->setGauge(_hero.hp, _hero.maxHp);
	_hpProBar->update();
}

void hero::hitDamage(int i)
{
	_hero.hp -= i;
}
