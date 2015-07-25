#include "maze.hpp"

int main(){
	mazes m ;
	pos finishpos ;
	std::vector<stats> weaponlist , armorlist , monsterlist ;
	char typeofspace ;

	map area(m) ;
	area.generation(m,finishpos) ;

	loot l ;
	l.generateloot(weaponlist,armorlist,m) ;

	monsters mons ;
	mons.generatemonsters(monsterlist,m,finishpos) ;

	printintro() ;	

	character c(m) ;

	while(1 != 2){
		
		typeofspace = c.movement(m) ;
		if(typeofspace == 'A'){
			c.inventory('A',armorlist,m) ;
		}
		if(typeofspace == 'W'){
			c.inventory('W',weaponlist,m) ;
		}
		if(typeofspace == 'M' or typeofspace == 'F'){
			c.fighting(monsterlist,m) ;
		}
	}

	return 0 ;

	
}
