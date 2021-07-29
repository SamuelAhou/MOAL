CC = gcc
CFLAGS = -g
LIB = -lm

SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)

all : main

main : LAF UF
	$(CC) LAF.o UF.o -o main $(LIB)

LAF.o : src/LAF.c
	gcc ./src/LAF.c -c LAF.o $(LIB)

UF.o : src/UF.c
	gcc ./src/UF.c -c UF.o $(LIB)