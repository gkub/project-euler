CXX = g++
CC = gcc
CXXFLAGS = -Wall -std=c++11
CFLAGS = -Wall

# Find all source files
CPP_SOURCES = $(wildcard problem*.cpp)
C_SOURCES = $(wildcard problem*.c)

# Generate executable names by removing the extension
CPP_TARGETS = $(CPP_SOURCES:.cpp=)
C_TARGETS = $(C_SOURCES:.c=)

# Combined list of all targets
ALL_TARGETS = $(CPP_TARGETS) $(C_TARGETS)

# Default target
all: $(ALL_TARGETS)

# Rule for C++ files
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Rule for C files
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean target
clean:
	rm -f $(ALL_TARGETS)

.PHONY: all clean 