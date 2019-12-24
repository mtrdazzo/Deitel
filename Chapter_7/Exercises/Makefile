CXX=g++
CC=gcc
CXXFLAGS=-Wall -Wextra
DEBUG_FLAGS=-g -O0
RELEASE_FLAGS=-O3
SRC_DIR=.

HEADERS=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJS:=$(SRC:.cpp=.o)
EXE:=$(SRC:.cpp=)
INCLUDES:=-I$(SRC_DIR)

all: $(OBJS)	

% : %.cpp

%.o : %.cpp
	@echo -en "\tCXX $<"
	$(CXX) $(DEBUG_FLAGS) $(CXXFLAGS) $(INCLUDES) -c $^

%: %.o
	@echo -en "\tCXX $^ -o $@"
	@$(CXX) $^ -o $@

clean:
	@echo "Cleaning directory..."
	@rm -rf $(OBJS) $(EXE)

.PHONY: Makefile clean
.PRECIOUS: $(OBJS)