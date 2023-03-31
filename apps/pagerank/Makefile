
TRGS = pagerank pagerank_lock

LIBS += -lpthread -lrt

CXXFLAGS = -g --std=c++0x -O3
CXXFLAGS += -Wall -Werror

CXXFLAGS += -no-pie -DENABLE_HOOKS 
LDFLAGS += -L$(M5_FOLDER)/libx86 -lm5
HOOKS_OBJ = $(M5_FOLDER)/hooks.o $(M5_FOLDER)/m5_mmap.o

all: $(TRGS)

pagerank: pagerank.cc
pagerank_lock: pagerank_lock.cc

clean:
	rm -f $(TRGS) *.o *.dot
	rm -f file.txt

%: %.cc ;
	$(CXX) $(CXXFLAGS) $< $(HOOKS_OBJ) -o $@ $(LIBS) $(LDFLAGS)
