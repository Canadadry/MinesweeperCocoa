#ifndef _SG_RECTANGLE_
#define _SG_RECTANGLE_


#include <SceneGraph/SGItem.h>
#include <SceneGraph/Color.h>
#include <SceneGraph/VertexArray.h>

class SGRectangle : public SGItem
{
public:
	SGRectangle(SGItem* parent = NULL);
	
	void setColor(Color new_Color);
	Color color() const;
	
	float borderSize() const;
	void setBorderSize(float new_borderSize);
	
	void setBorderColor(Color new_Color);
	Color borderColor() const;
	
protected:

	void paint()const;	
	void geometryChange();
	
	Color m_color;
	Color m_borderColor;
	float m_borderSize;
	
private:
	VertexArray m_vertex_array;
	
	void updateVertexArray();
	
};

#endif //endof _SG_RECTANGLE_
