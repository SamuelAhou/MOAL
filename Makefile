CC = gcc
CFLAGS = -g
LIB = -lm

SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)

all : main

main : LAF.o UF.o
	$(CC) LAF.o UF.o -o main $(LIB)

LAF.o : ./src/LAF.c
	gcc ./src/LAF.c -c $(LIB)

UF.o : ./src/UF.c
	gcc ./src/UF.c -c $(LIB)