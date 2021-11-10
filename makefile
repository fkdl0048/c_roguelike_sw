CC = gcc
CFLAGS = -lpdcurses -I./include/
SOURCES = ./src/*.c

all: rogue run clean

mac: mac_gcc run mac_clean

mac_gcc:
	$(CC) $(SOURCES) -lncurses -I./include/ -o rogue

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue

clean:
	del rogue.exe

mac_clean:
	rm rogue
