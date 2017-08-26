#pragma once

#include "stdafx.h"
#include "hero.h"
#include "wall.h"

void hero::action()
{
	//이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !_hero.isDamage)
	{
		_hero.isRight = false;
		_hero.isRun = true;
		_hero.x -= 5.0f;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !_hero.isDamage)
	{
		_hero.isRight = true;
		_hero.isRun = true;
		_hero.x += 5.0f;
	}
	
	if (_hero.isLadder)
	{
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_hero.y -= 2.0f;
			_hero.state = LADDER_UP;
			_hero.gravity = 0.0f;
			_hero.jumpPow = 0.0f;
		}
		else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_hero.y += 2.0f;
			_hero.state = LADDER_DOWN;
			_hero.gravity = 0.0f;
			_hero.jumpPow = 0.0f;
		}
	}
	
	//점프 x0x58
	if (KEYMANAGER->isOnceKeyDown('X') && !_hero.isDamage  && _hero.state != AIR)
	{
		jump();
	}

	//공격 z0x5A
	if (KEYMANAGER->isOnceKeyDown('Z') && !_hero.isAttack && _hero.state != LADDER_UP && !_hero.isDamage)
	{
		_hero.isAttack = true;
	}

	//IDLE 상태
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_hero.isRun = false;
	}

}

void hero::jump()
{
	if (_hero.state == JUMP_UP || _hero.state == JUMP_DOWN) return;

	_hero.state = JUMP_UP;
}

void hero::jumpAction()
{
	if (_hero.state == JUMP_UP || _hero.state == JUMP_DOWN)
	{
		_hero.gravity += 0.5f;
		_hero.jumpPow = 13.f;
		_hero.y -= (_hero.jumpPow - _hero.gravity);

		if (_hero.jumpPow < _hero.gravity)
		{
			_hero.state = JUMP_DOWN;
		}
	}
	else if (_hero.state == AIR)
	{
		_hero.gravity += 0.4f;
		_hero.y += _hero.gravity;
	}

	for (int i = 0; i < _wall->getvWall().size(); i++)
	{
		RECT rc;
		if (IntersectRect(&rc, &_hero.rc, &_wall->getvWall()[i].rc))
		{
			if (rc.top == _wall->getvWall()[i].rc.top &&
				(_hero.rc.left > _wall->getvWall()[i].rc.left && _hero.rc.left < _wall->getvWall()[i].rc.right ||
					_hero.rc.right > _wall->getvWall()[i].rc.left && _hero.rc.right < _wall->getvWall()[i].rc.right)
				&& _wall->getvWall()[i].state == WALL && _hero.state != LADDER_UP)
			{
				_hero.rcNum = i;
				_hero.y -= rc.bottom - rc.top;
				_hero.state = IDLE;
				_hero.gravity = 0.0f;
			}
			else if (_hero.rc.bottom >= _wall->getvWall()[i].rc.bottom && _wall->getvWall()[i].state == WALL)
			{
				_hero.y += rc.bottom - rc.top;
			}
			else if (_hero.rc.right <= _wall->getvWall()[i].rc.right && _wall->getvWall()[i].state == WALL)
			{
				_hero.x -= rc.right - rc.left;
			}
			else if (_hero.rc.left >= _wall->getvWall()[i].rc.left && _wall->getvWall()[i].state == WALL)
			{
				_hero.x += rc.right - rc.left;
			}

			if (PtInRect(&_wall->getvWall()[i].rc, pointMake(_hero.x + (_hero.img->getFrameWidth() / 2), (_hero.y + _hero.img->getFrameHeight() - 10))) &&
				(_hero.rc.left > _wall->getvWall()[i].rc.left && _hero.rc.left < _wall->getvWall()[i].rc.right ||
					_hero.rc.right > _wall->getvWall()[i].rc.left && _hero.rc.right < _wall->getvWall()[i].rc.right) &&
				_wall->getvWall()[i].state == LADDER)
			{
				_hero.isLadder = true;
				_hero.rcNum = i;
				if (_hero.state == LADDER_UP || _hero.state == LADDER_DOWN)
				{
					_hero.x = _wall->getvWall()[_hero.rcNum].rc.left + 10;
				}
			}
			else
			{
				_hero.isLadder = false;
			}
		}
		else if (_hero.state != JUMP_UP && _hero.state != JUMP_DOWN &&
			(_hero.rc.right < _wall->getvWall()[_hero.rcNum].rc.left || _hero.rc.left > _wall->getvWall()[_hero.rcNum].rc.right))
		{
			_hero.state = AIR;
		}
	}
}