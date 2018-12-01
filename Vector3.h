#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float X,float Y, float Z):x(X),y(Y),z(Z) {}
	~Vector3();
	void set(float X, float Y, float Z) { x = X; y = Y;z = Z; }

	// operator overloading
	// this is just scalar multiplication
	Vector3 operator*(const float scalar) const
	{ 
		Vector3 result;
		result.x = x*scalar;
		result.y = y*scalar;
		result.z = z*scalar;
		return result;
	}

	Vector3 multMatrix22(const float m22[2][2]) const
	{
		Vector3 result;
		/* assuming this is a 2d vector */
		/* perform matrix multiply */
		/* Mp = [a b] * [x]
		        [c d]   [y]
			 
		   [x']  = ax + by;
		   [y']  = cx + dy;
		*/

		result.x = 0;
		result.y = 0;
		result.z = 0;

		return result;
	}


	// this is the addition operator to add two vectors
	Vector3 operator+(const Vector3 rhs) const
	{
		Vector3 result;
		result.x = x + rhs.x;
		result.y = y + rhs.y;
		result.z = z + rhs.z;

		return result;
	}

	// this is the addition operator to add two vectors
	Vector3 operator-(const Vector3 rhs) const
	{
		Vector3 result;
		result.x = x - rhs.x;
		result.y = y - rhs.y;
		result.z = z - rhs.z;

		return result;
	}

	// its a 3D vector, here is the data!
	float x, y, z;

};

