#ifndef SFML_VERTEXARRAY_HPP
#define SFML_VERTEXARRAY_HPP

#include <SceneGraph/Vertex.h>
#include <vector>


class VertexArray
{
public :
	
	enum PrimitiveType
	{
		Points,         
		Lines,          
		LinesStrip,     
		Triangles,      
		TrianglesStrip, 
		TrianglesFan,   
		Quads           
	};

    explicit VertexArray(PrimitiveType type = Quads, unsigned int vertexCount = 0);

    unsigned int getVertexCount() const;
    Vertex& operator [](unsigned int index);
    const Vertex& operator [](unsigned int index) const;
    void clear();
    void resize(unsigned int vertexCount);

    void append(const Vertex& vertex);
    void setPrimitiveType(PrimitiveType type);
    PrimitiveType getPrimitiveType() const;

    void draw() const;

private:

    std::vector<Vertex> m_vertices;      
    PrimitiveType       m_primitiveType; 
};

#endif // SFML_VERTEXARRAY_HPP
