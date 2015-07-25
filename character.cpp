#include "maze.hpp"

character::character(mazes& m){
	stats noinv ;
	noinv.hp = 5 ;
	noinv.crit = 0 ;
	noinv.dodge = 0 ;
	noinv.atk = 1 ;
	noinv.name = "NONE" ;

	player = noinv ;


	std::cout << std::endl << "Please enter name: " ;
	std::getline (std::cin, player.name) ;

	playerarmor = noinv ;
	playerweapon = noinv ;

	player.position.x = 1 ;
	player.position.y = 20 ;

	m.foggymap[player.position.x][player.position.y] = 'X' ;


}

void character::crafting(stats& armor1, mazes& m){
	
	if(playerarmor.hp >= armor1.hp){
		playerarmor.hp = playerarmor.hp + 2*armor1.hp/3 ;

		if(armor1.hp == 1){
			playerarmor.hp = playerarmor.hp + 1 ;
		}

		player.hp = playerarmor.hp ;
	}
	else{
		player.dodge = player.dodge - playerarmor.dodge ;
		
		armor1.hp = armor1.hp + 2*playerarmor.hp/3 ;
		if(playerarmor.hp == 1){
			armor1.hp = armor1.hp + 1 ;
		}

		playerarmor = armor1 ;

		player.hp = playerarmor.hp ;
		player.dodge = player.dodge + playerarmor.dodge ; 
	}

	m.maparray[player.position.x][player.position.y] = 'O' ;
}



void character::fighting(std::vector<stats>& x, mazes& m){
	int j , damage , random ;
	char choice ;
	int crit ;
	
	srand(time(NULL)) ;	

	for(unsigned int i = 0 ; i < x.size() ; i++){
		if (x[i].position.x == player.position.x and
		    x[i].position.y == player.position.y){
			j = i ;
		}
	}

	printplayerstats() ;
	::printfighting_main(x[j]) ;

	std::cout << "\nEnter a choice: Attack or Run (a/other):  " ;
	std::cin >> choice ;

	while(choice == 'a'){
		random = rand() % 100 ;
		if(player.crit > random){
			damage = player.atk * 2 ;
			crit = 1 ;

			playerweapon.crit = playerweapon.crit - 3 ;
			player.crit = playerweapon.crit ;
		}
		else if(random > 100 - 5*(5-player.crit/10) and player.atk > 1){
			damage = player.atk ;
			crit = 2 ;

			playerweapon.atk = playerweapon.atk - 1 ;
			player.atk = playerweapon.atk ;
		}
		else{
			damage = player.atk ;
			crit = 0 ;
		}

		printplayerstats() ;
		::printfighting_atk(damage,1,x[j].name,crit) ;

		std::cout << "Enter a key to continue:  " ;
		std::cin >> choice ;

		x[j].hp = x[j].hp - damage ;

		printplayerstats() ;
		::printfighting_main(x[j]) ;

		if(x[j].hp <=0){
			m.maparray[player.position.x][player.position.y]
				                                   = 'O' ;

			if(x[j].name == "The Gatekeeper"){
				::printwinner() ;
			}
			break ;
		}

		if(x[j].hp > 0){
			random = rand() % 100 ;
			if(player.dodge > random){
				damage = 0 ;
			}
			else{
				damage = x[j].atk ;
			}

			printplayerstats() ;
			::printfighting_atk(damage,2,x[j].name,0) ;

			std::cout << "Enter a key to continue: " ;
			std::cin >> choice ;

			playerarmor.hp = playerarmor.hp - damage ;
			player.hp = playerarmor.hp ;

			if(player.hp <= 0){
				::printloser() ; 
			}              
		
		}
		
		printplayerstats() ;
		::printfighting_main(x[j]) ;
		
		std::cout << "Enter a choice: Attack or Run (a/other): " ;
		std::cin >> choice ;
	}

	if(choice != 'a'){
		m.foggymap[player.position.x][player.position.y] = '!' ;
		
		if(previousmove == 'w'){
			player.position.y++ ;
		}
		if(previousmove == 'a'){
			player.position.x++ ;
		}
		if(previousmove == 's'){
			player.position.y-- ;
		}
		if(previousmove == 'd'){
			player.position.x-- ;
		}

		m.foggymap[player.position.x][player.position.y] = 'X' ;
	}


}

	






void character::inventory(char typeofspace, std::vector<stats>& x,mazes& m){
	char answer , error;
	int j ;
	stats temp ;
	
	for(unsigned int i = 0 ; i < x.size() ; i++){
		if (x[i].position.x == player.position.x and
		   x[i].position.y == player.position.y){
			j = i ;
		}
	}


	printplayerstats() ;
	::printloot(x[j],typeofspace) ;
	
	if(typeofspace == 'A'){
		std::cout << "\nWould you like to trade " 
			  << "or craft your current armor?" 
			  << " (y/c/other): " ;
	}
	else if(typeofspace == 'W'){
		std::cout << "\nWould you like to trade "
			  << "your current weapon?(y/other): " ;
	}

	std::cin >> answer ;

	if(answer == 'c'){
		if(typeofspace == 'A'){
			crafting(x[j],m) ;
		}
		else{
			printplayerstats() ;
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				  << "\n\n\n\n\t\t\t"
				  << "You can only craft with armor" 
			          << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				  << "\n\n\n\n\n"
				  << "\n______________________________"
				  << "______________________________"
				  << "______________\n"
				  << "Enter a key to continue: " ;
			
			std::cin >> error ;
		}
	}

	if(answer == 'y'){

		if(typeofspace == 'A'){
			player.dodge = player.dodge
			           - playerarmor.dodge ;
			
			if(playerarmor.name != "NONE"){
				playerarmor.position.x = x[j].position.x ;
				playerarmor.position.y = x[j].position.y ;
				
				temp = playerarmor ;
				playerarmor = x[j] ;
				x[j] = temp ;
			
			}
			else{
				playerarmor = x[j] ;
				m.maparray[player.position.x][player.position.y] = 'O' ;
			}
				

			player.hp = playerarmor.hp ;
			player.dodge = player.dodge
				           + playerarmor.dodge ;
		}
		else if(typeofspace == 'W'){
			player.dodge = player.dodge
				           - playerweapon.dodge ;
			
			if(playerweapon.name != "NONE"){
				playerweapon.position.x = x[j].position.x ;
				playerweapon.position.y = x[j].position.y ;
				
				temp = playerweapon ;
				playerweapon = x[j] ;
				x[j] = temp ;
			}
			else{
				playerweapon = x[j] ;
				m.maparray[player.position.x][player.position.y] = 'O' ;
			}
			
				
			player.atk= playerweapon.atk ;
			player.dodge = player.dodge
				           + playerweapon.dodge ;
			player.crit = playerweapon.crit ;
		}
	}

}




