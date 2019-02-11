CC=g++

BUILDDIR=./build
BINDIR=$(BUILDDIR)/bin
LIBDIR=$(BUILDDIR)/lib
OBJDIR=$(BUILDDIR)/obj

SRCDIR=./src
TESTDIR=./test

CPPFLAGS=-g -Wall -I ./include -I ./ps-lite/include -std=c++11

OBJS=$(patsubst ./src/%.cpp,$(OBJDIR)/%.o,$(wildcard ./src/*.cpp))

all: $(BUILDDIR) pslr

$(BUILDDIR):
	mkdir -p $(BINDIR) $(LIBDIR) $(OBJDIR)

pslr: $(OBJS)
	g++ $^ -o $(BINDIR)/$@ -L ./ps-lite/build -lpslite -L ./deps/lib -lzmq -lpthread -lprotobuf


$(OBJDIR)/%.o: ${SRCDIR}/%.cpp
	g++ -c $< -o $@ $(CPPFLAGS)

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	g++ -c $< -o $@ $(CPPFLAGS)
