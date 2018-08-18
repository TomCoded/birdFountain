#Makefile for OpenGL programs
#Bill Lenhart 

#To use, type:  make progname  (where progname.c is the source file)

PROGS = rectplanet
USESCLASSES = ../TransformMaker/TransformMaker.o \
	../Camera/Camera.o ../Ray/Ray.o \
	../Material/Material.o

rectplanet : rectplanet.cc $(USESCLASSES)
	$(CC) $(CCFLAGS) -o $@ $< $(USESCLASSES) $(INCLDIRS) \
	$(LIBDIRS) $(LIBS)

include ../include.mak  #The real one!  Make sure this exists.


