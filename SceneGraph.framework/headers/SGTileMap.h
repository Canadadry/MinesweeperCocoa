#ifndef _SGTILEMAP_
#define _SGTILEMAP_

#include <SceneGraph/SGItem.h>
#include <vector>
#include <SceneGraph/VertexArray.h>

class RessourceTileSet;

class SGTileMap : public SGItem
{
public:

	SGTileMap(SGItem* parent = NULL);
	
	void setTileSet(RessourceTileSet* tileset);
	void setIDForTile(int tile_id, int col,int row);
	int  getIDForTile(int col,int row) const;

	void setData(int columns, int rows, int* data);
	
	//handling view
	
protected:
	void paint() const;
	
private:
	RessourceTileSet* m_tileset;
	int               m_rows;
	int               m_columns;
	std::vector<int>  m_tileIds;
	VertexArray       m_vertex_array;
	
	void initTile(int col, int row); 
	void updateTile(int col, int row); 


};

#endif
