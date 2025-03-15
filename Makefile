##############################################################################################################
#
# NVMe Tools 2.0 
# ELY 2025
#
##############################################################################################################

TARGET = nvmeTool
VERBOSE = FALSE
RUN = TRUE
SOURCE_NAME = drv
UTIL_NAME = general
TEST_NAME = 

##############################################################################################################

# paths
PROJECT_ROOT := $(realpath ./)
SOURCE_ROOT := $(PROJECT_ROOT)/src
UTIL_ROOT := $(PROJECT_ROOT)/util
TEST_ROOT := $(PROJECT_ROOT)/test

SOURCE_DIRS = $(foreach index, $(SOURCE_NAME), $(addprefix $(SOURCE_ROOT)/, $(index)))
UTIL_DIRS = $(foreach index, $(UTIL_NAME), $(addprefix $(UTIL_ROOT)/, $(index)))
TEST_DIRS = $(foreach index, $(TEST_NAME), $(addprefix $(TEST_ROOT)/, $(index)))

BUILD_DIR = $(PROJECT_ROOT)/build

#includes
INCLUDES = $(foreach index, $(SOURCE_DIRS), $(addprefix -I , $(index)/include))
INCLUDES += $(foreach index, $(TEST_DIRS), $(addprefix -I , $(index)/include))
INCLUDES += $(foreach index, $(UTIL_DIRS), $(addprefix -I , $(index)/include))

# add this list to VPATH, the place make will look for the source files
VPATH = $(SOURCE_DIRS)
VPATH += $(TEST_DIRS)
VPATH += $(UTIL_DIRS)

# sources
SOURCES = $(PROJECT_ROOT)/main.cpp
SOURCES += $(foreach index, $(SOURCE_DIRS), $(wildcard $(index)/*.cpp $(index)/*.c))
SOURCES += $(foreach index, $(TEST_DIRS), $(wildcard $(index)/*.cpp $(index)/*.c))
SOURCES += $(foreach index, $(UTIL_DIRS), $(wildcard $(index)/*.cpp $(index)/*.c))

# defines (if any)
DEFINES =	-D RUN_UNITY_FRAMEWORK=0
DEFINES += 	-D UNITY_OUTPUT_COLOR

##############################################################################################################

# Compiler
CC = g++

# Compile Flags
CFLAGS =	-std=c++11 
CFLAGS += 	-Wall
CFLAGS += 	-Werror
CFLAGS += 	-Wextra
CFLAGS +=	-g

##############################################################################################################

# helpers
RM = rm -rf
RMDIR = rm -rf
MKDIR = mkdir -p
ERRIGNORE = 2>/dev/null
SEP = /

# Remove space after separator
PSEP = $(strip $(SEP))

# Verbosity
ifeq ($(VERBOSE),TRUE)
HIDE =
else
HIDE = @
endif


ifeq ($(RUN),TRUE)
POST_BUILD = $(BUILD_DIR)$(PSEP)$(TARGET)
else
POST_BUILD =
endif

##############################################################################################################

all: clean dir $(TARGET)
	@echo "Done" $@
	$(HIDE)$(POST_BUILD)

$(TARGET):
	@echo "[Building...]"
	$(HIDE)$(CC) $(CFLAGS) $(DEFINES) $(SOURCES) $(INCLUDES) -o $(BUILD_DIR)$(PSEP)$(TARGET)

dir:
	@echo "[Create Build Directory...]"
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(BUILD_DIR)) $(ERRIGNORE)
	@echo "Done" $@

clean:
	@echo "[Cleaning...]"
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(BUILD_DIR)) $(ERRIGNORE)
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	@echo "Done" $@

debug:
	@echo "SOURCES"
	@echo $(SOURCES)
	@echo "INCLUDES"
	@echo $(INCLUDES)	
	@echo "SOURCES DIRS"
	@echo $(SOURCE_DIRS)	
	@echo "Done" $@