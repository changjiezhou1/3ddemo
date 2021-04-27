#pragma once
#ifndef __MATHUTIL_H_INCLUDED__
#define __MATHUTIL_H_INCLUDED__


#include <math.h>
const float kPi = 3.141592f;
const float k2Pi = kPi*2;
const float kPiOver2 = kPi / 2;
inline void sinCos(float* returnSin, float* returnCos, float theta) {

	*returnSin = sin(theta);
	*returnCos = cos(theta);


}
#endif // !__MATHUTIL_H_INCLUDED__
