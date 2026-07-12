CXX = g++
CXXFLAGS = -Wall -Iinclude

SRC = src/main.cpp \
      src/csv_reader.cpp \
      src/table.cpp \
      src/tokenizer.cpp \
	  src/quey.cpp

OUT = build/csvsql

.PHONY: all clean

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $^ -o $(OUT)

clean:
	rm -rf build
