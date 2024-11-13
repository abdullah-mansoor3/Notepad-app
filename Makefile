# Compiler and flags
CXX = g++
CXXFLAGS = -Iheaders -Wall -std=c++11 -g

# Linker flags (add -lncurses to link the ncurses library)
LDFLAGS = -lncurses

# Directories
SRC_DIR = source
HEADER_DIR = headers

# Output executable
TARGET = notepad

# Source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Default target
all: $(TARGET)

# Link all object files into the final executable with ncurses
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS)

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ_FILES) $(TARGET) notepad_app notepad.txt
