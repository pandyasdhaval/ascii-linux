CC=g++
CFLAGS=-Wall -c

all: ascii

ascii: main.o Enemy.o GameSystem.o Level.o Player.o Graphics.o Entity.o
	$(CC) main.o Enemy.o GameSystem.o Level.o Player.o Graphics.o Entity.o -o ascii -lncurses

main.o: main.cpp GameSystem.h
	$(CC) $(CFLAGS) main.cpp -o main.o

Enemy.o: Enemy.cpp Enemy.h
	$(CC) $(CFLAGS) Enemy.cpp -o Enemy.o

GameSystem.o: GameSystem.cpp GameSystem.h
	$(CC) $(CFLAGS) GameSystem.cpp -o GameSystem.o

Level.o: Level.cpp Level.h
	$(CC) $(CFLAGS) Level.cpp -o Level.o

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp -o Player.o

Graphics.o: Graphics.cpp Graphics.h
	$(CC) $(CFLAGS) Graphics.cpp -o Graphics.o

Entity.o: Entity.cpp Entity.h
	$(CC) $(CFLAGS) Entity.cpp -o Entity.o
clean:
	rm *.o ./ascii

run: all
	./ascii
