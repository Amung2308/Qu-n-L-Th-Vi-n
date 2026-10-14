CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
TARGET = bin/QuanLyThuVien

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin:
	mkdir -p bin

obj:
	mkdir -p obj

clean:
	rm -rf obj bin

run: all
	./$(TARGET)

.PHONY: all clean run
