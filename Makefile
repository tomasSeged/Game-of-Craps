#Makefile for Project 1
#Tomas H. Seged G0130011
#CS262, Lab Section 202
#Project 1


CFLAGS=-g -Wall -std=c89 -pedantic-errors
LIBS=-lm


all: Project1_tseged_202.c
	gcc $(CFLAGS) -o Project1_tseged_202 Project1_tseged_202.c $(LIBS)

clean:
	rm Project1_tseged_202
