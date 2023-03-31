
TRGS = triangle_counting_lock triangle_counting_atomic sorted_neighbors_tri_lock

LIBS += -lpthread -lrt

CXXFLAGS = -g --std=c++0x -O3
CXXFLAGS += #-Wall -Werror

CXXFLAGS += -no-pie -DENABLE_HOOKS 
LDFLAGS += -L$(M5_FOLDER)/libx86 -lm5
HOOKS_OBJ = $(M5_FOLDER)/hooks.o $(M5_FOLDER)/m5_mmap.o

all: $(TRGS)

triangle_counting_lock: triangle_counting_lock.cc
triangle_counting_atomic: triangle_counting_atomic.cc
sorted_neighbors_tri_lock: sorted_neighbors_tri_lock.cc

clean:
	rm -f $(TRGS) *.o *.dot

%: %.cc ;
	$(CXX) $(CXXFLAGS) $< $(HOOKS_OBJ) -o $@ $(LIBS) $(LDFLAGS)
