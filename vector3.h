
#ifndef __VECTOR3_H_INCLUDED__
#define __VECTOR3_H_INCLUDED__
#include<math.h>
class Vector3 {
public:
	float x, y, z;
	Vector3() {};
	Vector3(const Vector3& a) :x(a.x), y(a.y), z(a.z) {};
	Vector3(float nx, float ny, float nz) :x(nx), y(ny), z(nz) {};

	void zero() {x = y = z = 0.0f;};
    Vector3 operator-()const { return Vector3(-x, -y, -z); };
	Vector3 operator*(float a)const {
		return Vector3(a * x, a * y, a * z);
	}
	Vector3 operator/(float a)const {
		a = 1.0f / a;
		return Vector3(a * x, a * y, a * z);
	}
	
		Vector3 operator/=(float a) {
			a = 1.0f / a;
			x *= a; y *= a; z *= a;

			return *this;
		}
	Vector3 operator*=(float a) {
		x *= a; y *= a; z *= a;
		return *this;
	}

	Vector3 operator+ (const Vector3& a)const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator- (const Vector3& a)const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}
	Vector3 operator+=(const Vector3& a) {
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}
	Vector3 operator-=(const Vector3& a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}
	void normalize() {
		float magSq = x * x + y * y + z * z;
		if (magSq) {
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;

		}
	}
	float operator*(const Vector3& a) const {
		return x * a.x + y * a.y + z * a.z;

	}
	
};
inline float vectorMag(const Vector3& a) {
	return sqrt(double(a.x * a.x) + double( a.y * a.y )+ double(a.z *a.z));
}

inline Vector3 operator *(float k, const Vector3& v) {
	return Vector3(k * v.x, k * v.y, k * v.z);
}

inline float distance(const Vector3& a, const Vector3& b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

inline double CalculateAngleTwoVectorsRadian(const Vector3&a,const Vector3&b) {

	return acos((a * b) / (vectorMag(a) * vectorMag(b)));

}

inline Vector3 crossProduct(const Vector3& a, const Vector3& b) {
	return Vector3(a.y * b.z - a.z * b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
#endif