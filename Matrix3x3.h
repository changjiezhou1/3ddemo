#ifndef __MATRIX3X3_H_INCLUDED__
#define __MATRIX3X3_H_INCLUDED__
#include"vector3.h"
class Matrix3x3 {
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	Matrix3x3() {
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
	};
	Matrix3x3(int m11,int  m12,int  m13, int m21,int  m22,int  m23, int m31, int m32, int m33):m11(m11), m12(m12), m13(m13), m21(m21), m22(m22),m23(m23),m31(m31),m32(m32), m33(m33) {};
	void setRotate(int axis, float theta);
	void setupScale(const Vector3 &s);
	//对标准坐标平面进行镜像
	void setupReflect(int axis);
	//使用法向量来确定平面
	void setupProject(const Vector3& n);
	void setupReflect(const Vector3& n);
	void setupShear(int axis, float s, float t);
	void setupScale(const float Kx, const float Ky, const float Kz);
};
Matrix3x3 operator*(const Matrix3x3& a, const Matrix3x3& b);
Vector3 operator*(const Vector3& a, const Matrix3x3& b);

Matrix3x3& operator*=( Matrix3x3& a, const Matrix3x3& b);
Vector3& operator*=( Vector3& a, const Matrix3x3& b);


#endif // !__MATRIX3X3_H_INCLUDED__
