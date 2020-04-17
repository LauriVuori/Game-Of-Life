#http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#Needed folders Main(include, lib, src(obj))
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lncurses

_DEPS = main.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS)) 

_OBJ = CheckInfected.o ClearVirus.o CountNeighbour.o Drawboard.o EvalfutureBoard.o game_of_life.o Navigation.o SpawnVirus.o RandBoard.o kokgalaxy.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

Runfile: $(OBJ) 	
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
.PHONY: clean
					
clean:
	rm -f $(ODIR)/*.o