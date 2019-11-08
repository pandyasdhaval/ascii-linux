CC=g++
CFLAGS=-Wall -c

all: ansi

ansi: main.o Enemy.o GameSystem.o Level.o Player.o
	$(CC) main.o Enemy.o GameSystem.o Level.o Player.o -o ansi

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

clean:
	rm *.o ./ansi

run: all
	./ansi