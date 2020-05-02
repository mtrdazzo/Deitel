# Compilation Flags
CXX          := g++
STD          := -std=c++14

# Determine build flags
DEBUG_FLAG   := debug
RELEASE_FLAG := release
GCOV_FLAG    := gcov
CLEAN_FLAG   := clean
EXTRA_CLEAN_FLAG := extra-clean
ALL_FLAGS    := $(DEBUG_FLAG) $(RELEASE_FLAG) $(GCOV_FLAG) $(CLEAN_FLAG) $(EXTRA_CLEAN_FLAG)

# Compiler flags
EXTRA_CFLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS  := -g -Og -DDEBUG
RELEASE_FLAGS:= -Os
CXXFLAGS     := $(EXTRA_CFLAGS) $(STD) -MD

ifeq ($(RELEASE_FLAG)$(DEBUG_FLAG), $(filter $(RELEASE_FLAG), $(MAKECMDGOALS))$(filter $(DEBUG_FLAG), $(MAKECMDGOALS)))
$(error Pick either $(RELEASE_FLAG) or $(DEBUG_FLAG) not both!)
endif
ifeq ($(RELEASE_FLAG), $(filter $(RELEASE_FLAG), $(MAKECMDGOALS)))
CXXFLAGS += $(RELEASE_FLAGS)
else
CXXFLAGS += $(DEBUG_FLAGS)
endif

# gcov parameters
GCOVR_OUT_FILE = coverage.xml
GCOV_FLAGS     = -fprofile-arcs -ftest-coverage
GCOV_FILES    := $(SRC_OBJ_FILES:.o=.gcno) \
                 $(TST_OBJ_FILES:.o=.gcno) \
                 $(SRC_OBJ_FILES:.o=.gcda) \
                 $(TST_OBJ_FILES:.o=.gcda) \
                 $(GOOGLE_TEST_OBJ_FILES:.o=.gcda) \
                 $(GOOGLE_TEST_OBJ_FILES:.o=.gcno) \
                 $(GCOVR_OUT_FILE)

ifneq (, $(filter $(GCOV_FLAG), $(MAKECMDGOALS)))
$(info in here!)
CXXFLAGS+=$(GCOV_FLAGS)
endif

# Google Test Relative Directories
GOOGLE_TEST_HOME_DIR    = ../googletest/googletest
GOOGLE_TEST_INCL_DIR   := $(GOOGLE_TEST_HOME_DIR)/include
GOOGLE_TEST_SRC_DIR    := $(GOOGLE_TEST_HOME_DIR)/src
GOOGLE_TEST_SRC_FILES   = gtest_main.cc gtest-all.cc
GOOGLE_TEST_INCL_FLAGS := -I$(GOOGLE_TEST_HOME_DIR) -I$(GOOGLE_TEST_INCL_DIR) -pthread

ifeq ($(RELEASE_FLAG), $(filter $(RELEASE_FLAG), $(MAKECMDGOALS)))
OUT_DIR       = out/$(RELEASE_FLAG)
else
OUT_DIR       = out/$(DEBUG_FLAG)
endif

OBJ_DIR       = $(OUT_DIR)/obj
SRC_DIR       = Exercises
TST_DIR       = Tests
FIG_DIR       = Figures
BIN_DIR      := $(OUT_DIR)/bin
INCLUDE_FLAGS = -I$(SRC_DIR) -I/usr/include -L/usr/lib

OUT_DIRS = $(OUT_DIR) \
           $(BIN_DIR) \
           $(OBJ_DIR)

MKDIR_P  = mkdir -p

