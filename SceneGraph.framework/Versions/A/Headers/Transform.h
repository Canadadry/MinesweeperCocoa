#ifndef _TRANSFORM_
#define _TRANSFORM_

#include <SceneGraph/Vector.h>

class Transform
{
public :

    Transform();
	Transform(float a00, float a01, float a02,
              float a10, float a11, float a12,
              float a20, float a21, float a22);

    const float* getMatrix()  const;
    Transform    getInverse() const;
	
    Vector  transformPoint(float x, float y) const;
    Vector  transformPoint(const Vector& point) const;
    //FloatRect transformRect(const FloatRect& rectangle) const;

    Transform& combine(const Transform& transform);
    Transform& translate(float x, float y);
    Transform& translate(const Vector& offset);
    Transform& rotate(float angle);
    Transform& rotate(float angle, float centerX, float centerY);
    Transform& rotate(float angle, const Vector& center);
    Transform& scale(float scale);
    Transform& scale(float scaleX, float scaleY);
    Transform& scale(float scaleX, float scaleY, float centerX, float centerY);
    Transform& scale(const Vector& factors);
    Transform& scale(const Vector& factors, const Vector& center);

    static const Transform Identity;

private:

    float m_matrix[16];
};

Transform  operator * (const Transform& left, const Transform& right);
Transform& operator *=(      Transform& left, const Transform& right);
Vector     operator * (const Transform& left, const Vector&    right);

#endif // _TRANSFORM_
