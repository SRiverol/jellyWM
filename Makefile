debug : main.o
	gcc -g -o JellyWM.debug main.o

main.o : main.c
	gcc -g -Wall -c main.c

clean:
	rm *.o *.debug