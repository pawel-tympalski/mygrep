CFLAGS=-Wall -Werror -g

start: start.c listFile.c startFunctions.c listFileName.c
	gcc -o start start.c listFile.c startFunctions.c listFileName.c -I. -fopenmp

clean:
	rm -f start