# List of Source files, exercises, and object files
SRC_FILES     := $(wildcard $(SRC_DIR)/*.cpp)
TST_FILES     := $(wildcard $(TST_DIR)/*.cpp)
FIG_FILES     := $(wildcard $(FIG_DIR)/*.cpp)

EXERCISES     := $(basename $(notdir $(SRC_FILES)))
TESTS         := $(subst tst_,,$(basename $(notdir $(TST_FILES))))

SRC_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:.cpp=.o)))
TST_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(TST_FILES:.cpp=.o)))
FIG_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(FIG_FILES:.cpp=.o)))
GGL_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(GOOGLE_TEST_SRC_FILES:.cc=.o)))
OBJ_FILES     := $(SRC_OBJ_FILES) $(TST_OBJ_FILES) $(GGL_OBJ_FILES) $(FIG_OBJ_FILES)
BIN_FILES     := $(addprefix $(BIN_DIR)/,$(TESTS))
BUILD_LOG     := $(OUT_DIR)/build.log

DEPS  = $(OBJ_FILES:.o=.d)

vpath % $(GOOGLE_TEST_SRC_DIR) $(SRC_DIR) $(TST_DIR) $(FIG_DIR)

ifeq (, $(filter $(CLEAN_FLAG), $(MAKECMDGOALS))$(filter $(EXTRA_CLEAN_FLAG), $(MAKECMDGOALS)))
$(DEBUG_FLAG) $(RELEASE_FLAG): $(OUT_DIRS) $(OBJ_FILES)
	@echo $^
else
$(DEBUG_FLAG) $(RELEASE_FLAG):
	@:
endif

__create_build_log:
	@if [ -f "$(BUILD_LOG)" ]; then \
		rm $(BUILD_LOG); \
	fi
	@touch $(BUILD_LOG)

__run_all_files:
	@echo -en "\n  Running all exercises..."
	@for test_exe in $(BIN_FILES); do \
		$$test_exe >> $(BUILD_LOG) 2>&1; \
	done
	@echo -e "done!\n"

__gcov:
	@echo -en "\n  Running gcov..."
	@for src_file in $(SRC_FILES); do \
		gcov $$src_file --no-output --demangled-names --relative-only --object-directory $(SRC_DIR)/obj >> $(BUILD_LOG) 2>&1; \
	done
	@echo -e "done!\n"

__gcovr:
	@echo -en "\n  Creating test coverage report: $(GCOVR_OUT_FILE)..."
	@gcovr -r . --xml --delete --exclude=Tests --exclude=../googletest --sort-percentage --output=$(GCOVR_OUT_FILE) >> $(BUILD_LOG) 2>&1
	@echo -e "done!\n"

$(OUT_DIRS):
	@echo "\n  > Initialized directory $@\n"
	@$(MKDIR_P) $@

$(OBJ_DIR)/%.o: %.cc
	@echo -en "\n  CXX $(notdir $<) -o $(notdir $@)\n"
	@$(CXX) $(CXXFLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(OBJ_DIR)/tst_%.o : %.cpp $(GGL_OBJ_FILES)
	@echo -en "\n  CXX -c $(notdir $<) -o $(notdir $@)\n"
	@$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : %.cpp
	@echo -en "\n  CXX -c $(notdir $<) -o $(notdir $@)\n"
	@$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(BIN_DIR)/% : $(OBJ_DIR)/tst_%.o $(OBJ_DIR)/%.o
	@echo -e "\n  CXX $(notdir $^) -o $(notdir $@)\n"
	@$(CXX) $(CXXFLAGS) $^ $(GOOGLE_TEST_OBJ_FILES) $(GOOGLE_TEST_INCL_FLAGS) -o $@

__print_settings:
	$(info $(BANNER))
	@echo -e "  CXX=$(CXX)\n"
	@echo -e "  CXXFLAGS=$(CXXFLAGS)\n"

define BANNER

   ____ _                 _              _  ___  
  / ___| |__   __ _ _ __ | |_ ___ _ __  / |/ _ \ 
 | |   | '_ \ / _` | '_ \| __/ _ \ '__| | | | | |
 | |___| | | | (_| | |_) | ||  __/ |    | | |_| |
  \____|_| |_|\__,_| .__/ \__\___|_|    |_|\___/ 
                   |_|                           

endef

__see_build_log:
	@echo -e "\n  See $(BUILD_LOG) for details\n"

$(CLEAN_FLAG):
	@echo -n "\n  Cleaning up..."
	@rm -f $(OBJ_FILES) $(BIN_FILES) $(DEPS)
	@echo "done!\n"

$(EXTRA_CLEAN_FLAG): $(CLEAN_FLAG)
	@rm -Rf  $(OUT_DIR)

.PHONY: Makefile clean __print_banner __gcov __gcovr
.PRECIOUS: $(TST_DIR)/$(OBJ_DIR)/%.o $(SRC_DIR)/$(OBJ_DIR)/%.o
