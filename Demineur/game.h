#ifndef _GAME_
#define _GAME_

#include <SceneGraph/SceneGraph.h>
#include <vector>

class RessourceTileSet;
class SGTileMap;
class SGRoot;


class Game 
{
public:
	Game();
	~Game();
	void startGame(int colonne, int ligne, int mine);
	
	void display();
	int width() const;
	int height() const;
	
	void mouseLeftUp(int x,int y);
	void mouseLeftDragged(int x,int y);
    void mouseLeftDown(int x,int y);
	
	void mouseRightUp(int x,int y);
	void mouseRightDragged(int x,int y);
    void mouseRightDown(int x,int y);

	
private:
	//data map
	RessourceTileSet* m_tileset;
	SGTileMap* m_tileMap;
	SGRoot* m_root;
	std::vector<int> myTabMines;
	int myLargeur;
	int myHauteur;
	int myNbMine;
	int myNbDrapeau;
	int myMinetrouve;	
	
	//gameplay
	bool cliqueGauche(int colonne,int ligne);
	bool cliqueDroit (int colonne,int ligne);
	bool cliqueBoth  (int colonne,int ligne);
	void gagne();
	void perdu();
	
	//game generation
	void randomMap();
	void addMine(int colonne,int ligne);
	void upNbMine(int colonne,int ligne);
	
};



#endif //end of _GAME_
