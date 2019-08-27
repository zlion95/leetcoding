CC := g++

CFLAGS := 

SRC := $(wildcard *.cpp)
targets := $(patsubst %.cpp,%.out,$(SRC))

all: $(targets)

%.out: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(targets)
