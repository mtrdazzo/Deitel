# Compilation Flags
CXX := $(shell which g++)
STD := -std=c++14

CHAPTER := $(notdir $(CURDIR))

# Compiler flags
EXTRA_CFLAGS  := -Wall -Wextra
DEBUG_FLAGS   := -g -Og -DDEBUG
RELEASE_FLAGS := -Os -Werror
CXXFLAGS      := $(EXTRA_CFLAGS) $(STD) -MD

# Determine build flags
DEBUG_FLAG       := debug
RELEASE_FLAG     := release
GCOV_FLAG        := gcov
CLEAN_FLAG       := clean
EXTRA_CLEAN_FLAG := extra-clean
ALL_FLAGS        := $(DEBUG_FLAG) $(RELEASE_FLAG) $(GCOV_FLAG) $(CLEAN_FLAG) $(EXTRA_CLEAN_FLAG)

# Print parameters
BIG_BANNER   = "   ///////////////////////////////////////////////////\n  ///\n ///   $(1)\n //\n /\n"
SMALL_BANNER = "   ///////////////////////////////////////////////////\n  /\n /     $(1)\n/\n"
CURR_DATE   := $(shell date)
START_TIME  := $(shell date +'%s' )
CURRENT_TIME = $(shell date +'%s' )
DELTA_TIME   = $(shell echo $(CURRENT_TIME) - $(START_TIME) | bc )
ELAPSED_TIME = $(shell printf %i:%02i $(shell expr $(DELTA_TIME) / 60 ) $(shell expr $(DELTA_TIME) % 60 ) )

# Find possible unknown flag
ifneq (, $(filter-out $(ALL_FLAGS), $(MAKECMDGOALS)))
$(error Unknown option: $(filter-out $(ALL_FLAGS), $(MAKECMDGOALS)))
endif

# Resolve release or debug build
ifeq ($(RELEASE_FLAG)$(DEBUG_FLAG), $(filter $(RELEASE_FLAG), $(MAKECMDGOALS))$(filter $(DEBUG_FLAG), $(MAKECMDGOALS)))
$(error Pick either $(RELEASE_FLAG) or $(DEBUG_FLAG) not both!)
endif
ifeq ($(RELEASE_FLAG), $(filter $(RELEASE_FLAG), $(MAKECMDGOALS)))
CXXFLAGS += $(RELEASE_FLAGS)
else
CXXFLAGS += $(DEBUG_FLAGS)
endif

# gcov parameters
ifneq (, $(filter $(GCOV_FLAG), $(MAKECMDGOALS)))
GCOVR_OUT_FILE = coverage.html
GCOV_FLAGS     = -fprofile-arcs -ftest-coverage
GCOV_FILES    := $(SRC_OBJ_FILES:.o=.gcno) \
                 $(TST_OBJ_FILES:.o=.gcno) \
                 $(SRC_OBJ_FILES:.o=.gcda) \
                 $(TST_OBJ_FILES:.o=.gcda) \
                 $(GOOGLE_TEST_OBJ_FILES:.o=.gcda) \
                 $(GOOGLE_TEST_OBJ_FILES:.o=.gcno) \
                 $(GCOVR_OUT_FILE)

CXXFLAGS+=$(GCOV_FLAGS)
endif

# Google Test Relative Directories
GOOGLE_TEST_HOME_DIR    = ../googletest/googletest
GOOGLE_TEST_INCL_DIR   := $(GOOGLE_TEST_HOME_DIR)/include
GOOGLE_TEST_EXR_DIR    := $(GOOGLE_TEST_HOME_DIR)/src
GOOGLE_TEST_EXR_FILES   = gtest_main.cc gtest-all.cc
GOOGLE_TEST_INCL_FLAGS := -I$(GOOGLE_TEST_HOME_DIR) -I$(GOOGLE_TEST_INCL_DIR) -pthread

ifeq ($(RELEASE_FLAG), $(filter $(RELEASE_FLAG), $(MAKECMDGOALS)))
OUT_DIR       = out/$(RELEASE_FLAG)
else
OUT_DIR       = out/$(DEBUG_FLAG)
endif

OBJ_DIR       = $(OUT_DIR)/obj
EXR_DIR       = Exercises
TST_DIR       = Tests
FIG_DIR       = Figures
BIN_DIR      := $(OUT_DIR)/bin
INCLUDE_FLAGS = -I$(EXR_DIR) -I/usr/include -L/usr/lib

OUT_DIRS = $(OUT_DIR) \
           $(BIN_DIR) \
           $(OBJ_DIR)

MKDIR_P  = mkdir -p

