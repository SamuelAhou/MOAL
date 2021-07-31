CC = gcc
CFLAGS = -g
LIB = -lm

SRC = $(wildcard ./src/*.c)
OBJ = $(wildcard *.o)

all : main

main : 
	$(CC) $(SRC) main.c -o main $(LIB)
