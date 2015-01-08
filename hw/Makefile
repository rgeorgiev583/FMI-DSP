CC := gcc
CFLAGS := -I.
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
BINS := 1 2 3-test

all: $(BINS)

debug: CFLAGS += -g
debug: $(BINS)

define MAKE_EXEC

$1: $$(CFLAGS)
	$$(CC) $$@.o -o $$@ $$(CFLAGS)

endef

$(foreach bin,$(BINS),$(eval $(call MAKE_EXEC,$(bin))))

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)
