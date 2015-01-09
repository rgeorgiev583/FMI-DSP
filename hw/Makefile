CC := g++
BINS := 1 2 3-test

all: $(BINS)

debug: CFLAGS += -g
debug: $(BINS)

define MAKE_EXEC

$1: $1.cpp
	$$(CC) $$< -o $$@ $$(CFLAGS)

endef

$(foreach bin,$(BINS),$(eval $(call MAKE_EXEC,$(bin))))

clean:
	rm -f $(BINS)
