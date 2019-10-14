#ifndef _SG_IMAGE_
#define _SG_IMAGE_

#include <OpenGL/gltypes.h>

#include <SceneGraph/SGItem.h>
#include <SceneGraph/VertexArray.h>


class SGImage : public SGItem
{
public:
	SGImage(SGItem* parent = NULL);
	
	GLuint image() const;
	void setImage(GLuint texture);
	
protected:
	void paint()const;	
	void geometryChange();

private:
	GLuint m_textureId;
	VertexArray m_vertex_array;
	
	void updateVertexArray();
	
};

#endif //endof _SG_RECTANGLE_
