#include "Matrix3x3.h"
#include "vector3.h"
#include"MathUtil.h"
#include <assert.h>
#include<iostream>
Matrix3x3 operator*(const Matrix3x3& a, const Matrix3x3& b) {
	Matrix3x3 r;
	std::cout << &r;
	r.m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
	r.m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
	r.m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;

	r.m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
	r.m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
	r.m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;

	r.m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
	r.m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
	r.m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;
	
	return r;
}

Vector3 operator*(const Vector3& a, const Matrix3x3& b)
{
	return Vector3(a.x*b.m11+a.y*b.m21+a.z*b.m31, 
		a.x * b.m12 + a.y * b.m22 + a.z * b.m32, 
		a.x * b.m13 + a.y * b.m23 + a.z * b.m33);
}

Matrix3x3& operator*=( Matrix3x3& a, const Matrix3x3& b)
{
	a= a * b;
	return a;
	// TODO: �ڴ˴����� return ���
}

Vector3& operator*=( Vector3& a, const Matrix3x3& b)
{
	a = a * b;
	return a;
	// TODO: �ڴ˴����� return ���
}
//1 x 2 y 3 z
void Matrix3x3::setRotate(int axis, float theta)
{
	float s, c;
	sinCos(&s, &c,theta);
	switch (axis) {
	case 1:
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = c; m23 = s;
		m31 = 0.0f; m32 = -s; m33 = c;

		break;
	case 2:
		m11 = c; m12 = 0.0f; m13 = -s;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = s; m32 = 0.0f; m33 = c;
		break;

	case 3:
		m11 = c; m12 = s; m13 = 0.0f;
		m21 = -s; m22 = c; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
		break;

	default:
		std::cout << "��ת�᲻��";
		//assert(false);
	}
}

void Matrix3x3::setupScale(const Vector3& s)
{
	m11 = s.x; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = s.y; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = s.z;
}

void Matrix3x3::setupReflect(int axis)
{
	switch (axis) {
	case 1:
		//x���꾵��
		m11 = -1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
		break;
	case 2:
		//y���귢������
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = -1.0f; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
		break;
	case 3:
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = -1.0f;
		//z���귢������
		break;
	default:
		assert(false);
	}

}

void Matrix3x3::setupProject(const Vector3& n)
{
	assert(fabs(n * n - 1.0f) < 0.01);
	m11 = 1.0f - n.x * n.x;
	m22 = 1.0f - n.y * n.y;
	m33 = 1.0f - n.z * n.z;

	m12 = m21 = -(n.x * n.y);
	m13 = m31 = -(n.x * n.z);
	m32 = m23 = -(n.y * n.z);
}

void Matrix3x3::setupReflect(const Vector3& n)
{
	assert(fabs(n * n - 1.0f) < 0.01);
	float ax = -2.0f * n.x;
	float ay = -2.0f * n.y;
	float az = -2.0f * n.z;

	m11 = 1.0f + ax * n.x;
	m22 = 1.0f + ay * n.y;
	m33 = 1.0f + az * n.z;

	m12 = m21 = ax * n.y;
	m13 = m31 = ax * n.z;
	m23 = m32 = ay * n.z;



}

void Matrix3x3::setupShear(int axis, float s, float t)
{
	switch (axis) {
	case 1:
		//ʹ��Xȥ�б�yz
		m11 = 1.0f; m12 = s; m13 = t;
		m21 = 0.0f; m22 = 1.0f; m23 =0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
		break;
	case 2:
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = s; m22 = 1.0f; m23 = t;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
		//ʹ��y�б�xz
		break;
	case 3:
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = s; m32 = t; m33 = 1.0f;
		//ʹ��z�б�yx
		break;
	default:
		assert(false);

	}

}

void Matrix3x3::setupScale(const float Kx, const float Ky, const float Kz)
{
	m11 = Kx; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = Ky; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = Kz;
}
