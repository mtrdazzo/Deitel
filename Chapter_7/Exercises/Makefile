CXX=g++
CC=gcc
CXXFLAGS=-Wall -Wextra
DEBUG_FLAGS=-g -O0
RELEASE_FLAGS=-O3
SRC_DIR=.
BIN_DIR=$(SRC_DIR)/../bin
MKDIR_P=mkdir -p

HEADERS=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJS:=$(SRC:.cpp=.o)
EXE:=$(SRC:.cpp=)
INCLUDES:=-I$(SRC_DIR)

__directories: ${BIN_DIR}

${BIN_DIR}:
	${MKDIR_P} ${BIN_DIR}

all: __directories $(OBJS)

% : %.cpp

%.o : %.cpp
	@echo -en "\tCXX $<"
	$(CXX) $(DEBUG_FLAGS) $(CXXFLAGS) $(INCLUDES) -c $^

% : %.o
	@echo -en "\tCXX $^ -o $@"
	@$(CXX) $^ -o $@

clean:
	@rm -rf $(OBJS) $(EXE)

.PHONY: Makefile clean
.PRECIOUS: $(OBJS)