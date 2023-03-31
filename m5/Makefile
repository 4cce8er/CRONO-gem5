# Wrapper Makefile to choose how to build the hooks library. Supported options:
#   1. Makefile.static - Create a static library
#   2. Makefile.shared - Create a shared library
#
# Creating a shared library is the default. This allows us to change the
# instrumentation of PARSEC workloads without recompiling the benchmark
# programs, but it makes things a little more complicated
#
# The shared library Makefile uses libtool, which is part of the PARSEC
# distribution. You also need to make sure that the shared library can be
# found at run time. The PARSEC framework already takes care of this.

#include Makefile.static
#include Makefile.shared

#OBJS=hooks.lo m5op_x86.lo m5_mmap.lo
#TARGET=libhooks.la

#M5CFLAGS?=-DM5OP_ADDR=0xFFFF0000 -DM5OP_PIC -Iinclude

#all: $(OBJS)
#	ar $(CFLAGS) -rc $(OBJS) -o $(TARGET)

#%.lo : %.c config.h m5op_x86.S m5_mmap.c
#	$(CXX) $(CFLAGS) -Wall -o $@ -c $<

#m5op_x86.lo : m5op_x86.S
#	$(CXX) $(M5CFLAGS) -o $@ -c $<

#m5_mmap.lo : m5_mmap.c
#	$(CXX) $(M5CFLAGS) -o $@ -c $<

#clean:
#	rm -f $(OBJS)
#	rm -f $(TARGET)
#	rm -f *.o

TARGET=hooks.o

#M5_FOLDER=/home/acceber/fs_img/crono/the_benchmark/CRONO/m5
CXXFLAGS += -I$(M5_FOLDER)/include -DM5OP_ADDR=0xFFFF0000

all: hooks.c
	$(CXX) -c hooks.c m5_mmap.c $(CXXFLAGS)

clean:
	rm *.o

.PHONY: all clean

