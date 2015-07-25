#include "maze.hpp"

monsters::monsters(){
	srand(time(NULL)) ;
	monsterseed = rand() % 4 + 10 ;
}

void monsters::generatemonsters(std::vector<stats>& monsterlist, mazes& m, pos finishpos){
	for(int i = 0 ; i < monsterseed ; i++){
		monsterlist.push_back(stats()) ;
		monsterlist[i].hp = rand() % 67 + 3 ;
		monsterlist[i].dodge = 0 ;
		monsterlist[i].crit = 0 ;
		monsterlist[i].atk = rand() % 10 + 1 ;

		namemonsters(monsterlist[i]) ;
	}

	placemonsters(monsterlist,m) ;
	boss(monsterlist,finishpos) ;

}

void monsters::boss(std::vector<stats>& monsterlist , pos finishpos){
	int i = monsterlist.size() ;
	
	monsterlist.push_back(stats()) ;
	monsterlist[i].hp = 70 ;
	monsterlist[i].dodge = 0 ;
	monsterlist[i].crit = 0 ;
	monsterlist[i].atk = 11 ;
	monsterlist[i].name = "The Gatekeeper" ;
	monsterlist[i].position.x = finishpos.x ;
	monsterlist[i].position.y = finishpos.y ;
}


void monsters::placemonsters(std::vector<stats>& x , mazes& m){
	::calctotalplaces(m,0,40,10,40) ;
	
	int random ;
	

	for(unsigned int i = 0 ; i < x.size() ; i++){
		random = rand() % m.places.size() ;

		m.maparray[m.places[random].x][m.places[random].y] = 'M' ;

		x[i].position.x = m.places[random].x ;
		x[i].position.y = m.places[random].y ;
	}
		
}


void monsters::namemonsters(stats& x){

	if(x.atk == 1){
		x.name = "Abandoned and Neglected" ;
	}
	else if(x.atk == 2){
		x.name = "Depressed" ;
	}
	else if(x.atk == 3){
		x.name = "Blind" ;
	}
	else if(x.atk == 4){
		x.name = "Small" ;
	}
	else if(x.atk == 5){
		x.name = "Average Sized" ;
	}
	else if(x.atk == 6){
		x.name = "Very Large" ;
	}
	else if(x.atk == 7){
		x.name = "Hallucinating" ;
	}
	else if(x.atk == 8){
		x.name = "Enraged" ;
	}
	else if(x.atk == 9){
		x.name = "Crazed" ;
	}
	else if(x.atk == 10){
		x.name = "Frenzied" ;
	}



	if(x.hp < 20){
		x.name = x.name + " Imp" ;

	}
	else if(x.hp >= 20 and x.hp < 30){
		x.name = x.name + " Goblin" ;

	}
	else if(x.hp >= 30 and x.hp < 40){
		x.name = x.name + " Orc" ;

	}
	else if(x.hp >= 40 and x.hp < 50){
		x.name = x.name + " Stone Golem" ;

	}
	else if(x.hp >= 50 and x.hp < 60){
		x.name = x.name + " Troll" ;

	}
	else if(x.hp >= 60){
		x.name = x.name + " Dragon" ;

	}
}
