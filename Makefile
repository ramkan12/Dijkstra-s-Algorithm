# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
# macOS SDK path (needed on some systems)
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
    SDK_PATH := $(shell xcrun --show-sdk-path 2>/dev/null)
    ifneq ($(SDK_PATH),)
        CXXFLAGS += -isysroot $(SDK_PATH)
        CXXFLAGS += -I$(SDK_PATH)/usr/include/c++/v1
    endif
endif

# Directories
SRC_DIR = src
EXAMPLE_DIR = examples

# Source files
SOURCES = $(SRC_DIR)/Graph.cpp
EXAMPLE = $(EXAMPLE_DIR)/main.cpp

# Output executable
TARGET = graph

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCES) $(EXAMPLE)
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) $(SOURCES) $(EXAMPLE) -o $(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) *.o

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
