#include <iostream>
#include "vector3.h"
#include "Matrix3x3.h"
#include"MathUtil.h"
using namespace std;
void print_v(Vector3 v) {
	cout << "[" << v.x << "," << v.y << "," << v.z << "]" << endl;

}
void print_m(Matrix3x3 m) {
	cout << '[' << m.m11 << ',' << m.m12 << ',' << m.m13 << ',' << endl;
	cout  << m.m21 << ',' << m.m22 << ',' << m.m23 << ',' << endl;
	cout  << m.m31 << ',' << m.m32 << ',' << m.m33 << ']' << endl;
}
int main() {

	Vector3 a(10, 20,30),b;
	print_v(a);

	Matrix3x3 M;

	M.setupReflect(1);
	b = a * M;
	print_v(b);

	Vector3 n(0, 0, 1);
	M.setupReflect(n);
	b = a * M;
	print_v(b);

	M.setupShear(2, 1, 2);
	b = a * M;
	print_v(b);
	/*Matrix3x3 M;
	M.setRotate(3, kPiOver2);
	b = a * M;
	print_v(b);

	M.setRotate(3, kPi);
	print_m(M);
	b = a * M;
	print_v(b);

	M.setRotate(1, -22 * kPi / 180);
	print_m(M);
	b = a * M;
	print_v(b);

	M.setRotate(2, 30 * kPi / 180);
	print_m(M);*/

	//M.setRotate(1,-22)

	//Matrix3x3 a(1, -5, 3,
	//	0, -2, 6,
	//	7, 2, -4);
	//Matrix3x3 b(-8,6,1,
	//	7,0,-3,
	//	2,4,5);
	//Matrix3x3&& c = a * b;
	//cout << &c;
	//print_m(c);
	//a *= b;
	//print_m(a);


	//Vector3 v(3, -1, 4);
	//Matrix3x3 m(-2, 0, 3,
	//			5, 7, -6,
	//			1, -4, 2);
	//Vector3 r1 = v * m;
	//v *= m;
	//print_v(r1);
	//print_v(v);

	//Vector3 v1(10, 20, 30);
	//print_v(v1);

	//Vector3 v2(v1);

	//Vector3 v3=-v1;
	//print_v(v3);

	//v2.zero();
	//print_v(v2);

	//Vector3 v4(5, -4, 7);
	//float r = vectorMag(v4);
	//cout << r;

	//Vector3 v5 = v4 /3;
	//v5 /= 2;
	//print_v(v5);

	//Vector3 v9(1, 2, 3);
	//Vector3 v10 = 2 * v9;
	//print_v(v10);

	//v5 = 2 * v9;
	//print_v(v5);

	//Vector3 v11(-3, 4, 0);
	//v11.normalize();
	//print_v(v11);


	//Vector3 a(5, 0, 0);
	//Vector3 b(-1, 8, 0);
	//Vector3 c = a - b;


	//print_v(c);

	//float m = distance(a, b);
	//cout << m;

	//Vector3 h1(3, -2, 7);
	//Vector3 h2(0, 4, -1);
	//cout << h1 * h2<<endl;

	//double red = CalculateAngleTwoVectorsRadian(h1, h2)*(180/3.141592);
	//cout << red;

	//Vector3 t1(1, 3, 4);
	//Vector3 t2(2, -5, 8);
	//Vector3 cp = crossProduct(t1, t2);
	//print_v(cp);
	//getchar();
	return 0;

}