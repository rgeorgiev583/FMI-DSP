CC := g++
CFLAGS :=

all: 1 2

debug: CFLAGS += -g
debug: 1 2

1: 1.cpp stack.cpp
	$(CC) $< -o $@ $(CFLAGS)

2: 2.cpp stack.cpp
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f 1 2
