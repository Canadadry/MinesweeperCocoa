#ifndef _TRANSFORMABLE_
#define _TRANSFORMABLE_

#include <SceneGraph/Transform.h>

class Transformable
{
public :

    Transformable();
    virtual ~Transformable();

    void setPosition(float x, float y);
	void setPosition(const Vector& position);
    void setRotation(float angle);
    void setScale(float factorX, float factorY);
    void setScale(const Vector& factors);
    void setScale(float factors);
	
    void setOrigin(float x, float y);
	void setOrigin(const Vector& origin);

    const Vector& getPosition() const;
    float getRotation() const;
    const Vector& getScale() const;
    const Vector& getOrigin() const;

    void move(float offsetX, float offsetY);
    void move(const Vector& offset);

    void rotate(float angle);
    void scale(float factorX, float factorY);
    void scale(const Vector& factor);
    void scale(float factor);
	
    const Transform& getTransform() const;
    const Transform& getInverseTransform() const;
	
protected:
	virtual void transformUpdate() const;

private :

    Vector            m_origin;                     
    Vector            m_position;                   
    float             m_rotation;                   
    Vector            m_scale;                      
    mutable Transform m_transform;                  
    mutable bool      m_transformNeedUpdate;        
    mutable Transform m_inverseTransform;           
    mutable bool      m_inverseTransformNeedUpdate; 
};

#endif 