#include "game.h"
#include <iostream>
#include <vector>
#include <cmath>

enum TileSetEnum {
	RED_FLAG  = 0 ,
	BLUE_FLAG = 1 ,
	MINE      = 2 ,
	DEAD_MINE = 3 ,
	NO_MINE   = 4 ,
	FREE      = 5 ,
	EMPTY     = 6 , 
	MINE_AROUND_1 ,
	MINE_AROUND_2 ,
	MINE_AROUND_3 ,
	MINE_AROUND_4 ,
	MINE_AROUND_5 ,
	MINE_AROUND_6 ,
	MINE_AROUND_7 ,
	MINE_AROUND_8 
};


Game::Game()
: m_tileset(new RessourceTileSet)
, m_tileMap(new SGTileMap)
, m_root(new SGRoot)
, myTabMines()
, myLargeur(0)
, myHauteur(0)
, myNbMine(0)
, myNbDrapeau(0)
, myMinetrouve(0)
{
	srand ( time(NULL) );
	
	m_tileset->setNumberOfTile(5,3);
	std::string ressource = "mineswiper.png";
	m_tileset->loadFromFile(ressource.c_str());	
	m_tileMap->setTileSet(m_tileset);
	m_root->giveMainItem(m_tileMap);
	
}

void Game::startGame(int colonne, int ligne, int mine)
{
	myLargeur = colonne;
	myHauteur = ligne;
	myNbMine = mine;
	myNbDrapeau = mine;
	myMinetrouve = 0;

	std::vector<int> initData;
	initData.assign(myLargeur*myHauteur, FREE);
	m_tileMap->setData(myLargeur, myHauteur, &initData[0]);
	
	myTabMines.assign(myLargeur*myHauteur, 0);
	
	randomMap();
}

Game::~Game()
{
	delete m_root;
}

void Game::display()
{	
	m_root->render();
}

int Game::width() const
{
	return myLargeur*m_tileset->getTileWidth();
}
int Game::height() const
{
	return myHauteur*m_tileset->getTileHeight();
}

void Game::mouseLeftUp(int x,int y)
{
	cliqueGauche(x/m_tileset->getTileWidth(), y/m_tileset->getTileHeight());
}

void Game::mouseLeftDragged(int x,int y)
{
  //mouse empty under mouse	
}

void Game::mouseLeftDown(int x,int y)
{	// place code to show EMPTY il clic is possible
}

void Game::mouseRightUp(int x,int y)
{
	cliqueDroit(x/m_tileset->getTileWidth(), y/m_tileset->getTileHeight());
}

void Game::mouseRightDragged(int x,int y)
{
	
}

void Game::mouseRightDown(int x,int y)
{
}


bool Game::cliqueGauche(int colonne,int ligne)
{
	//printf("clic %d,%d\n",colonne,ligne);
    if(colonne>=0 && ligne>=0 && colonne<myLargeur && ligne<myHauteur)
    {
        int tmp=colonne+myLargeur*ligne;
		int nbMine = myTabMines[tmp];
		int tile = m_tileMap->getIDForTile(colonne, ligne);
		
		if(tile == FREE)
		{
			if(nbMine == 9)
			{
				m_tileMap->setIDForTile(DEAD_MINE,colonne,ligne);
				perdu();
			}
			else
			{
				m_tileMap->setIDForTile((nbMine+EMPTY),colonne,ligne);
			
				if(nbMine == 0)
				{
					cliqueGauche(colonne-1,ligne-1);
					cliqueGauche(colonne  ,ligne-1);
					cliqueGauche(colonne+1,ligne-1);
					cliqueGauche(colonne-1,ligne  );
					cliqueGauche(colonne+1,ligne  );
					cliqueGauche(colonne-1,ligne+1);
					cliqueGauche(colonne  ,ligne+1);
					cliqueGauche(colonne+1,ligne+1);
				}
			}
			
			return true;
		}
    }
    return false;
}

