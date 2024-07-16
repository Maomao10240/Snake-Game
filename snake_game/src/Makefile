# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# SFML library flags
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = main.cpp board.cpp snake.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = sfml-app

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(SFML_LIBS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