# Source files from Exercises, Tests, and Figures
EXR_FILES     := $(wildcard $(EXR_DIR)/*.cpp)
TST_FILES     := $(wildcard $(TST_DIR)/*.cpp)
FIG_FILES     := $(wildcard $(FIG_DIR)/*.cpp)
TESTS         := $(subst tst_,,$(basename $(notdir $(TST_FILES))))

SRC_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(EXR_FILES:.cpp=.o)))
TST_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(TST_FILES:.cpp=.o)))
FIG_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(FIG_FILES:.cpp=.o)))
GGL_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(GOOGLE_TEST_EXR_FILES:.cc=.o)))
OBJ_FILES     := $(SRC_OBJ_FILES) $(TST_OBJ_FILES) $(GGL_OBJ_FILES) $(FIG_OBJ_FILES)
BIN_FILES     := $(addprefix $(BIN_DIR)/,$(TESTS)) $(addprefix $(BIN_DIR)/, $(notdir $(FIG_FILES:.cpp=.fig)))

BUILD_LOG     := $(OUT_DIR)/build.log

DEPS  = $(OBJ_FILES:.o=.d)

vpath % $(GOOGLE_TEST_EXR_DIR) $(EXR_DIR) $(TST_DIR) $(FIG_DIR)

ifeq (, $(filter $(CLEAN_FLAG), $(MAKECMDGOALS))$(filter $(EXTRA_CLEAN_FLAG), $(MAKECMDGOALS)))
$(DEBUG_FLAG) $(RELEASE_FLAG): __print_settings $(OUT_DIRS) $(BIN_FILES)
	@echo $(call BIG_BANNER, $(CHAPTER) build done!)
	@echo "        Elapsed Time: $(ELAPSED_TIME)\n"
else
$(DEBUG_FLAG) $(RELEASE_FLAG):
	@:
endif

$(GCOV_FLAG): __run_all_files __gcov __gcovr

__create_build_log:
	@if [ -f "$(BUILD_LOG)" ]; then \
		rm $(BUILD_LOG); \
	fi
	@touch $(BUILD_LOG)

__run_all_files:
	@echo -n "\n  Running all exercises..."
	@for test_exe in $(addprefix $(BIN_DIR)/,$(TESTS)); do \
		echo "\n$$test_exe" >> $(BUILD_LOG); \
		$$test_exe >> $(BUILD_LOG) 2>&1; \
	done
	@echo "done!"

__gcov:
	@echo -n "\n  Running gcov..."
	@for src_file in $(EXR_FILES); do \
		gcov $$src_file --no-output --demangled-names --relative-only --object-directory $(OBJ_DIR) >> $(BUILD_LOG) 2>&1; \
	done
	@echo "done!"

__gcovr:
	@echo -n "\n  Creating test coverage report: $(GCOVR_OUT_FILE)..."
	@gcovr -r . --html --html-details --delete --exclude=$(FIG_DIR) --exclude=$(TST_DIR) --exclude=$(GOOGLE_TEST_HOME_DIR) --sort-percentage --output=$(GCOVR_OUT_FILE) >> $(BUILD_LOG) 2>&1
	@echo "done!\n"

$(OUT_DIRS):
	@echo "\n  > Initialized directory $@\n"
	@$(MKDIR_P) $@

$(OBJ_DIR)/%.o: %.cc
	@echo $(call SMALL_BANNER, Compiling $(notdir $<)...)
	@$(CXX) $(CXXFLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : %.cpp
	@echo $(call SMALL_BANNER,Compiling $(notdir $<)...)
	@$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(BIN_DIR)/%.fig : $(OBJ_DIR)/%.o $(MAKEFILE_LIST)
	@echo $(call SMALL_BANNER, Linking $(notdir $@)...)
	@$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/% : $(OBJ_DIR)/tst_%.o $(OBJ_DIR)/%.o $(GGL_OBJ_FILES) $(MAKEFILE_LIST)
	@echo $(call SMALL_BANNER, Linking $(notdir $@)...)
	@$(CXX) $(CXXFLAGS) $(filter-out $(MAKEFILE_LIST), $^) $(GOOGLE_TEST_INCL_FLAGS) -o $@

$(MAKEFILE_LIST):
	@:

__print_settings:
	$(info $(BANNER))
	@echo "Using CXX...\n\n\t$(CXX)\n"
	@echo "Using CXXFLAGS...\n"
	@for flag in $(CXXFLAGS); do \
		echo "\t$$flag" ; \
	done
	@echo "\nFigures...\n"
	@for test in $(notdir $(FIG_FILES)); do \
		echo "\t$$test" ; \
	done
	@echo "\nExercises...\n"
	@for ex in $(notdir $(EXR_FILES)); do \
		echo "\t$$ex" ; \
	done
	@echo "\nTests...\n"
	@for test in $(notdir $(TST_FILES)); do \
		echo "\t$$test" ; \
	done
	@echo

define BANNER

   ____ _                 _              _  ___  
  / ___| |__   __ _ _ __ | |_ ___ _ __  / |/ _ \ 
 | |   | '_ \ / _` | '_ \| __/ _ \ '__| | | | | |
 | |___| | | | (_| | |_) | ||  __/ |    | | |_| |
  \____|_| |_|\__,_| .__/ \__\___|_|    |_|\___/ 
                   |_|                           

          $(CURR_DATE)

endef

__see_build_log:
	@echo -e "\n  See $(BUILD_LOG) for details\n"

$(CLEAN_FLAG):
	@echo 
	@echo $(call BIG_BANNER, Cleaning up $(CHAPTER)...)
	@rm -f $(OBJ_FILES) $(BIN_FILES) $(DEPS) $(BUILD_LOG)

$(EXTRA_CLEAN_FLAG): $(CLEAN_FLAG)
	@rm -Rf  $(OUT_DIR)

.PHONY: clean __print_banner __gcov __gcovr
.PRECIOUS: $(OBJ_FILES)
