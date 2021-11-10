CC = gcc
CFLAGS = -lpdcurses -I./include/
SOURCES = ./src/*.c

all: rogue run clean

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue

clean:
	del rogue.exe
