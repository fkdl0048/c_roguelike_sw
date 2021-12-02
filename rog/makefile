CC = gcc
CFLAGS = -lpdcurses -Im -I./include/
SOURCES = ./src/*.c

all: rogue run clean

mac: mac_gcc mac_run mac_clean

mac_gcc:
	$(CC) $(SOURCES) -lncurses -Im -I./include/ -o rogue

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue.exe

mac_run:
	./rogue

clean:
	del rogue.exe

mac_clean:
	rm rogue