char character::movement(mazes& m){

	char move ;
	int hitwall(0) ;

	if(m.foggymap[player.position.x+1][player.position.y] !='O'  and
	   m.foggymap[player.position.x+1][player.position.y] !='@'  and
	   m.foggymap[player.position.x+1][player.position.y] !='$'  and
	   m.foggymap[player.position.x+1][player.position.y] !='!'  and
	   m.maparray[player.position.x+1][player.position.y] != ' '){
	
		m.foggymap[player.position.x+1][player.position.y] = '?' ;
	}
	if(m.foggymap[player.position.x-1][player.position.y] !='O'  and
	   m.foggymap[player.position.x-1][player.position.y] !='@'  and
	   m.foggymap[player.position.x-1][player.position.y] !='$'  and
	   m.foggymap[player.position.x-1][player.position.y] !='!'  and
	   m.maparray[player.position.x-1][player.position.y] != ' '){
	
		m.foggymap[player.position.x-1][player.position.y] = '?' ;
	}
	if(m.foggymap[player.position.x][player.position.y+1] !='O' and
	   m.foggymap[player.position.x][player.position.y+1] !='@' and
	   m.foggymap[player.position.x][player.position.y+1] !='$' and
	   m.foggymap[player.position.x][player.position.y+1] !='!' and
	   m.maparray[player.position.x][player.position.y+1] != ' '){
	
		m.foggymap[player.position.x][player.position.y+1] = '?' ;
	}
	if(m.foggymap[player.position.x][player.position.y-1] !='O' and
	   m.foggymap[player.position.x][player.position.y-1] !='@' and
	   m.foggymap[player.position.x][player.position.y-1] !='$' and
	   m.foggymap[player.position.x][player.position.y-1] !='!' and
	   m.maparray[player.position.x][player.position.y-1] != ' '){
	
		m.foggymap[player.position.x][player.position.y-1] = '?' ;
	}
		
			
	printplayerstats() ;
	::printmap(m) ;	


	if(m.maparray[player.position.x][player.position.y]=='A'){
		
		m.foggymap[player.position.x][player.position.y] = '@' ;
	}
	   
		
	else if(m.maparray[player.position.x][player.position.y]=='W'){
			
		m.foggymap[player.position.x][player.position.y] = '$' ;
	}

	else if(m.maparray[player.position.x][player.position.y]=='M'){

		m.foggymap[player.position.x][player.position.y] = '!' ;

	}	

	else{
		m.foggymap[player.position.x][player.position.y] = 'O' ;
	}
	
		

	do{
		hitwall = 0 ;

		std::cout << "\nPlease enter a direction to move (WASD): ";
		std::cin >> move ;

		if(move == 'w' and 
		   m.maparray[player.position.x][player.position.y-1]!=' '){
			m.foggymap[player.position.x][player.position.y--];

			previousmove = 'w' ;
		}
		else if(move == 'a' and 
		        m.maparray[player.position.x - 1][player.position.y]
							!= ' '){

			m.foggymap[player.position.x--][player.position.y];
			
			previousmove = 'a' ;
		}
		else if(move == 's' and 
			m.maparray[player.position.x][player.position.y + 1]
							!= ' '){

			m.foggymap[player.position.x][player.position.y++];
			
			previousmove = 's' ;
		}
		else if(move == 'd' and 
			m.maparray[player.position.x + 1][player.position.y]
							!= ' '){
		
			m.foggymap[player.position.x++][player.position.y];
			
			previousmove = 'd' ;
		}
	
		else{
			std::cout << "\nYou hit a wall" ;
			hitwall = 1 ;
		}

	}while(hitwall == 1) ;

	m.foggymap[player.position.x][player.position.y] = 'X' ;
	
	
	return(m.maparray[player.position.x][player.position.y]) ;
	



}

void character::printplayerstats(){
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		  << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" 
		  << player.name << "    HP: " << player.hp 
		  <<"    ATK: " << player.atk << "    CRIT%: "
		  << player.crit << "    DODGE%: " << player.dodge
		  << "\n\nWeapon:  " <<  "A/C/D: " << playerweapon.atk
		  << "/" << playerweapon.crit  << "/" << playerweapon.dodge
		  << "\t" << playerweapon.name << std::endl 
		  << "Armor:   " << "HP/D:  " << playerarmor.hp << "/" 
		  << playerarmor.dodge << "\t" << playerarmor.name
		  << "\n________________________________________"
		  << "___________________________________" ;
}
