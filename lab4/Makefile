
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -Iinclude


SRCDIR   := src
BINDIR   := .


TARGET   := programa


SOURCES  := $(wildcard $(SRCDIR)/*.cpp)

OBJECTS  := $(SOURCES:%.cpp=%.o)


all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(BINDIR)/$@


$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(SRCDIR)/*.o $(BINDIR)/$(TARGET)

.PHONY: all clean
