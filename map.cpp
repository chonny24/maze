#include "maze.hpp"

map::map(mazes& m){
	for (int i = 0 ; i < 40 ; i++){
		for(int j = 0 ; j < 40 ; j++){
			m.maparray[i][j] = ' ' ;
			m.foggymap[i][j] = ' ' ;
		}
	}
}


void map::generation(mazes& m, pos& finishpos){

	branches.startx.push_back(1) ;
	branches.starty.push_back(20) ;

	path(m,15,branches.startx[0],branches.starty[0]) ;

	for(int i = 1 ; i < 7 ; i = i + 1){
	path(m,5,branches.startx[i],branches.starty[i]) ;
	}

	finish(m,finishpos) ;



}




void map::finish(mazes& m , pos& finishpos){
	int found(0) , choice(0) , edgecount (0) , maxedge(0) ;
	std::vector<int> bestends ;

	coordinates temp ;

	for(int i = 38 ; i >= 1 ; i--){
		if(found != 1){
			for(int j = 0 ; j <= 38 ; j++){
				if(m.maparray[i][j] == 'O'){
					temp.starty.push_back(j) ;
					temp.startx.push_back(i) ;
					found = 1 ;
				}
			}
		}
	}

	for(unsigned int i = 0 ; i < temp.starty.size() ; i++){
		if(m.maparray[temp.startx[i]+1][temp.starty[i]] == ' '){
			edgecount++ ;
		}
		if(m.maparray[temp.startx[i]-1][temp.starty[i]] == ' '){
			edgecount++ ;
		}
		if(m.maparray[temp.startx[i]][temp.starty[i]+1] == ' '){
			edgecount++ ;
		}
		if(m.maparray[temp.startx[i]][temp.starty[i]-1] == ' '){
			edgecount++ ;
		}

		if(edgecount == maxedge){
			bestends.push_back(i) ;
		}

		if(edgecount > maxedge){
			maxedge = edgecount ;
			bestends.clear() ;
			bestends.push_back(i) ;
		}
		edgecount = 0 ;
	}


	choice = rand() % bestends.size() ;
	finishpos.x = temp.startx[bestends[choice]] ;
	finishpos.y = temp.starty[bestends[choice]] ;

	m.maparray[finishpos.x][finishpos.y] = 'F' ;

}



void map::path(mazes& m , int seedlength , int posx , int posy){
	int seedpos(0) , turngen(0) , start(1) , turnstore(0) , error(0);

	srand(time(NULL)) ;
	for(int i = 0 ; i < seedlength ; i++){
		seed.push_back(rand() % 3 + 3) ;
	}
	
	while(seedpos < seedlength){

		if(start == 0){
			turngen = rand() % 3 ;
		}

		if(start == 1){
			start = 0 ;
		}

		if(turnstore == 2 or turnstore == 1){
			turngen = 0 ;
		}

		if(turngen == 1 or turngen == 2){
			branches.startx.push_back(posx);
			branches.starty.push_back(posy);
		}

		if(turngen == 0){
			for(int i = 1 ; i <= seed[seedpos] ; i++){
				if(m.maparray[posx+i][posy + 1] == 'O' or
				   m.maparray[posx+i][posy - 1] == 'O'){
					error = 1 ;
				}
			}
			
			
			
			for(int i = 0 ; i < seed[seedpos] ; i++){ //RIGHT
				if(posx + seed[seedpos] <= 38 and
				   error != 1){	
					m.maparray[posx+i][posy]='O';
				}
			}
			if(posx + seed[seedpos] <= 38 and error != 1){
				posx = posx + seed[seedpos] ;
			}
			seedpos++ ;
			error = 0 ;
		}

		
		if(turngen == 1){
			for(int i = 1 ; i <= seed[seedpos] ; i++){
				if(m.maparray[posx-1][posy - i] == 'O' or
				   m.maparray[posx+1][posy - i] == 'O'){
					error = 1 ;
				}
			}

			for(int i = 0 ; i < seed[seedpos] ; i++){ //UP
				if(posy - seed[seedpos] >= 1){
					m.maparray[posx][posy-i]='O';
				}
			}
			if(posy - seed[seedpos] >= 1){
				posy = posy - seed[seedpos];
			}
			seedpos++ ;
			error = 0 ;
		}

		if(turngen == 2){
			for(int i = 1 ; i <= seed[seedpos] ; i++){
				if(m.maparray[posx-1][posy + i] == 'O' or
				   m.maparray[posx+1][posy + i] == 'O'){
					error = 1 ;
				}
			}

			for(int i = 0 ; i < seed[seedpos] ; i++){ //DOWN
				if(posy + i <= 38){
					m.maparray[posx][posy+i]='O';
				}
			}
			if(posy + seed[seedpos] <= 38){	
				posy = posy + seed[seedpos] ;
			}
			seedpos++ ;
			error = 0 ;
		}

		turnstore = turngen ;
	}
		
}
