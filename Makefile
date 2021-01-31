CC = g++
CFLAGS = -c
CG = -std=c++11
CLINK = -o
SOURCES = main.cpp Controller.cpp Food.cpp Map.cpp Points.cpp Snake.cpp StartInterface.cpp Tools.cpp
OBJECTS = $(SOURCES:.cpp = .o)

all:HungrySnake

HungrySnake:$(OBJECTS)
	$(CC) $(OBJECTS) $(CLINK) HungrySnake $(CG)
Tools.o:Tools.cpp Tool.hpp
	$(CC) $(CFLAGS) Tools.cpp $(CG)
Points.o:Tools.o Points.cpp Points.hpp
	$(CC) $(CFLAGS) Points.cpp $(CG) 
StartInterface.o:Points.o StartInterface.hpp StartInterface.cpp
	$(CC) $(CFLAGS) StartInterface.cpp $(CG) 
Map.o:Points.o Map.hpp Map.cpp 
	$(CC) $(CFLAGS) Map.cpp $(CG) 
Food.o:Points.o Snake.o Food.cpp Food.hpp
	$(CC) $(CFLAGS) Snake.cpp Food.cpp $(CG) 
Snake.o:Points.o Food.o Snake.cpp Snake.hpp
	$(CC) $(CFLAGS) Snake.cpp Food.cpp $(CG) 
Controller.o:Tools.o Map.o StartInterface.o Food.o Snake.o Points.o Controller.cpp Controller.hpp
	$(CC) $(CFLAGS) Controller.cpp $(CG) 
main.o:main.cpp Controller.o
	$(CC) $(CFLAGS) main.cpp $(CG)
clean:
	rm -f *.o main 
