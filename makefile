CXX = g++
CXXFLAGS = -pedantic-errors -ansi -Wall
OBJS = map.o main.o character.o nonclass.o loot.o monsters.o
SRCS = main.cpp map.cpp character.cpp nonclass.cpp loot.cpp monsters.cpp
HEADERS = maze.hpp

maze: ${OBJS}
	${CXX} ${OBJS} -o maze

map_generation.o: map.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} map.cpp -c -o map.o

main.o: main.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} main.cpp -c -o main.o

character.o: character.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} character.cpp -c -o character.o

nonclass.o: nonclass.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} nonclass.cpp -c -o nonclass.o

loot.o: loot.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} loot.cpp -c -o loot.o

monsters.o: monsters.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} monsters.cpp -c -o monsters.o


clean:
	rm *.o
	rm maze

