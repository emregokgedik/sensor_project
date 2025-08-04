CXX=g++
CXXFLAGS=-std=c++17 -Iinclude -Wall -Wextra
TARGET=sensor_app
SRC=$(wildcard src/*.cpp)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
