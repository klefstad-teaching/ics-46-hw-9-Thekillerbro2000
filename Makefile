CXXFLAGS=-Isrc -ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
all: main l_main
main: src/dijkstras_main.cpp dijkstras.o
	g++ $(CXXFLAGS) src/dijkstras_main.cpp dijkstras.o -o main
l_main: src/ladder_main.cpp ladder.o
	g++ $(CXXFLAGS) src/ladder_main.cpp ladder.o -o l_main
dijkstras.o: src/dijkstras.cpp
	g++ $(CXXFLAGS) -c src/dijkstras.cpp -o dijkstras.o
ladder.o: src/ladder.cpp
	g++ $(CXXFLAGS) -c src/ladder.cpp -o ladder.o	
clean:
	/bin/rm l_main main *.o

#valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes