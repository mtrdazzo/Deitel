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
GCOVR_OUT_FILE = coverage.xml
GCOV_FLAGS     = -fprofile-arcs -ftest-coverage
GCOV_FILES     = $(SRC_OBJ_FILES:.o=.gcno) \
                 $(TST_OBJ_FILES:.o=.gcno) \
                 $(SRC_OBJ_FILES:.o=.gcda) \
                 $(TST_OBJ_FILES:.o=.gcda) \
                 $(GOOGLE_TEST_OBJ_FILES:.o=.gcda) \
                 $(GOOGLE_TEST_OBJ_FILES:.o=.gcno) \
                 $(GCOVR_OUT_FILE)

ifneq (, $(filter $(GCOV_FLAG), $(MAKECMDGOALS)))
CXXFLAGS+=$(GCOV_FLAGS)
endif

# Google Test Relative Directories
GOOGLE_TEST_HOME_DIR   = ../googletest/googletest
GOOGLE_TEST_INCL_DIR   = $(GOOGLE_TEST_HOME_DIR)/include
GOOGLE_TEST_SRC_DIR    = $(GOOGLE_TEST_HOME_DIR)/src
GOOGLE_TEST_SRC_FILES  = gtest_main.cc gtest-all.cc
GOOGLE_TEST_OBJ_FILES  = $(addprefix $(GOOGLE_TEST_OBJ_DIR)/, $(GOOGLE_TEST_SRC_FILES:.cc=.o))
GOOGLE_TEST_OBJ_DIR    = $(GOOGLE_TEST_HOME_DIR)/$(OBJ_DIR)
GOOGLE_TEST_INCL_FLAGS = -I$(GOOGLE_TEST_HOME_DIR) -I$(GOOGLE_TEST_INCL_DIR) -pthread

OBJ_DIR = obj
OUT_DIR = out
SRC_DIR = Exercises
TST_DIR = Tests
BIN_DIR = $(addsuffix /bin, $(OUT_DIR))
OBJ_DIRS = $(addsuffix /$(OBJ_DIR), $(TST_DIR) $(SRC_DIR))
INCLUDE_FLAGS = -I$(SRC_DIR) -I/usr/include -L/usr/lib

OUT_DIRS = $(GOOGLE_TEST_OBJ_DIR) $(BIN_DIR) $(OBJ_DIRS) $(OUT_DIR)

MKDIR_P  = mkdir -p

# List of Source files, exercises, and object files
SRC_FILES     = $(wildcard $(SRC_DIR)/*.cpp)
TST_FILES     = $(wildcard $(TST_DIR)/*.cpp)

EXERCISES     = $(basename $(notdir $(SRC_FILES)))
TESTS         = $(basename $(notdir $(TST_FILES)))
TESTS        := $(subst tst_,,$(TESTS))

SRC_OBJ_FILES = $(addsuffix .o, $(addprefix $(SRC_DIR)/$(OBJ_DIR)/,$(EXERCISES)))
TST_OBJ_FILES = $(addsuffix .o, $(addprefix $(TST_DIR)/$(OBJ_DIR)/,$(basename $(notdir $(TST_FILES)))))
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

# export gid := $(shell echo $(id -u))
# export uid := $(shell echo $(id -g))

debug: __pre_build
	docker-compose run $@
	@docker-compose rm --force > /dev/null 2>&1

build: __print_banner
	@echo "\n  Creating build image..."
	@export gid=$(shell id -u); \
	export uid=$(shell id -g); \
	docker-compose $@
	@echo "done!\n"

__pre_build: __print_banner \
	         __make_dirs \
	         __create_build_log \
	
__build: __print_settings \
		 __google_test \
	     __make_modules \
	     __make_test_modules \
	     __make_bin_files \

ifneq (, $(filter $(GCOV_FLAG), $(MAKECMDGOALS)))
__build: __run_all_files \
         __gcov \
         __gcovr \

gcov: # Blank gcov rule
	@:

endif

__build: __see_build_log

__debug: CXXFLAGS += $(DEBUG_FLAGS)
__debug: __build

release: clean __pre_build
	@docker-compose run release
	@docker-compose rm --force > /dev/null 2>&1

__release: CXXFLAGS += $(RELEASE_FLAGS)
__release: __build

__make_dirs: $(OUT_DIRS)

__google_test: $(GOOGLE_TEST_OBJ_DIR) $(GOOGLE_TEST_OBJ_FILES)

__make_modules: $(SRC_DIR)/$(OBJ_DIR) $(SRC_OBJ_FILES)

__make_test_modules: $(TST_DIR)/$(OBJ_DIR) $(TST_OBJ_FILES)

__make_bin_files: $(BIN_DIR) $(BIN_FILES)

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

$(GOOGLE_TEST_OBJ_DIR)/%.o: %.cc
	@echo -e "\n  CXX $(notdir $<) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(SRC_DIR)/$(OBJ_DIR)/%.o : %.cpp
	@echo -e "\n  CXX -c $(notdir $<) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(TST_DIR)/$(OBJ_DIR)/%.o : %.cpp
	@echo -e "\n  CXX -c $(notdir $<) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) $(INCLUDE_FLAGS) $(GOOGLE_TEST_INCL_FLAGS) -c $< -o $@

$(BIN_DIR)/% : $(TST_DIR)/obj/tst_%.o $(SRC_DIR)/$(OBJ_DIR)/%.o
	@echo -e "\n  CXX $(notdir $^) -o $(notdir $@)\n      "
	@$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) $^ $(GOOGLE_TEST_OBJ_FILES) $(GOOGLE_TEST_INCL_FLAGS) -o $@

__print_settings:
	@echo -e "  CXX=$(CXX)\n"
	@echo -e "  CXXFLAGS=$(CXXFLAGS)\n"

__print_banner:
	@ \
	echo "   ________                __               ____ ";\
  	echo "  / ____/ /_  ____ _____  / /____  _____   / __ \ ";\
 	echo " / /   / __ \/ __  / __ \/ __/ _ \/ ___/  / /_/ /";\
	echo "/ /___/ / / / /_/ / /_/ / /_/  __/ /      \__, /";\
	echo "\____/_/ /_/\__,_/ .___/\__/\___/_/      /____/ ";\
	echo "                /_/                             ";\
	echo "";

__see_build_log:
	@echo -e "\n  See $(BUILD_LOG) for details\n"

clean:
	@echo -n "\n  Cleaning up..."
	@rm -rf $(GOOGLE_TEST_OBJ_FILES) $(OUT_FILES) $(DEPS) $(GCOV_FILES) $(BUILD_LOG)
	@echo "done!\n"

extra-clean: clean
	@rm -Rf  $(GOOGLE_TEST_OBJ_DIR)  $(BIN_DIR) $(OBJ_DIRS) $(OUT_DIR)

.PHONY: Makefile clean __print_banner __gcov __gcovr
.PRECIOUS: $(TST_DIR)/$(OBJ_DIR)/%.o $(SRC_DIR)/$(OBJ_DIR)/%.o
