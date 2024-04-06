CC := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++14 -Wshadow -Wformat=2 -Wconversion -Weffc++ -Wfloat-equal -fstack-protector-strong -fPIE -pie
SRC_DIR := src
INCDIR := include
OBJDIR := obj
LANGUAGE := -DRU

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE := coursework

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(LANGUAGE) $^ -o $@

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CXXFLAGS) $(LANGUAGE) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR) $(EXECUTABLE)

.PHONY: all clean
