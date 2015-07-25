#include "maze.hpp"

void printintro(){
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n"
		  << "\n____________________________________"
		  << "_______________________________________\n"
		  << "**********HOW TO PLAY: \n\n"
		  << "      You are marked as an 'X' on the map. A '?'" 
		  << " represents a place you\n"
		  << "      have not yet visited. Move with WASD.\n\n\n"
	          << "      As you explore the map, you will find monsters"
		  << ", armor, and weapons.\n"
		  << "      On the map, weapons are indicated as '$',"
		  << " armor as '@', and monsters\n"
		  << "      as '!'\n\n\n"
		  << "      You have 4 statistics:\n"
	  	  << "          HP:    Your health. This comes from your"
		  << " armor. If it reaches 0,\n"
		  << "                 you die.\n\n"
		  << "          ATK:   This is the amount of damage you do"
		  << " per attack. This comes\n"
		  << "                 from your weapon.\n\n"
		  << "          CRIT:  This is your chance to critical hit"
		  << ". If you happen to get a\n"
		  << "                 a critical hit, you will do double"
		  << " damage but your chance to\n"
		  << "                 crit on your weapon will"
		  << " permanently decrease by 3. Also,\n"
		  << "                 the lower your crit is, you have"
		  << " a higher chance of getting\n"
		  << "                 a 'Terrible Aim'. If this happens,"
		  << " your weapon's atk will\n"
		  << "                 permanently decrease by 1. Your"
		  << " crit value comes from your\n"
		  << "                 weapon.\n\n"
		  << "          DODGE: This is your chance to dodge an"
		  << " attack. If you dodge, you,\n"
		  << "                 will take 0 damage. This comes"
		  << " from both your armor and \n"
		  << "                 weapon.\n\n\n"
		  << "       You can also craft armor together. If you"
		  << " find an armor, you can press\n"
		  << "       'c' and add 2/3 the HP of the armor with the"
		  << " lowest HP to the other.\n\n\n"
		  << "       Your goal is to make it though the maze and"
		  << " defeat The Gatekeeper.\n"
		  << "\n\n\n                                  Good luck\n" 
		  << "\n________________________________________"
		  << "___________________________________\n" ;
}



void printmap(mazes m){
         for(int i = 0 ; i < 40 ; i++){
                 std::cout << std::endl ;
                 for(int j = 0 ; j < 40 ; j++){
			 //std::cout << m.maparray[j][i] ;
			 std::cout << m.foggymap[j][i] ;
                 }
         }
         std::cout << "\n________________________________________"
		   << "___________________________________" << std::endl ;
 }
	

void printloot(stats x, char typeofspace){
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		  << "You found: " << x.name << "!" ;

	if(typeofspace == 'A'){
		std::cout << "\n\n\n   (HP/D): " << x.hp 
			  << "/" << x.dodge ;
	}

	if(typeofspace == 'W'){
		std::cout << "\n\n\n   (A/C/D): " << x.atk << "/"
			  << x.crit << "/" << x.dodge ;
	}

	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		  << "________________________________________"
		  << "___________________________________\n" ;
}

void printwinner(){
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		  << "________________________________________"
		  << "___________________________________\n"
	          << "\n\n\n"
		  << "\t                        ###\n"
	          << "\t                      ### ###\n"
	          << "\t                     ###   ###\n"
	          << "\t                    ###     ###\n"
	          << "\t                   ###       ###\n"
	          << "\t                  ###         ###\n"
	          << "\t       #############	       #############\n"
		  << "\t       ##                                 ##\n"
		  << "\t        ####                           ####\n"
		  << "\t          ####                       ####\n"
		  << "\t             ####                 ####\n"
		  << "\t                ###             ###\n"
		  << "\t                 ##             ##\n"
		  << "\t               ##      #####      ##\n"
		  << "\t              ##     ###   ###     ##\n"
		  << "\t             ##     ##       ##     ##\n"
		  << "\t            ##    ###         ###    ##\n"
		  << "\t           ##   ##               ##   ##\n"
		  << "\t           #####                   ####\n" ;

	std::cout << "\n\n\n\n\t\t\t"
		  << "********************\n\t\t\t"
		  << " CONGRATULATIONS!!!\n\t\t\t"
		  << "      YOU WIN!\n\t\t\t"
		  << "********************\n"
		  << "\n\n\n\n\n\n\n\n\n\n\n"
		  << "________________________________________"
		  << "___________________________________\n";

	exit(0) ;
}



