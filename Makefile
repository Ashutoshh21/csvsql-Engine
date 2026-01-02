CXX = g++
CXXFLAGS = -Wall -Iinclude
SRC = src/main.cpp src/csv_reader.cpp 
OUT = build/csvsql

all: $(OUT)
$(OUT): $(SRC)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf build

