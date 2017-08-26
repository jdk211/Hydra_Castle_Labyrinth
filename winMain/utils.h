#pragma once

#include <cmath>

#define PI 3.141592654f // PI == 180도
#define PI2 (PI * 2)	// PI2 == 360도
#define DEG_TO_RAD (PI / 180.f)

#define FLOAT_EPSILON 0.0001f //이 정도 차이가 나면 같다고 봐도 무방하겠다 라는, 허용 오차범위

namespace MY_UTIL
{
	//거리 가져오는 함수
	float getDistance( float startX, float startY, float endX, float endY );

	//앵글 가져오는 함수
	float getAngle( float startX, float startY, float endX, float endY );
}