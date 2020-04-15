#---------------------------------------------------------------------#
#Directories, setup
#---------------------------------------------------------------------#
IDIR =../include
ODIR =obj
LDIR =../lib
SDIR =src

CFLAGS=-I$(IDIR)

LIBS = -lcurses
#---------------------------------------------------------------------#
#Depensies
#---------------------------------------------------------------------#
_DEPS = main.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS)) 

_OBJ = CheckInfected.o ClearVirus.o CountNeighbour.o Drawboard.o EvalfutureBoard.o game_of_life.o Navigation.o SpawnVirus.o RandBoard.o kokgalaxy.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#---------------------------------------------------------------------#
# Compile
#---------------------------------------------------------------------#
$(ODIR)/%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

Runfile: $(OBJ) 	
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

#---------------------------------------------------------------------#
# Commands, install, clean												  
#---------------------------------------------------------------------#

install:
	mkdir src src/obj lib include
	mv *.c $(SDIR)/
	mv makefile $(SDIR)/
	mv *.h include/
	#If there is no .o files, error
	mv *.o $(SDIR)/$(ODIR)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 

