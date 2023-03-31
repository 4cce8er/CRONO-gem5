
TRGS = bfs bfs_atomic

LIBS += -lpthread -lrt

CXXFLAGS = -g --std=c++0x -O3
CXXFLAGS += -Wall

CXXFLAGS += -no-pie -DENABLE_HOOKS 
LDFLAGS += -L$(M5_FOLDER)/libx86 -lm5
HOOKS_OBJ = $(M5_FOLDER)/hooks.o $(M5_FOLDER)/m5_mmap.o

all: $(TRGS)

bfs: bfs.cc
bfs_atomic: bfs_atomic.cc

clean:
	rm -f $(TRGS) *.o *.dot
	rm -f myfile.txt

%: %.cc ;
	$(CXX) $(CXXFLAGS) $< $(HOOKS_OBJ) -o $@ $(LIBS) $(LDFLAGS)
