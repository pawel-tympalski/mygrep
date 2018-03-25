CFLAGS=-Wall -g

test_start: test_start.c ../listFile.c ../listFileName.c ../startFunctions.c
	gcc -o test_start test_start.c ../listFile.c ../listFileName.c ../startFunctions.c  `pkg-config --cflags --libs check` -fopenmp

clean:
	rm -f test_start
