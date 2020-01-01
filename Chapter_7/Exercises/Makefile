# Compilation Flags
CXX=g++
CC=gcc
CXXFLAGS=-Wall -Wextra
DEBUG_FLAGS=-g -O0
RELEASE_FLAGS=-O3

# Source and output directories
SRC_DIR=.
BIN_DIR=$(SRC_DIR)/../bin
OBJ_DIR:=$(BIN_DIR)/obj
MKDIR_P=mkdir -p

HEADERS=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJS:=$(foreach file,$(SRC:.cpp=.o),$(OBJ_DIR)/$(file))
EXE:=$(SRC:.cpp=)
INCLUDES:=-I$(SRC_DIR)

all: clean __print_settings __directories $(OBJS)

__directories: ${BIN_DIR} ${OBJ_DIR}

${BIN_DIR}:
	@${MKDIR_P} ${BIN_DIR}

${OBJ_DIR}:
	@${MKDIR_P} ${OBJ_DIR}

debug: CXXFLAGS+=$(DEBUG_FLAGS)
debug: all

release: CXXFLAGS+=$(RELEASE_FLAGS)
release: all

__print_settings:
	@echo "CXX=$(CXX)"
	@echo "CXXFLAGS=$(CXXFLAGS)"

%.o : __directories $(OBJ_DIR)/%.o
	@echo

% : %.o

$(OBJ_DIR)/%.o : %.cpp
	@echo "\tCXX $< -c"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<
	@mv $(subst .cpp,.o,$<) $(OBJ_DIR)

$(BIN_DIR)/% : $(OBJ_DIR)/%.o
	@echo "\tCXX $^ -o $@"
	@$(CXX) $^ -o $@

maze: __print_settings __directories Ex_7_33.o Ex_7_34.o
	@$(CXX) $(OBJ_DIR)/Ex_7_33.o $(OBJ_DIR)/Ex_7_34.o -o $(BIN_DIR)/$@

clean:
	@rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*Ex* $(SRC_DIR)/*.o $(EXE)

extra-clean: clean
	@rm -Rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: Makefile clean __print_settings
.PRECIOUS: $(BIN_DIR)/$(OBJS) $(OBJS)