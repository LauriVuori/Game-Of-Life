#http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#Needed folders Main(include, lib, src(obj))
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -pedantic -Wextra

ODIR=obj
LDIR=../lib
SDIR=src

LIBS=-lncurses

_DEPS = game_of_life.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS)) 

_OBJ = CheckInfected.o ClearVirus.o CountNeighbour.o Drawboard.o EvalfutureBoard.o game_of_life.o Navigation.o SpawnVirus.o RandBoard.o kokgalaxy.o SpawnCure.o CheckCure.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

Runfile: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

$(ODIR)/%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)


	
.PHONY: clean
					
clean:
	rm -f $(ODIR)/*.o ./*.exe