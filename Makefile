include config.mak

#MAKE = gmake

SRCDIR = src
BINDIR = bin
TARGET = bin/birdFountain
INCDIR = inc
#LDFLAGS=$(LDFLAGS) -lTomFun -llinAlg -lglut -lGLU -lGL -L/usr/lib/x86_64-linux-gnu/ #-lMagick++-6.Q16 -lMagick++
GTESTFLAGS=-lgtest_main -lgtest -lpthread -lg

CCFILES1 = $(wildcard $(SRCDIR)/*/*.cc) $(wildcard $(SRCDIR)/*/*/*.cc) $(wildcard $(SRCDIR)/*/*/*/*.cc)
TESTFILES = $(filter-out %Main.cc,$(CCFILES1))
TESTOBJS = $(TESTFILES:.cc=.o)
CCFILES = $(filter-out %Test.cc,$(CCFILES1))
#CCFILES = $(FUNCCS)
OBJS = $(CCFILES:.cc=.o)
INCLDIRS = -I$(SRCDIR) -I$(INCDIR) $(addprefix -I,$(dir $(CCFILES)))
#CC = g++

#build 
$(TARGET): $(OBJS)
	mkdir -p $(dir $(TARGET))
	$(CC) $(CCFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)
	chmod 755 $@
	#Remember to run make install with permissions on $(prefix)

.cc.o:
	$(CC) $(CCFLAGS) -c -o $@ $^ $(INCLDIRS)

# install
install: $(TARGET)
	cp $(TARGET) $(prefix)/bin/

all: config.mak $(OBJS) $(TARGET)

copyheaders:
	cp $(SRCDIR)/*/*.h $(prefix)/include

mrproper: clean
	rm -f config.h config.mak

clean:	
	rm -f $(TARGET)
	rm -f $(OBJS) $(TESTOBJS)

test: $(TESTOBJS) 
	$(CC) $(CCFLAGS) $(TESTOBJS) -o bin/test $(LDFLAGS) $(GTESTFLAGS)
	bin/test





