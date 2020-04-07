# Compilation Flags
CXX           = g++
STD           = -std=c++14

# Determine build flags
DEBUG_FLAG   = debug
RELEASE_FLAG = release
GCOV_FLAG    = gcov

# Compiler flags
EXTRA_CFLAGS  = -Wall -Wextra -Werror
DEBUG_FLAGS   = -g -Og -DDEBUG
RELEASE_FLAGS = -Os
CXXFLAGS      = $(EXTRA_CFLAGS) $(STD) -MD

# gcov parameters
GCOV_FLAGS    = -fprofile-arcs -ftest-coverage
GCOV_FILES    = $(SRC_OBJ_FILES:.o=.gcno) $(TST_OBJ_FILES:.o=.gcno) $(SRC_OBJ_FILES:.o=.gcda) $(TST_OBJ_FILES:.o=.gcda) 
GCOVR_OUT_FILE = coverage.xml

ifneq (, $(filter $(GCOV_FLAG), $(MAKECMDGOALS)))
CXXFLAGS+=$(GCOV_FLAGS)
endif

# Google Test Relative Directories
GOOGLE_TEST_HOME_DIR   = ../googletest/googletest
GOOGLE_TEST_INCL_DIR   = $(GOOGLE_TEST_HOME_DIR)/include
GOOGLE_TEST_SRC_DIR    = $(GOOGLE_TEST_HOME_DIR)/src
GOOGLE_TEST_SRC_FILES  = gtest_main.cc gtest-all.cc
GOOGLE_TEST_OBJ_FILES  = $(addprefix $(GOOGLE_TEST_OBJ_DIR)/, $(GOOGLE_TEST_SRC_FILES:.cc=.o))
GOOGLE_TEST_OBJ_DIR    = $(GOOGLE_TEST_HOME_DIR)/obj
GOOGLE_TEST_INCL_FLAGS = -I$(GOOGLE_TEST_HOME_DIR) -I$(GOOGLE_TEST_INCL_DIR) -pthread

OUT_DIR = out
SRC_DIR = Exercises
TST_DIR = Tests
BIN_DIR = $(addsuffix /bin, $(OUT_DIR))
OBJ_DIRS = $(addsuffix /obj, $(TST_DIR) $(SRC_DIR))
INCLUDE_FLAGS = -I$(SRC_DIR) -I/usr/include -L/usr/lib

OUT_DIRS = $(GOOGLE_TEST_OBJ_DIR) $(BIN_DIR) $(OBJ_DIRS) $(OUT_DIR)

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
OUT_FILES     = $(SRC_OBJ_FILES) \
	   			$(TST_OBJ_FILES) \
				$(BIN_FILES)
BUILD_LOG     = $(OUT_DIR)/build.log

DEPS  = $(SRC_OBJ_FILES:.o=.d)
DEPS += $(TST_OBJ_FILES:.o=.d)
DEPS += $(GOOGLE_TEST_OBJ_FILES:.o=.d)

vpath % $(GOOGLE_TEST_SRC_DIR) $(SRC_DIR) $(TST_DIR)

includeIfNotExist = $(filter-out $(wildcard $1), $1)

all: __print_banner \
	 __print_settings \
	 __make_dirs \
     __google_test \
	 __make_modules \
	 __make_test_modules \
	 __make_bin_files \

ifneq (, $(filter $(GCOV_FLAG), $(MAKECMDGOALS)))
all: __run_all_files \
	 __gcov \
     __gcovr \

gcov: # Blank gcov rule
	@:

endif

debug: CXXFLAGS+=$(DEBUG_FLAGS)
debug: all

release: CXXFLAGS+=$(RELEASE_FLAGS)
release: clean all

__make_dirs: $(OUT_DIRS)

__google_test: $(GOOGLE_TEST_OBJ_DIR) $(GOOGLE_TEST_OBJ_FILES)

__make_modules: $(SRC_DIR)/obj $(SRC_OBJ_FILES)

__make_test_modules: $(TST_DIR)/obj $(TST_OBJ_FILES)

__make_bin_files: $(BIN_DIR) $(BIN_FILES)

__run_all_files:
	@for test_exe in $(BIN_FILES); do \
		echo Running $$test_exe; \
		$$test_exe > $(BUILD_LOG); \
	done

__gcov:
	@for src_file in $(SRC_FILES); do \
		echo Running gcov for $$src_file; \
		gcov $$src_file --no-output --relative-only --object-directory $(SRC_DIR)/obj > $(BUILD_LOG) 2>&1; \
	done

__gcovr:
	@echo Running gcovr now
	@gcovr -r . --xml --output=$(GCOVR_OUT_FILE)

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
	$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@ > $(BUILD_LOG) 2>&1
	@echo "\n  CXX -c $(notdir $<) -o $(notdir $@)\n      "

$(TST_DIR)/obj/%.o : %.cpp
	@echo "\n  CXX -c $(notdir $<) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@ > $(BUILD_LOG) 2>&1

$(BIN_DIR)/% : $(TST_DIR)/obj/tst_%.o $(SRC_DIR)/obj/%.o
	@echo "\n  CXX $(notdir $^) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) $^ $(GOOGLE_TEST_OBJ_FILES) $(GOOGLE_TEST_INCL_FLAGS) -o $@ > $(BUILD_LOG) 2>&1

clean:
	@echo Cleaning up...
	@rm -rf $(GOOGLE_TEST_OBJ_FILES) $(OUT_FILES) $(DEPS) $(GCOV_FILES) $(BUILD_LOG)

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

.PHONY: Makefile clean __print_banner
.PRECIOUS: $(TST_DIR)/obj/%.o $(SRC_DIR)/obj/%.o
# .SILENT: