CC = g++
CFLAGS = -c
CG = -std=c++17
CLINK = -o
SOURCES = main.cpp Controller.cpp Food.cpp Map.cpp Points.cpp Snake.cpp StartInterface.cpp Tools.cpp
OBJECTS = $(SOURCES:.cpp = .o)

all:HungrySnake

HungrySnake:$(OBJECTS)
	$(CC) $(OBJECTS) $(CLINK) HungrySnake
Tools.o:Tools.cpp Tool.hpp
	$(CC) $(CG) $(CFLAGS) Tools.cpp 
Points.o:Tools.o Points.cpp Points.hpp
	$(CC) $(CG) $(CFLAGS) Points.cpp 
StartInterface.o:Points.o StartInterface.hpp StartInterface.cpp
	$(CC) $(CG) $(CFLAGS) StartInterface.cpp 
Map.o:Points.o Map.hpp Map.cpp 
	$(CC) $(CG) $(CFLAGS) Map.cpp 
Food.o:Points.o Snake.o Food.cpp Food.hpp
	$(CC) $(CG) $(CFLAGS) Snake.cpp Food.cpp 
Snake.o:Points.o Food.o Snake.cpp Snake.hpp
	$(CC) $(CG) $(CFLAGS) Snake.cpp Food.cpp 
Controller.o:Tools.o Map.o StartInterface.o Food.o Snake.o Points.o Controller.cpp Controller.hpp
	$(CC) $(CG) $(CFLAGS) Controller.cpp 
clean:
	rm -rf *o main
