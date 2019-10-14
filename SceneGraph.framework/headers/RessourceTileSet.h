#ifndef _RESSOURCES_TILESET_
#define _RESSOURCES_TILESET_

#include <SceneGraph/RessourceImage.h>

class RessourceTileSet : public RessourceImage
{
public:
	struct Quad{
		float top;
		float bottom;
		float left;
		float right;
	};
	
	RessourceTileSet();
	
	void setNumberOfTile(int on_x, int on_y);
	int getTileCount() const;
	int getTileCountOnX() const;
	int getTileCountOnY() const;
	int getTileWidth() const;
	int getTileHeight() const;
	
    // convention id 0 is topleft tile
	// event if tileset origin is bottomleft
	Quad getQuadFromID(int id) const;
	
private:
	int m_number_of_tile_on_x;
	int m_number_of_tile_on_y;
};

#endif // end of _RESSOURCES_TILESET_