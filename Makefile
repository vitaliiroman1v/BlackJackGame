# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# List of source files
SOURCES = main.cpp card.cpp

# Object files
OBJECTS = $(SOURCES:%.cpp=%.o)

# Executable name
EXECUTABLE = blackJack

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o blackJack
