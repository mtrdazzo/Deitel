# Compilation Flags
CXX           = g++
STD           = -std=c++14

# Determine build flags
DEBUG_FLAG   = debug
RELEASE_FLAG = release
GCOV_FLAG    = gcov
ALL_FLAGS   := $(DEBUG_FLAG) $(RELEASE_FLAG) $(GCOV_FLAG)

# Compiler flags
EXTRA_CFLAGS  = -Wall -Wextra -Werror
DEBUG_FLAGS   = -g -Og -DDEBUG
RELEASE_FLAGS = -Os
CXXFLAGS     := $(EXTRA_CFLAGS) $(STD) -MD

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
CXXFLAGS+=$(GCOV_FLAGS)
endif

# Google Test Relative Directories
GOOGLE_TEST_HOME_DIR    = googletest/googletest
GOOGLE_TEST_INCL_DIR   := $(GOOGLE_TEST_HOME_DIR)/include
GOOGLE_TEST_SRC_DIR    := $(GOOGLE_TEST_HOME_DIR)/src
GOOGLE_TEST_SRC_FILES   = gtest_main.cc gtest-all.cc
GOOGLE_TEST_OBJ_FILES   = $(addprefix $(GOOGLE_TEST_OBJ_DIR)/, $(GOOGLE_TEST_SRC_FILES:.cc=.o))
GOOGLE_TEST_OBJ_DIR     = $(GOOGLE_TEST_HOME_DIR)/$(OBJ_DIR)
GOOGLE_TEST_INCL_FLAGS := -I$(GOOGLE_TEST_HOME_DIR) -I$(GOOGLE_TEST_INCL_DIR) -pthread

OBJ_DIR       = obj
OUT_DIR       = out
SRC_DIR       = Exercises
TST_DIR       = Tests
BIN_DIR      := $(addsuffix /bin, $(OUT_DIR))
OBJ_DIRS     := $(addsuffix /$(OBJ_DIR), $(TST_DIR) $(SRC_DIR))
INCLUDE_FLAGS = -I$(SRC_DIR) -I/usr/include -L/usr/lib

OUT_DIRS = $(GOOGLE_TEST_OBJ_DIR) \
           $(BIN_DIR) \
           $(OBJ_DIRS) \
           $(OUT_DIR)

MKDIR_P  = mkdir -p

jenkins:
	@docker-compose --file docker-jenkins.yml up --detach --remove-orphans

stop-jenkins:
	@if docker ps -a | grep jenkins-server; then \
		docker stop jenkins-server; \
		docker rm --force jenkins-server; \
	fi
