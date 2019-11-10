CC=g++
CFLAGS=-Wall -c -Ilib

all: ascii

ascii: bin/main.o bin/Enemy.o bin/GameSystem.o bin/Level.o bin/Player.o bin/Graphics.o bin/Entity.o
	$(CC) bin/main.o bin/Enemy.o bin/GameSystem.o bin/Level.o bin/Player.o bin/Graphics.o bin/Entity.o -o ascii -lncurses

bin/main.o: src/main.cpp lib/GameSystem.h
	$(CC) $(CFLAGS) src/main.cpp -o bin/main.o -lncurses

bin/Enemy.o: src/Enemy.cpp lib/Enemy.h
	$(CC) $(CFLAGS) src/Enemy.cpp -o bin/Enemy.o -lncurses

bin/GameSystem.o: src/GameSystem.cpp lib/GameSystem.h
	$(CC) $(CFLAGS) src/GameSystem.cpp -o bin/GameSystem.o -lncurses

bin/Level.o: src/Level.cpp lib/Level.h
	$(CC) $(CFLAGS) src/Level.cpp -o bin/Level.o -lncurses

bin/Player.o: src/Player.cpp lib/Player.h
	$(CC) $(CFLAGS) src/Player.cpp -o bin/Player.o -lncurses

bin/Graphics.o: src/Graphics.cpp lib/Graphics.h
	$(CC) $(CFLAGS) src/Graphics.cpp -o bin/Graphics.o -lncurses

bin/Entity.o: src/Entity.cpp lib/Entity.h
	$(CC) $(CFLAGS) src/Entity.cpp -o bin/Entity.o -lncurses
clean:
	rm *.o ./ascii

run: all
	./ascii
