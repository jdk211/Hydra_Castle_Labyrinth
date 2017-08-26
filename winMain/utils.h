#pragma once

#include <cmath>

#define PI 3.141592654f // PI == 180��
#define PI2 (PI * 2)	// PI2 == 360��
#define DEG_TO_RAD (PI / 180.f)

#define FLOAT_EPSILON 0.0001f //�� ���� ���̰� ���� ���ٰ� ���� �����ϰڴ� ���, ��� ��������

namespace MY_UTIL
{
	//�Ÿ� �������� �Լ�
	float getDistance( float startX, float startY, float endX, float endY );

	//�ޱ� �������� �Լ�
	float getAngle( float startX, float startY, float endX, float endY );
}