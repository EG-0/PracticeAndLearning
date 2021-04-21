graph: main.o graph.o
	g++ -o graph main.o graph.o
	
main.o: main.cpp graph.h
	g++ -c main.cpp
	
graph.o: graph.cpp graph.h
	g++ -c graph.cpp
