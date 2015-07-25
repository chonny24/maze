#ifndef MAZE_HPP
#define MAZE_HPP


#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include<stdlib.h>

struct pos{
	int x ;
	int y ;

};

struct stats{
	int hp ;
	int dodge ;
	int crit ;
	int atk ;
	std::string name ;
	pos position ;
};

struct coordinates{
	std::vector<int> startx ;
	std::vector<int> starty ;

};

struct mazes{
	char maparray[40][40] ;
	char foggymap[40][40] ;
	std::vector<pos> places ;
};

void printmap(mazes m) ;
void printloot(stats x, char typeofspace) ;
void calctotalplaces(mazes& m,int istart,int iend,int jstart,int jend) ;
void printfighting_main(stats x) ;
void printfighting_atk(int damage,int x,std::string monster,int crit) ;
void printwinner() ;
void printloser() ;
void printintro() ;

class monsters{
	public:
		monsters() ;
		void generatemonsters(std::vector<stats>& monsterlist,
				      mazes& m,pos finishpos);
		void namemonsters(stats& x);
		void placemonsters(std::vector<stats>& x,mazes& m) ;
		void boss(std::vector<stats>& monsterlist,
					pos finishpos);


	private:
		int monsterseed ;

};

class loot{
	public:
		loot() ;
		void generateloot(std::vector<stats>& weaponlist,
				  std::vector<stats>& armorlist,
				  mazes& m) ;
		void nameloot(stats& x) ;
		void placeloot(std::vector<stats>& x, mazes& m) ;

	private:
		int weaponseed ;
		int armorseed ;
};

class character{
	public:
		character(mazes& m) ;
		char movement(mazes& m) ;
		void printplayerstats() ;
		void inventory(char typeofspace,std::vector<stats>& x,
			       mazes& m) ;
		void fighting(std::vector<stats>& x, mazes& m) ;
		void crafting(stats& armor1, mazes& m) ;

		pos get_playerpos(){return player.position;} 

	private:
		stats player ;
		stats playerarmor ;
		stats playerweapon ;
		char previousmove ;
};
		


class map{
	public:
		map(mazes& m) ;
		void finish(mazes& m , pos& finishpos) ;
		void generation(mazes& m , pos& finishpos) ;
		void path(mazes& m , int seedlength,int posx,int posy) ;
	
	private:
		std::vector<int> seed ;
		coordinates branches ;
};



#endif
