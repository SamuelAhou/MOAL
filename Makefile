CC = gcc
CFLAGS = -g
LIB = -lm

SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)

all : main

main : LAF UF
	$(CC) LAF.o UF.o -o main $(LIB)

LAF.o : Functions/LAF.c
	gcc ./Functions/LAF.c -c ./Functions/LAF.o $(LIB)

UF.o : Functions/UF.c
	gcc ./Functions/LAF.c -c ./Functions/LAF.o $(LIB)