// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

/* #### ������� #### */
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN //MFC�� �ƴ� ���� ���α׷��� ��쿡��
							//WIN32_LEAN_AND_MEAN�� ������ commdlg.h���
							//�ʿ���� ��������� ��Ŭ��� ���� �ʰ� ���ش�.


#include <windows.h>    //������ ������� ��Ŭ���
#include <stdio.h>      //���Ĵٵ� ����� ��� ��Ŭ���~ (printf, scanf ���..)
#include <tchar.h>      //�����쿡�� ����� ���ڿ� ��� ��� ��Ŭ���~
						//MBCS (Multi Byte Character Set)
						//-> ������ ����Ѵ� ��Ƽ����Ʈ ������ ���ڿ�~
						//WBCS (Wide Byte Character Set)
						//-> ��� ���ڸ� 2����Ʈ�� ó��~~, �����ڵ� ���...
#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "utils.h"
#include "imageManager.h"
#include "timeManager.h"


//using namespace MY_UTIL;


/* #### �����ι� #### */
#define WINNAME ( LPTSTR)(TEXT ("APIWindow"))
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 1100
#define WINSIZEY 825
#define CENTERX (WINSIZEX / 2) //��ũ�� ������ �Լ� �� ���� ��ȣ�� �����ִ� ������ ��������
#define CENTERY (WINSIZEY / 2)
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p)              { if(p) { delete (p);		(p)= NULL; } }
#define SAFE_DELETE_ARRAY(p)        { if(p) { delete [] (p);    (p)= NULL; } }
#define SAFE_RELEASE(p)             { if(p) { (p)->release();	(p)=NULL; } }

/* #### �̱��� ��ũ�� #### */
#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()


/* #### �������� #### */
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;