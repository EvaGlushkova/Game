CXX = g++
CXXFLAGS = -std=c++14 -I./src -pthread
GTEST_LIBS = -lgtest -lgtest_main

SRC_FILES = $(shell find src/ -name "*.cpp")
TEST_FILE = tests/test-game.cpp
TARGET = test-game

all: $(TARGET)

$(TARGET): $(TEST_FILE) $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(TEST_FILE) $(SRC_FILES) $(GTEST_LIBS) -o $(TARGET)

test: $(TARGET)
	./$(TARGET)


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f test-results.xml
	rm -rf docs/doxygen/

.PHONY: all test test-xml test-list format check-format docs run clean check