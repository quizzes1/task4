all:
	gcc game.c racket.c ball.c bricks.c widgets.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image --pedantic  -Wall
	.\a