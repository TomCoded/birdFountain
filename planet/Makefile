#Makefile for OpenGL programs
#Bill Lenhart 

#To use, type:  make progname  (where progname.c is the source file)

PROGS = planet
USESCLASSES = ../TransformMaker/TransformMaker.o

planet : planet.cc $(USESCLASSES)
	$(CC) $(CCFLAGS) -o $@ $< $(INCLDIRS) $(LIBDIRS) $(LIBS) \
	$(USESCLASSES)

include ../include.mak  #The real one!  Make sure this exists.

