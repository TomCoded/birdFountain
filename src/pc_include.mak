# generic makefile for a set of classes for CS371

# (C) Anonymous1 

# Makefile variables

# which make
MAKE = gmake

# which compiler
CC = g++
# flags (always use debugging!)
#CCFLAGS = -g -pthread
CCFLAGS = -g

# where user-defined classes live
LOCALCLASSESDIR = .. 

# where to find header files
INCLDIRS = -IG:/Dev/include -IC:/Dev/mingw/include \
	-I$(LOCALCLASSESDIR) -IC:/cygwin/usr/include

# where to find libraries
LIBDIRS = -L/usr/cs-local/lib/cs371lib -L/usr/X11R6/lib -L/sw/lib
GLLIBS = -lglut -lGLU -lGL
XLIBS = -lXmu -lXi -lXext -lX11

# which system libraries to include
LIBS = -llinAlg $(GLLIBS) $(XLIBS) -lm 

#rules:

# @D refers to directory portion of file name; @F refers to file portion
# this line may have multiple targets
$(USESCLASSES) :
	cd $(@D) ; $(MAKE) $(@F)

$(CLASS).o : $(CLASS).cc $(CLASS).h
	$(CC) $(CCFLAGS) -c $< $(INCLDIRS)

$(CLASS)Test : $(CLASS)Test.cc $(CLASS).o $(USESCLASSES)
	$(CC) $(CCFLAGS) -o $@ $< $(CLASS).o $(USESCLASSES) \
	$(INCLDIRS) $(LIBDIRS) $(LIBS)

clean :
	rm -f *~

# PROGS is defined in each local directory

veryclean :
	$(MAKE) clean
	rm -f $(PROGS)

strip :
	$(MAKE) veryclean
	rm -f *.o





