#pragma once

#include "stdafx.h"
#include "hero.h"

void hero::frameCount()
{
	//Attack 경우 이미지, 아닐경우 이미지 설정
	//점프하면서 공격할 경우
	if (_hero.isAttack)
	{
		_hero.img = IMAGEMANAGER->addFrameImage("hero_attack", "image/Hero/hero_attack.bmp", 174, 110, 3, 2, true, RGB(0, 255, 0));
	}
	else if ((!_hero.isAttack && _hero.isRun && !_hero.isDamage) || _hero.state == IDLE)
	{
		_hero.img = IMAGEMANAGER->addFrameImage("hero_run", "image/Hero/hero_run.bmp", 112, 112, 2, 2, true, RGB(0, 255, 0));
	}
	//점프하면서 공격안할 경우
	if ((_hero.state == JUMP_UP || _hero.state == JUMP_DOWN || _hero.state == AIR) && !_hero.isAttack && !_hero.isDamage)
	{
		_hero.img = IMAGEMANAGER->addFrameImage("hero_jump", "image/Hero/hero_jump.bmp", 112, 112, 2, 2, true, RGB(0, 255, 0));
	}
	//올라가는 경우
	if (_hero.state == LADDER_UP || _hero.state == LADDER_DOWN && !_hero.isDamage)
	{
		_hero.img = IMAGEMANAGER->addFrameImage("hero_ladder", "image/Hero/hero_ladder.bmp", 250, 106, 5, 2, true, RGB(0, 255, 0));
	}
	if (_hero.isDamage)
	{
		_hero.img = IMAGEMANAGER->addFrameImage("hero_damage", "image/Hero/hero_damage.bmp", 118, 118, 3, 2, true, RGB(0, 255, 0));
	}


	//Attack이 아닌 경우
	if (_hero.state != LADDER_UP && _hero.state != LADDER_DOWN)
	{
		//보고있는 시점 (오른쪽, 왼쪽) 프레임Y 설정
		if (_hero.isRight)
		{
			_hero.img->setFrameY(0);
			_sword.img->setFrameY(0);
		}
		else if (!_hero.isRight)
		{
			_hero.img->setFrameY(1);
			_sword.img->setFrameY(1);
		}
	}

	if (!_hero.isAttack)
	{
		if (_hero.state != LADDER_UP && _hero.state != LADDER_DOWN && !_hero.isDamage)
		{
			//state에 따른 프레임 움직임
			//가만히 있을 경우
			if (!_hero.isRun)
			{
				_hero.img->setFrameX(0);
			}
			//움질일 때
			else if (_hero.isRun)
			{
				_heroCount++;
				if ((_heroCount % 10 == 0))
				{
					if (_hero.img->getFrameX() >= _hero.img->getMaxFrameX())
					{
						_hero.img->setFrameX(0);
						_hero.isAttack = false;
					}
					else
					{
						_hero.img->setFrameX(_hero.img->getFrameX() + 1);
					}
					_heroCount = 0;
				}
			}
			//점프했을 경우 
			if (_hero.state == JUMP_UP)
			{
				_hero.img->setFrameX(0);
			}
			else if (_hero.state == JUMP_DOWN || _hero.state == AIR)
			{
				_hero.img->setFrameX(1);
			}
		}
		//사다리를 오를 경우
		else if (_hero.state == LADDER_UP || _hero.state == LADDER_DOWN)
		{
			if (_hero.img->getFrameY() == 0)
			{
				_heroCount++;
				if ((_heroCount % 10 == 0))
				{
					if (_hero.img->getFrameX() >= _hero.img->getMaxFrameX())
					{
						_hero.img->setFrameX(0);
						_hero.img->setFrameY(_hero.img->getMaxFrameY());
					}
					else
					{
						_hero.img->setFrameX(_hero.img->getFrameX() + 1);
					}
					_heroCount = 0;
				}
			}
			else if (_hero.img->getFrameY() == 1)
			{
				_heroCount++;
				if ((_heroCount % 10 == 0))
				{
					if (_hero.img->getFrameX() >= _hero.img->getMaxFrameX())
					{
						_hero.img->setFrameX(0);
						_hero.img->setFrameY(0);
					}
					else
					{
						_hero.img->setFrameX(_hero.img->getFrameX() + 1);
					}
					_heroCount = 0;
				}
			}
		}
		//damage입었을 경우
		else if (_hero.isDamage)
		{
			_heroCount++;
			if ((_heroCount % 5 == 0))
			{
				if (_hero.img->getFrameX() >= _hero.img->getMaxFrameX())
				{
					_hero.img->setFrameX(_hero.img->getMaxFrameX());
				}
				else
				{
					_hero.img->setFrameX(_hero.img->getFrameX() + 1);
				}
				_heroCount = 0;
			}
		}
	}
	//Attack 할 경우
	else
	{
		if (_hero.state == LADDER_UP || _hero.state == LADDER_DOWN)
		{
			_hero.isAttack = false;
		}
		_heroCount++;
		_swordCount++;
		if ((_heroCount % 8 == 0))
		{
			if (_hero.img->getFrameX() >= _hero.img->getMaxFrameX())
			{
				_hero.img->setFrameX(0);
				_sword.img->setFrameX(0);
				_hero.isAttack = false;
			}
			else
			{
				_hero.img->setFrameX(_hero.img->getFrameX() + 1);
			}
			_heroCount = 0;
		}
		//Attack 할 경우 Sword의 프레임 증가
		if ((_swordCount % 7 == 0))
		{
			if (_sword.img->getFrameX() >= _sword.img->getMaxFrameX())
			{
				_sword.img->setFrameX(_sword.img->getMaxFrameX());
			}
			else
			{
				_sword.img->setFrameX(_sword.img->getFrameX() + 1);
			}
		}
	}
}

void hero::enemyDieEffect()
{
	_dieFrameCount++;
	if (_dieFrameCount % 3 == 0)
	{
		if (_enemyDie->getFrameX() >= _enemyDie->getMaxFrameX())
		{
			_enemyDie->setFrameX(0);
			_isEnemyDie = false;
		}
		else
		{
			_enemyDie->setFrameX(_enemyDie->getFrameX() + 1);
		}
	}
}
