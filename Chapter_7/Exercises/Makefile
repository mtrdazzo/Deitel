# Compilation Flags
CXX=g++
CC=gcc
CXXFLAGS=-Wall -Wextra
DEBUG_FLAGS=-g -O0
RELEASE_FLAGS=-O3

# Source and output directories
SRC_DIR=.
BIN_DIR=$(SRC_DIR)/../bin
OBJ_DIR=$(BIN_DIR)/obj
MKDIR_P=mkdir -p

HEADERS=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJS:=$(SRC:.cpp=.o)
EXE:=$(SRC:.cpp=)
INCLUDES:=-I$(SRC_DIR)

__directories: ${BIN_DIR} ${OBJ_DIR}

${BIN_DIR}:
	@${MKDIR_P} ${BIN_DIR}

${OBJ_DIR}:
	@${MKDIR_P} ${OBJ_DIR}

all: __directories $(OBJS)

% : %.cpp

%.o : %.cpp
	@echo "\tCXX $<"
	@$(CXX) $(DEBUG_FLAGS) $(CXXFLAGS) $(INCLUDES) -c $<
	@mv $@ $(OBJ_DIR)

% : %.o
	@echo -en "\tCXX $^ -o $@"
	@$(CXX) $^ -o $@

clean:
	@rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*Ex*

extra-clean: clean
	@rm -Rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: Makefile clean
.PRECIOUS: $(BIN_DIR)/$(OBJS) $(OBJS)