CC := g++

CFLAGS := -std=c++11

SRC := $(wildcard *.cpp)
targets := $(patsubst %.cpp,%.out,$(SRC))

all: $(targets)

%.out: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(targets)
