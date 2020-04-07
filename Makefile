# Compilation Flags
CXX           = g++
STD           = -std=c++14

EXTRA_CFLAGS  = -Wall -Wextra
DEBUG_FLAGS   = -g -O0 -DDEBUG
RELEASE_FLAGS = -O3
CXXFLAGS      = $(EXTRA_CFLAGS) $(STD) -MD -MP

# Google Test Relative Directories
GOOGLE_TEST_HOME_DIR   = googletest/googletest
GOOGLE_TEST_INCL_DIR   = $(GOOGLE_TEST_HOME_DIR)/include
GOOGLE_TEST_SRC_DIR    = $(GOOGLE_TEST_HOME_DIR)/src
GOOGLE_TEST_SRC_FILES  = gtest_main.cc gtest-all.cc
GOOGLE_TEST_OBJ_FILES  = $(addprefix $(GOOGLE_TEST_OBJ_DIR)/, $(GOOGLE_TEST_SRC_FILES:.cc=.o))
GOOGLE_TEST_OBJ_DIR    = $(GOOGLE_TEST_HOME_DIR)/obj
GOOGLE_TEST_INCL_FLAGS = -I$(GOOGLE_TEST_HOME_DIR) -I$(GOOGLE_TEST_INCL_DIR) -pthread

SRC_DIR = Exercises
TST_DIR = Tests
BIN_DIR = $(addsuffix /bin, $(TST_DIR))
OBJ_DIR = $(addsuffix /obj, $(TST_DIR) $(SRC_DIR))
INCLUDE_FLAGS = -I$(SRC_DIR)

OUT_DIRS = $(GOOGLE_TEST_OBJ_DIR) $(BIN_DIR) $(OBJ_DIR)
MKDIR_P  = mkdir -p

# List of Source files, exercises, and object files
SRC_FILES     = $(wildcard $(SRC_DIR)/*.cpp)
TST_FILES     = $(wildcard $(TST_DIR)/*.cpp)
EXERCISES     = $(basename $(notdir $(SRC_FILES)))
TESTS         = $(basename $(notdir $(TST_FILES)))
TESTS        := $(subst tst_,,$(TESTS))
SRC_OBJ_FILES = $(addsuffix .o, $(addprefix $(SRC_DIR)/obj/,$(EXERCISES)))
TST_OBJ_FILES = $(addsuffix .o, $(addprefix $(TST_DIR)/obj/,$(basename $(notdir $(TST_FILES)))))
BIN_FILES     = $(addprefix $(BIN_DIR)/,$(TESTS))
OUT_FILES     = $(OBJ_FILES) \
	   			$(TST_OBJ_FILES) \
				$(BIN_FILES)

DEPS  = $(OBJ_FILES:.o=.d)
DEPS += $(GOOGLE_TEST_OBJ_FILES:.o=.d)
-include $(DEPS)

vpath % $(GOOGLE_TEST_SRC_DIR) $(SRC_DIR) $(TST_DIR)

includeIfNotExist = $(filter-out $(wildcard $1), $1)

all: __print_banner \
     __google_test \
	 __make_modules \
	 __make_test_modules \
	 __make_bin_files

debug: CXXFLAGS+=$(DEBUG_FLAGS)
debug: all

release: CXXFLAGS+=$(RELEASE_FLAGS)
release: clean all

__google_test: $(GOOGLE_TEST_OBJ_DIR) $(GOOGLE_TEST_OBJ_FILES)

__make_modules: $(SRC_DIR)/obj $(SRC_OBJ_FILES)

__make_test_modules: $(TST_DIR)/obj $(TST_OBJ_FILES)

__make_bin_files: $(BIN_DIR) $(BIN_FILES)

$(OUT_DIRS):
	@echo "\n  > Initialized directory $@\n"
	@$(MKDIR_P) $@

__print_settings:
	@echo "CXX=$(CXX)"
	@echo "STD=$(STD)"
	@echo "CXXFLAGS=$(CXXFLAGS)\n"

$(GOOGLE_TEST_OBJ_DIR)/%.o: %.cc
	@$(CXX) $(CXXFLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@
	@echo "\n  CXX $(notdir $<) -o $(notdir $@)\n      "

$(SRC_DIR)/obj/%.o : %.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@echo "\n  CXX -c $(notdir $<) -o $(notdir $@)\n      "

$(TST_DIR)/obj/%.o : %.cpp
	@echo "\n  CXX -c $(notdir $<) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(BIN_DIR)/% : $(TST_DIR)/obj/tst_%.o $(SRC_DIR)/obj/%.o
	@echo "\n  CXX $(notdir $^) $(notdir $(LIBGTEST)) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $^ $(GOOGLE_TEST_OBJ_FILES) $(GOOGLE_TEST_INCL_FLAGS) -o $@

clean:
	@rm -rf $(GOOGLE_TEST_OBJ_FILES) $(OUT_FILES) $(DEPS)

extra-clean: clean
	@rm -Rf $(OUT_DIRS)

__print_banner:
	@ \
	echo "   ________                __               ____ ";\
  	echo "  / ____/ /_  ____ _____  / /____  _____   / __ \ ";\
 	echo " / /   / __ \/ __  / __ \/ __/ _ \/ ___/  / /_/ /";\
	echo "/ /___/ / / / /_/ / /_/ / /_/  __/ /      \__, /";\
	echo "\____/_/ /_/\__,_/ .___/\__/\___/_/      /____/ ";\
	echo "                /_/                             ";\
	echo "";

.PHONY: Makefile clean __print_settings
.PRECIOUS: $(TST_DIR)/obj/%.o $(SRC_DIR)/obj/%.o
