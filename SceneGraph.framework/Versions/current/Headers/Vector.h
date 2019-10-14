#ifndef _VECTOR_
#define _VECTOR_


class Vector
{
public:
	Vector(float x =0.0 ,float y =0.0 );
	Vector(const Vector& vect);
	Vector& operator=(const Vector& vect);
	Vector operator+(const Vector& vect) const;
	Vector operator-(const Vector& vect) const;
	Vector& operator+=(const Vector& vect);
	Vector& operator-=(const Vector& vect);
	bool operator==(const Vector& vect) const;
	bool operator!=(const Vector& vect) const;
	Vector operator*(float scalar) const ;
	Vector operator/(float scalar) const ;
	Vector& operator*=(float scalar);
	Vector& operator/=(float scalar);


	float dotProduct(const Vector& vect) const ;
	float crossProduct(const Vector& vect) const ;
	float norme() const ;
	float phase() const ;

	Vector& normalise();

	float x;
	float y;
};

#endif // end of _VECTOR_