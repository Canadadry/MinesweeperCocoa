#ifndef _SG_ITEM_
#define _SG_ITEM_

#include <vector>

#include <SceneGraph/SGObject.h>
#include <SceneGraph/Transformable.h>
#include <SceneGraph/Event.h>

class SGRoot;
class SGRessource;

class SGItem : public SGObject,public Transformable
{
	friend class SGRoot;

public:
	SGItem(SGItem* parent=NULL);
	virtual ~SGItem();
	
	float width()const;
	float height()const;
	
	void setWidth(float new_width);
	void setHeight(float new_height);
	
	SGItem* parentItem() const;
	
	bool containPoint(float x, float y) const;
	bool containPoint(Vector p) const;
	
	Vector mapToItem(SGItem* finalBasis, Vector point) const;
	Vector mapToItem(SGItem* finalBasis, float x, float y) const;
	Vector mapFromItem(SGItem* initialBasis, Vector point) const;
	Vector mapFromItem(SGItem* initialBasis,  float x, float y) const;

	
protected:
	virtual void paint() const;
	virtual void update(int elapsedTime);
	virtual void geometryChange();
	
	// event handling
	// return if this item should propagate event
	virtual bool mousePressed (float x, float y);
	virtual bool mouseReleased(float x, float y);
	virtual bool mouseMoveAt  (float x, float y);
	
private:
	float m_width;
	float m_height;	
	std::vector<SGRessource* > m_childrensRessources;
	std::vector<SGItem* >      m_childrensItem;
	mutable bool               m_parentTransformChanged;
	mutable Transform          m_parentGlobalTranfsorm;
	
	bool injectEvent(Event event);
	void updateParentGlobalTransform() const; 
	void updateObject(int elapsedTime);
	void paintObject()const;
	void transformUpdate() const;	

	
	//std::vector<SGRessources* > m_ressources;

};


#endif // endof _SG_ITEM_