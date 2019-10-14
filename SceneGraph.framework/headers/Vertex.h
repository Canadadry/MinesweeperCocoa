#ifndef _VERTEX_HPP
#define _VERTEX_HPP

#include <SceneGraph/Color.h>
#include <SceneGraph/Vector.h>

class Vertex
{
public :

    Vertex();
    Vertex(const Vector& thePosition);
    Vertex(const Vector& thePosition, const Color& theColor);
    Vertex(const Vector& thePosition, const Vector& theTexCoords);
    Vertex(const Vector& thePosition, const Color& theColor, const Vector& theTexCoords);
	
    Vector  texCoords;
    Color   color;    
    Vector  position;  
	float   z_coord; 
};


#endif // _VERTEX_HPP
