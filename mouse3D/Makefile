#Makefile for OpenGL programs
#Bill Lenhart 

#To use, type:  make progname  (where progname.c is the source file)

PROGS = mouse3D

mouse3D : mouse3D.cc
	$(CC) $(CCFLAGS) -o $@ $< $(INCLDIRS) $(LIBDIRS) $(LIBS)

include ../include.mak  #The real one!  Make sure this exists.

