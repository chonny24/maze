#include "maze.hpp"

loot::loot(){
	srand(time(NULL)) ;
	weaponseed = rand() % 3 + 10 ;
	armorseed = rand() % 3 + 7 ;
}


void loot::generateloot(std::vector<stats>& weaponlist,
		        std::vector<stats>& armorlist,
			mazes& m){
	for(int i = 0 ; i < weaponseed ; i++){
		weaponlist.push_back(stats()) ;
		weaponlist[i].dodge = rand() % 21 - 10 ;
		weaponlist[i].crit = rand() % 51 ;
		weaponlist[i].atk = rand() % 10 + 1 ;
		weaponlist[i].hp = 0 ;
		
		nameloot(weaponlist[i]) ;
	}

	for(int i = 0 ; i < armorseed ; i++ ){
		armorlist.push_back(stats()) ;
		armorlist[i].dodge = rand() % 41 - 10 ;
		armorlist[i].hp = rand() % 25 + 10 ;
	
		nameloot(armorlist[i]) ;
	}
		
	
	placeloot(weaponlist,m) ;
	placeloot(armorlist,m) ;



}







void loot::placeloot(std::vector<stats>& x, mazes& m){
	int random ;

	::calctotalplaces(m,0,40,0,30) ;


	for(unsigned int i = 0 ; i < x.size() ; i ++){
		do{
			random = rand() % m.places.size() ;
		}while(m.places[random].x == 1 and m.places[random].y==20);

		if(x[0].hp > 0){
			m.maparray[m.places[random].x][m.places[random].y] 
				                                    = 'A' ;
		}
		else{
			m.maparray[m.places[random].x][m.places[random].y] 
				                                    = 'W' ;
		}
			x[i].position.x = m.places[random].x ;
			x[i].position.y = m.places[random].y ;
	}
}






void  loot::nameloot(stats& x){
	int random ;

	if(x.hp > 0){
		if(x.dodge < -5){
			x.name = "Very Heavy" ;
		}
		else if(x.dodge >= -5 and x.dodge < 0){
			x.name = "Stiff" ;
		}
		else if(x.dodge >= 0 and x.dodge < 5){
			x.name = "Plain" ;
		}
		else if(x.dodge >= 5 and x.dodge < 10){
			x.name = "Quality" ;
		}
		else if(x.dodge >= 10 and x.dodge < 15){
			x.name = "Excellent" ;
		}
		else if(x.dodge >= 15 and x.dodge < 20){
			x.name = "Mastercrafted" ;
		}
		else if(x.dodge >= 20 and x.dodge < 25){
			x.name = "Elvish" ;
		}
		else if(x.dodge >= 25){
			x.name = "Unique" ;
		}


		if(x.hp < 15){
			x.name = x.name + " Shirt" ;
		}
		else if(x.hp >= 15 and x.hp < 20){
			x.name = x.name + " Cloak" ;
		}
		else if(x.hp >= 20 and x.hp < 25){
			x.name = x.name + " Leather Armor" ;
		}
		else if(x.hp >= 25 and x.hp < 30){
			x.name = x.name + " Steel Armor" ;
		}
		else if(x.hp >= 30){
			x.name = x.name + " Mithril Armor" ;
		}
	}

	else{
		if(x.dodge < -5){
			if(x.crit < 5){
				x.name = "Awkwardly Huge" ;
			}
			else if(x.crit >= 5 and x.crit < 25){
				x.name = "Heavy" ;
			}
			else if(x.crit >= 25 and x.crit < 40){
				x.name = "Dwarfmake" ;
			}
			else if(x.crit >= 40){
				x.name = "Randomly Exploding" ;
			}
		
		}

		else if(x.dodge >= -5 and x.dodge <= 5){
			if(x.crit < 15){
				x.name = "Average" ;
			}
			else if(x.crit >= 15 and x.crit < 25){
				x.name = "Superior" ;
			}
			else if(x.crit >= 25 and x.crit < 40){
				x.name = "Rare" ;
			}
			else if(x.crit >= 40){
				x.name = "One of a Kind" ;
			}
		}

		else if(x.dodge > 5){
			if(x.crit < 10){
				x.name = "Abnormaly Light" ;
			}
			else if(x.crit >= 10 and x.crit < 30){
				x.name = "Extremely Precise" ;
			}
			else if(x.crit >= 30 and x.crit < 40){
				x.name = "Assasin's" ;
			}
			else if(x.crit >= 40){
				x.name = "God's" ;
			}
		}



		if(x.atk <= 2){
			random = rand() % 5 + 1 ;

			switch(random){
				case 1:
					x.name = x.name + " Stick" ;
					break ;
				case 2:
					x.name = x.name + " Broom" ;
					break ;
				case 3:
					x.name = x.name + " Rock" ;
					break ;
				case 4:
					x.name =x.name+" Styrofoam Block" ;
					break ;
				case 5:
					x.name = x.name + " Spoon" ;
					break ;
			}
		}
		else{
			random = rand() % 9 + 1 ;

			switch(random){
				case 1:
					x.name = x.name + " Sword" ;
					break ;
				case 2:
					x.name = x.name + " Blade" ;
					break ;
				case 3:
					x.name = x.name + " Mace" ;
					break ;
				case 4:
					x.name = x.name + " Axe" ;
					break ;
				case 5:
					x.name = x.name + " Hatchet" ;
					break ;
				case 6:
					x.name = x.name + " Spear" ;
					break ;
				case 7:
					x.name = x.name + " Dagger" ;
					break ;
				case 8:
					x.name = x.name + " Claymore" ;
					break ;
				case 9:
					x.name = x.name + " Hammer";
					break ;
			}
		}



		if(x.atk <= 2){
			x.name = x.name + " of Harmlessness" ;
		}
		else if(x.atk > 2 and x.atk <= 4){
			x.name = x.name + " of Average Quality" ;
		}
		else if(x.atk == 5){
			x.name = x.name + " of Flawless Quality" ;
		}
		else if(x.atk == 6){
			x.name = x.name + " of Ice" ;
		}
		else if(x.atk == 7){
			x.name = x.name + " of Flames" ;
		}
		else if(x.atk == 8){
			x.name = x.name + " of Lightning" ;
		}
		else if(x.atk == 9){
			x.name = x.name + " of Anguish" ;
		}
		else if(x.atk == 10){
			x.name = x.name + " of The Psychopath" ;
		}

			

	}
}
