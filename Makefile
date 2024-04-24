all:
	gcc game.c racket.c ball.c bricks.c -lmingw32 -lSDL2main -lSDL2 --pedantic  -Wall
	.\a