bool Game::cliqueDroit(int colonne,int ligne)
{
	//printf("clic %d,%d\n",colonne,ligne);
	if(colonne>=0 && ligne>=0 && colonne<myLargeur && ligne<myHauteur)
	{
		int tmp=colonne+myLargeur*ligne;
		
		if(m_tileMap->getIDForTile(colonne, ligne) == FREE)
		{
			if(myNbDrapeau>0)
			{
				m_tileMap->setIDForTile(RED_FLAG,colonne, ligne);
				myNbDrapeau--;
				if(myTabMines[tmp]==9)
				{
					myMinetrouve++;
					if (myMinetrouve==myNbMine)
						gagne();
				}
			}
		}
		else if (m_tileMap->getIDForTile(colonne, ligne) == RED_FLAG)
		{
			m_tileMap->setIDForTile(FREE,colonne, ligne);
			myNbDrapeau++;
			if(myTabMines[tmp]==9)
				myMinetrouve--;
		}
		return true;
	}
	return false;
}

bool Game::cliqueBoth  (int colonne,int ligne)
{
	int tmp=colonne+myLargeur*ligne;
	
	if(m_tileMap->getIDForTile(colonne, ligne) > FREE)
	{
		int drapeau=myTabMines[tmp];
		
		for(int i=(colonne-1);i<(colonne+2);i++)
		{
			for(int j=(ligne-1);j<(ligne+2);j++)
			{
				if(i>=0 && j>=0 && i<myLargeur && j<myHauteur)
				{
					if (m_tileMap->getIDForTile(colonne, ligne) == RED_FLAG)
						drapeau--;
				}
			}
		}
		
		if(drapeau==0)
		{
			cliqueGauche(colonne-1,ligne-1);
			cliqueGauche(colonne  ,ligne-1);
			cliqueGauche(colonne+1,ligne-1);
			cliqueGauche(colonne-1,ligne  );
			cliqueGauche(colonne+1,ligne  );
			cliqueGauche(colonne-1,ligne+1);
			cliqueGauche(colonne  ,ligne+1);
			cliqueGauche(colonne+1,ligne+1);
			
			return true;
		}
	}
	
	return false;
}


void Game::gagne()
{
//	Sound::playWin();
}

void Game::perdu()
{
	for(int i=0;i<myLargeur;i++)
	{
		for(int j=0;j<myHauteur;j++)
		{
			int tile  = m_tileMap->getIDForTile(i, j);
			int nbMine = myTabMines[i+myLargeur*j];
			
			if(tile == RED_FLAG && nbMine!=9)
			{
	             m_tileMap->setIDForTile(NO_MINE,i, j);
			}
			
			if(tile == FREE)
			{
				if( nbMine==9 ) m_tileMap->setIDForTile(MINE,i, j);
				else            m_tileMap->setIDForTile(EMPTY+nbMine,i, j);
			}
			
			//printf("at %d,%d there was %d tile id and now %d and %d mine \n",i,j,tile,m_tileMap->getIDForTile(i, j),nbMine);
		}
	}
	//Sound::playLoose();
}

void Game::randomMap()
{
	std::vector<int> tab;
	tab.resize(myLargeur*myHauteur);
	for(int i=0;i<myLargeur*myHauteur;i++)
	{
		tab[i]=i;
	}
	for(int i=0;i<myNbMine;i++)
	{
		int max = myLargeur*myHauteur-i-1;
		int index= rand() % (max+1);
		int tmp=tab[index];
		tab.erase(tab.begin()+index);
		addMine(tmp%myLargeur,tmp/myLargeur);
	}
}

void Game::addMine(int colonne,int ligne)
{
	myTabMines[colonne+myLargeur*ligne]=9;
	upNbMine(colonne-1,ligne-1);
	upNbMine(colonne  ,ligne-1);
	upNbMine(colonne+1,ligne-1);
	upNbMine(colonne-1,ligne  );
	upNbMine(colonne+1,ligne  );
	upNbMine(colonne-1,ligne+1);
	upNbMine(colonne  ,ligne+1);
	upNbMine(colonne+1,ligne+1);
	
}

void Game::upNbMine(int colonne,int ligne)
{
	if(colonne>=0 && ligne>=0 && colonne<myLargeur && ligne<myHauteur)
	{
		if(myTabMines[colonne+myLargeur*ligne]==9 )
			return;
		
		myTabMines[colonne+myLargeur*ligne]++;
	}
}
