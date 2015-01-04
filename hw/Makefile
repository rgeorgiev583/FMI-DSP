CC=g++
CFLAGS=-I.
OBJ = stack.o 1.cpp

%.o: %.cpp %.h
	$(CC) -c $< -o $@ $(CFLAGS)

1: $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

debug: CFLAGS += -g
debug: 1

clean:
	rm -f *.o 1
