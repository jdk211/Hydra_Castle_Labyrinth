#pragma once
#include "stdafx.h"

#include "wall.h"

void wall::map01()
{
	//밑바닥
	setRect(0, 620, WINSIZEX, 250);
	//위 왼쪽
	setRect(0, 0, 340, 130);
	//위 오른쪽
	setRect(482, 0, 620, 130);
	//충돌 검사
	//setRect(400, 400, 50, 100);
	//사다리 검사
	//setRect(550, 346, 69, 275, LADDER);
}

void wall::map02()
{
	//밑바닥 오른쪽
	setRect(278, 620, 825, 250);
	//밑바닥 왼쪾
	setRect(0, 620, 205, 250);
	//가운데 왼쪽
	setRect(0, 346, 550, 62);
	//가운데 오른쪽
	setRect(620, 346, 133, 62);
	//위
	setRect(0, 0, WINSIZEX, 130);

	//오른쪽 사다리
	setRect(550, 336, 70, 275, LADDER);
	//왼쪽 사다리
	setRect(206, 610, 70, 275, LADDER);
}

void wall::map03()
{
	//밑바닥
	setRect(0, 620, 1100, 250);
	//사이
	setRect(0, 350, 478, 290);
	//가운데
	setRect(0, 344, 1100, 66);
	//사이
	setRect(0, 100, 65, 300);
	//위 왼쪽
	setRect(0, 0, 346, 133);
	//위 오른쪽
	setRect(412, 0, 700, 133);
	//사다리
	setRect(345, -60, 70, 410, LADDER);
}

void wall::map04()
{
	//밑바닥 오른쪽
	setRect(415, 752, 805, 100);
	//사다리
	setRect(345, 742, 70, 150, LADDER);
	//밑바닥 왼쪽
	setRect(0, 752, 347, 100);
	//왼쪽 올라갈곳
	setRect(0, 617, 203, 210);
	//왼쪽 기둥
	setRect(0, 0, 67, 825);
	//왼쪽 위
	setRect(0, 0, 132, 130);
	//위 오른쪽
	setRect(276, 0, 135, 132);
	//위 긴 오른쪽
	setRect(276, 0, 617, 57);
	//사다리
	setRect(893, -50, 70, 253, LADDER);
	//사다리 밑
	setRect(755, 202, 291, 67);
	//맨 오른쪽
	setRect(963, 0, 135, 56);
	//오른쪽 기둥
	setRect(1035, 0, 100, 825);

	//올라갈 아래 발판	
	setRect(345, 478, 135, 65);
	//위 발판
	setRect(551, 341, 135, 65);
}

void wall::map05()
{
	//밑바닥
	setRect(0, 630, WINSIZEX, 250);
	//위
	setRect(0, 0, WINSIZEX, 160);
	//왼쪽
	setRect(0, 0, 96, 487);
	//오른쪽
	setRect(1000, 0, 110, WINSIZEY);
}
