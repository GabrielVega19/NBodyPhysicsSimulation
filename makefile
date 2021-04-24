all: NBody

NBody: celestial.o universe.o  main.o
	g++ celestial.o universe.o main.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o NBody

universe.o: universe.cpp celestial.h
	g++ universe.cpp -std=c++14 -c -g -Og -Wall -Werror -pedantic

celestial.o: celestial.cpp celestial.h
	g++ celestial.cpp -std=c++14 -c -g -Og -Wall -Werror -pedantic

main.o: main.cpp
	g++ main.cpp -std=c++14 -c -g -Og -Wall -Werror -pedantic

clean:
	rm *.o NBody 