#pragma once
class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();
	int x;
	int y;

	// γόZq
	VECTOR2& operator = (const VECTOR2& vec);

	// Y¦Zq
	int& operator[](int i);

	// δrZq
	bool operator==(const VECTOR2& vec) const;
	bool operator!=(const VECTOR2& vec) const;
	bool operator< (const VECTOR2& vec) const;
	bool operator<=(const VECTOR2& vec) const;

	// PZq
	VECTOR2& operator += (const VECTOR2& vec);
	VECTOR2& operator -= (const VECTOR2& vec);
	VECTOR2& operator *= (int k);
	VECTOR2& operator /= (int k);

	// 
	VECTOR2 operator+() const;
	VECTOR2 operator-() const;
};


// xNgΜZ
// ΤθlΜ^ operatorZq(ψ1Aζ2ψA.......);
// VECTOR2 + VECTOR2
VECTOR2 operator +(const VECTOR2& u, const VECTOR2& v);
// VECTOR2 - VECTOR2
VECTOR2 operator -(const VECTOR2& u, const VECTOR2& v);
// int * VECTOR2
VECTOR2 operator *(int k, const VECTOR2& v);
// Vector3D * int
VECTOR2 operator *(const VECTOR2& v, int k);
// VECTOR3D / int
VECTOR2 operator /(const VECTOR2& v, int k);
// VECTOR3D % int
VECTOR2 operator %(const VECTOR2& v, int k);
// VECTOR3D + int
VECTOR2 operator +(const VECTOR2& v, int k);
// VECTOR3D - int
VECTOR2 operator -(const VECTOR2& v, int k);
