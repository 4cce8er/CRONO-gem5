
TRGS = community_lock community_atomic

LIBS += -lpthread -lrt

CXXFLAGS = -g --std=c++0x -O3
CXXFLAGS += -Wall -Werror

CXXFLAGS += -no-pie -DENABLE_HOOKS 
LDFLAGS += -L$(M5_FOLDER)/libx86 -lm5
HOOKS_OBJ = $(M5_FOLDER)/hooks.o $(M5_FOLDER)/m5_mmap.o

all: $(TRGS)

community_lock: community_lock.cc
community_atomic: community_atomic.cc

clean:
	rm -f $(TRGS) *.o *.dot

%: %.cc ;
	$(CXX) $(CXXFLAGS) $< $(HOOKS_OBJ) -o $@ $(LIBS) $(LDFLAGS)
