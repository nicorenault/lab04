# Makefile (Linux)

# Compilador y flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -Iinclude

# Directorios
SRCDIR   := src
BINDIR   := .

# Ejecutable resultante
TARGET   := programa

# Detecta todos los .cpp en src/
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
# Los .o correspondientes
OBJECTS  := $(SOURCES:%.cpp=%.o)

# Objetivo por defecto
all: $(TARGET)

# Linkeo del ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(BINDIR)/$@

# Regla genérica para compilar .cpp → .o
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Borrar binario y objetos
clean:
	rm -f $(SRCDIR)/*.o $(BINDIR)/$(TARGET)

.PHONY: all clean