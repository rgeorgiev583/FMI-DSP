CC = g++
CFLAGS = -I.
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = 1 2

%.o: %.cpp %.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

debug: CFLAGS += -g
debug: $(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
