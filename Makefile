CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -I/opt/homebrew/opt/mysql/include -Wall -Wextra
LDFLAGS = -L/opt/homebrew/opt/mysql/lib -lmysqlclient

TARGET = sensor_app
SRC = $(wildcard src/*.cpp)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)
