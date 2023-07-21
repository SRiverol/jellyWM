debug : main.o
	wayland-scanner client-header < protocol.xml > protocol.h
	wayland-scanner server-header < protocol.xml > protocol.h
	wayland-scanner private-code < protocol.xml > protocol.c
	
	gcc -g -o JellyWM.debug main.o

main.o : main.c
	gcc -g -Wall -c main.c -lwayland-server

clean:
	rm *.o *.debug