void printloser(){
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		  << "________________________________________"
		  << "___________________________________\n"
	          << "\n\n\n"
		  << "\t       #####                            #####\n"
	          << "\t         #####                        ##### \n"
	          << "\t           #####                    #####  \n"
	          << "\t             #####                #####   \n"
	          << "\t               #####            #####\n"
	          << "\t                 #####        #####\n"
	          << "\t                   #####    ##### \n"
		  << "\t                     ##########\n"
		  << "\t                       ######\n"
		  << "\t                     ##########\n"
		  << "\t                   #####    #####\n"
		  << "\t                 #####        #####\n"
		  << "\t               #####            #####\n"
		  << "\t             #####                #####\n"
		  << "\t           #####                    #####\n"
		  << "\t         #####                        #####\n"
		  << "\t       #####                            #####\n"
		  << "\t \n"
		  << "\t \n" ;

	std::cout << "\n\n\n\n\t\t\t"
		  << "^^^^^^^^^^^^^^^^^^^^\n\t\t\t"
		  << "        YOU         \n\t\t\t"
		  << "     HAVE DIED      \n\t\t\t"
		  << "^^^^^^^^^^^^^^^^^^^^\n"
		  << "\n\n\n\n\n\n\n\n\n\n\n"
		  << "________________________________________"
		  << "___________________________________\n";

	exit(0) ;
}



void printfighting_main(stats monster){
	std::cout << "\n\n\n\t\t\t         ####\n"
		  << "\t\t\t      ##########\n"
		  << "\t\t\t     ####    ####\n"
		  << "\t\t\t    ###        ###\n"
		  << "\t\t\t   ###          ###\n"
		  << "\t\t\t  ###            ###\n"
		  << "\t\t\t   ###          ###\n"
		  << "\t\t\t               ###\n"
		  << "\t\t\t              ###\n"
		  << "\t\t\t             ###\n"
		  << "\t\t\t           ####\n"
		  << "\t\t\t          ####\n"
		  << "\t\t\t         ####\n"
		  << "\t\t\t         ###\n"
		  << "\t\t\t         ###\n"
		  << "\t\t\t         ###\n"
		  << "\t\t\t         ###\n"
		  << "\t\t\t          #\n\n\n\n"
		  << "\t\t\t          ##\n"
		  << "\t\t\t         ####\n"
		  << "\t\t\t          ##\n\n\n" ;


	std::cout << "\n\n\t\t    " << monster.name << " has " << monster.hp
	          << " health\n\n\n\n\n\n\n\n\n\n"
	  	  << "________________________________________"
	          << "___________________________________\n" ;
}


void printfighting_atk(int damage, int x, std::string monster,int crit){
		std::cout << "\n\n\n\n\n\n\n\n\n\n" ;

		if(crit == 1){
			std::cout << "\t\t\t******CRITICAL HIT!******\n"
				  << "\t\t\t You hit for 2x, but your\n"
				  << "\t\t\t weapon has been slightly\n"
				  << "\t\t\t        damaged.\n" 
				  << "\t\t\t*************************\n" ;
		}

		else if(crit == 2){
			std::cout << "\t\t\t^^^^^^TERRIBLE AIM!^^^^^^\n"
				  << "\t\t\t You miss the target and \n"
				  << "\t\t\t hit the wall by mistake,\n"
				  << "\t\t\t  damaging your weapon.  \n"
				  << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^\n" ;
		}

		else if(damage == 0){
			std::cout << "\t\t\t*******YOU DODGED!*******\n"
				  << "\t\t\t The monster has missed! \n"
				  << "\t\t\t You take no damage and  \n"
				  << "\t\t\t  live to fight again!   \n" 
				  << "\t\t\t*************************\n" ;
		}
		else{
			std::cout << "\n\n\n\n" ;
		}

		std::cout << "\n\n\n\n\n\n" ;

		if(x == 1){
			std::cout << "\t\t\tYou " ;
		}
		else{
			std::cout << "\t\t\t" << monster << " " ;
		}

		std::cout << "hit for " << damage << " damage." 
			  << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
			  << "________________________________________"
			  << "___________________________________\n" ;
}



void calctotalplaces(mazes& m,int istart,int iend,int jstart,int jend){
	int counter(0) ;
	m.places.clear() ;
         for(int i = istart ; i < iend ; i ++){
                 for(int j = jstart ; j < jend ; j ++){
                         if(m.maparray[j][i] == 'O'){
                                 m.places.push_back(pos()) ;
                                 m.places[counter].x = j ;
                                 m.places[counter].y = i ;
                                 counter++ ;
                         }
                 }
         }
}
