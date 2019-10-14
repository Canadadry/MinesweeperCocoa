#ifndef _SG_ROOT_
#define _SG_ROOT_

#include <SceneGraph/Clock.h>

class SGItem;

class SGRoot
{
	
public:
	SGRoot();
	virtual ~SGRoot();
	
	void update();
	void render();
	
	void giveMainItem(SGItem* sgItem);
	SGItem* mainItem() const;
	
private:
	SGItem* m_main_item;
	Clock   m_clock;
		
};


#endif // end of _SG_ROOT_