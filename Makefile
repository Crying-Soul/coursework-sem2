CC=g++
CXXFLAGS=-Wall -Wextra -Werror -pedantic -std=c++11 -Wshadow -Wformat=2 -Wconversion -Weffc++ -Wfloat-equal -fstack-protector-strong -fPIE -pie -O2
SRC_DIR=.
BUILD_DIR=.
EXECUTABLE=coursework


SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)
