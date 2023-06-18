# Compiler options
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Directories
OBJDIR = obj

# SFML options
SFML_PATH = /path/to/sfml
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = gamefile

# Header file dependencies
DEPS = $(wildcard *.h)

# Rule to create the obj directory (if it doesn't exist)
$(shell mkdir -p $(OBJDIR))

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -L$(SFML_PATH)/lib $(SFML_LIBS) -o $@

# Rule to compile the source files
$(OBJDIR)/%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I$(SFML_PATH)/include -c $< -o $@

# Rule to clean the build
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
