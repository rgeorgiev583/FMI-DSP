CC := g++
CFLAGS := -I.
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
BINS := 1 2

all: $(BINS)

debug: CFLAGS += -g
debug: $(BINS)

define EXEC

$(1): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

endef

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)
