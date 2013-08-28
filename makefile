OBJS = main.o game.o
CC = g++
DEBUG = -g
#CFLAGS = -Wall -c $(DEBUG)
#LFLAGS = -Wall $(DEBUG)

CFLAGS := $(shell sdl-config --cflags)
LDFLAGS := $(shell sdl-config --libs)


p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

main.o : main.cpp game.h game.cpp
	$(CC) $(CFLAGS) main.cpp

game.o : game.h game.cpp 
	$(CC) -c $(CFLAGS) game.cpp

clean:
	\rm *.o *~ p1

tar:
	tar cfv p1.tar main.cpp game.cpp game.h
