#ifndef _SG_OBJECT_
#define _SG_OBJECT_

#include <vector>

class SGObject
{
	
public:
	SGObject(SGObject* parent=NULL);
	virtual ~SGObject();
	
	int childrenCount() const;
	SGObject* childrentAt(unsigned int index) const;
	SGObject* parent() const;
	
private:
	SGObject* m_parent;
	std::vector<SGObject* > m_childrens;
	
};


#endif // end of _SG_OBJECT_