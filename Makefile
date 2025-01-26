CC = g++
CFLAGS = -std=c++17 -Wall
OBJECTS = gamee.o game1_boom.o game2_navigation.o game3_rsp.o game4_hangman.o game5_surprise.o

all: gamee
	./gamee
gamee: $(OBJECTS)
	$(CC) $(CFLAGS) -o gamee $(OBJECTS)

gamee.o: gamee.cpp game1_boom.h game2_navigation.h game3_rsp.h game4_hangman.h game5_surprise.h
	$(CC) $(CFLAGS) -c gamee.cpp

game1_boom.o: game1_boom.cpp game1_boom.h
	$(CC) $(CFLAGS) -c game1_boom.cpp

game2_navigation.o: game2_navigation.cpp game2_navigation.h
	$(CC) $(CFLAGS) -c game2_navigation.cpp

game3_rsp.o: game3_rsp.cpp game3_rsp.h
	$(CC) $(CFLAGS) -c game3_rsp.cpp

game4_hangman.o: game4_hangman.cpp game4_hangman.h
	$(CC) $(CFLAGS) -c game4_hangman.cpp

game5_surprise.o: game5_surprise.cpp game5_surprise.h
	$(CC) $(CFLAGS) -c game5_surprise.cpp
clean:
	rm -f game $(OBJECTS)
