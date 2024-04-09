CC := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++14 -Wshadow -Wformat=2 -Wconversion -Weffc++ -Wfloat-equal -fstack-protector-strong -fPIE -pie
LIBS := -lcurl
SRC_DIR := src
INCDIR := include
OBJDIR := obj


SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE := coursework

DOXYGEN_CONFIG := Doxyfile

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $^ -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR) $(EXECUTABLE)

docs:
	@doxygen $(DOXYGEN_CONFIG)  # Note the tab character before doxygen

.PHONY: all clean docs
