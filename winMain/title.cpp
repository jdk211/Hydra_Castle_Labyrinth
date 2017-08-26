#include "stdafx.h"
#include "title.h"


title::title()
{
}


title::~title()
{
}

HRESULT title::init()
{
	//selectBox �̹����� ��ġ
	_selectBox.img = IMAGEMANAGER->addImage("select", "image/Title/title_select.bmp", 326, 41, true, RGB(0, 255, 0));
	_selectBox.x = 392;
	_selectBox.y = 487;

	//title �̹����� ��Ʈ ��ġ
	_gameTitle = IMAGEMANAGER->addImage("title", "image/Title/title.bmp", 450, 500, true, RGB(0, 255, 0));
	_rc[START] = RectMake(392, 487, _selectBox.img->getWidth(), _selectBox.img->getHeight());
	_rc[EXIT] = RectMake(392, 568, _selectBox.img->getWidth(), _selectBox.img->getHeight());

	_isStart = 0;

	return S_OK;
}

void title::release()
{
}

void title::update()
{
	//select Box �̵��ؼ� game start�� exit ����
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_selectBox.y = 487; //start
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_selectBox.y = 568; //exit
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_selectBox.y == 487) { _isStart = 1; } //start
		else { _isStart = 2; } //exit
	}
}

void title::render()
{
	/*for (int i = 1; i < STATE_END; i++)
	{
		Rectangle(getMemDC(), _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
	}*/
	//�̹��� �׸���
	_selectBox.img->render(getMemDC(), _selectBox.x, _selectBox.y);
	_gameTitle->render(getMemDC(), 330, 150);
}
