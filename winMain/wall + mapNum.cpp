#pragma once
#include "stdafx.h"

#include "wall.h"

void wall::map01()
{
	//�عٴ�
	setRect(0, 620, WINSIZEX, 250);
	//�� ����
	setRect(0, 0, 340, 130);
	//�� ������
	setRect(482, 0, 620, 130);
	//�浹 �˻�
	//setRect(400, 400, 50, 100);
	//��ٸ� �˻�
	//setRect(550, 346, 69, 275, LADDER);
}

void wall::map02()
{
	//�عٴ� ������
	setRect(278, 620, 825, 250);
	//�عٴ� �ަU
	setRect(0, 620, 205, 250);
	//��� ����
	setRect(0, 346, 550, 62);
	//��� ������
	setRect(620, 346, 133, 62);
	//��
	setRect(0, 0, WINSIZEX, 130);

	//������ ��ٸ�
	setRect(550, 336, 70, 275, LADDER);
	//���� ��ٸ�
	setRect(206, 610, 70, 275, LADDER);
}

void wall::map03()
{
	//�عٴ�
	setRect(0, 620, 1100, 250);
	//����
	setRect(0, 350, 478, 290);
	//���
	setRect(0, 344, 1100, 66);
	//����
	setRect(0, 100, 65, 300);
	//�� ����
	setRect(0, 0, 346, 133);
	//�� ������
	setRect(412, 0, 700, 133);
	//��ٸ�
	setRect(345, -60, 70, 410, LADDER);
}

void wall::map04()
{
	//�عٴ� ������
	setRect(415, 752, 805, 100);
	//��ٸ�
	setRect(345, 742, 70, 150, LADDER);
	//�عٴ� ����
	setRect(0, 752, 347, 100);
	//���� �ö󰥰�
	setRect(0, 617, 203, 210);
	//���� ���
	setRect(0, 0, 67, 825);
	//���� ��
	setRect(0, 0, 132, 130);
	//�� ������
	setRect(276, 0, 135, 132);
	//�� �� ������
	setRect(276, 0, 617, 57);
	//��ٸ�
	setRect(893, -50, 70, 253, LADDER);
	//��ٸ� ��
	setRect(755, 202, 291, 67);
	//�� ������
	setRect(963, 0, 135, 56);
	//������ ���
	setRect(1035, 0, 100, 825);

	//�ö� �Ʒ� ����	
	setRect(345, 478, 135, 65);
	//�� ����
	setRect(551, 341, 135, 65);
}

void wall::map05()
{
	//�عٴ�
	setRect(0, 630, WINSIZEX, 250);
	//��
	setRect(0, 0, WINSIZEX, 160);
	//����
	setRect(0, 0, 96, 487);
	//������
	setRect(1000, 0, 110, WINSIZEY);
}
