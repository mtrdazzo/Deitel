# Compilation Flags
CXX           = g++
STD           = -std=c++14
CXXFLAGS      = -Wall -Wextra
DEBUG_FLAGS   = -g -O0
RELEASE_FLAGS = -O3

# Source and output directories
SRC_DIR = Exercises
TST_DIR = Tests
BIN_DIR = bin
OBJ_DIR = obj
OUT_DIR = $(BIN_DIR) $(OBJ_DIR)
MKDIR_P = mkdir -p
INCLUDES = -I$(SRC_DIR)

SRC  = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(EXERCISES)))
EXES = $(addprefix $(BIN_DIR)/, $(EXERCISES))

EXERCISES = $(basename $(notdir $(SRC)))
OUT_FILES = $(call makeDirIf,$(BIN_DIR)) $(call makeDirIf,$(OBJ_DIR)) $(OBJS)

makeDirIf = $(filter-out $(wildcard $1), $1)

all: __print_settings $(OUT_FILES)

$(BIN_DIR) $(OBJ_DIR):
	@$(MKDIR_P) $@

debug: CXXFLAGS+=$(DEBUG_FLAGS)
debug: clean all

release: CXXFLAGS+=$(RELEASE_FLAGS)
release: clean all

__print_settings:
	@echo "CXX=$(CXX)"
	@echo "STD=$(STD)"
	@echo "CXXFLAGS=$(CXXFLAGS)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@echo "\tCXX $(notdir $<) -c"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BIN_DIR)/% : $(OBJ_DIR)/%.o
	@echo "\tCXX $^ -o $@"
	@$(CXX) $^ -o $@

maze: __print_settings __directories Ex_7_33.o Ex_7_34.o
	@$(CXX) $(OBJ_DIR)/Ex_7_33.o $(OBJ_DIR)/Ex_7_34.o -o $(BIN_DIR)/$@

clean:
	@rm -rf $(OBJS) $(EXES)

extra-clean: clean
	@rm -Rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: Makefile clean __print_settings
