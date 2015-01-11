CC := g++
CFLAGS :=
LIBS := stack.cpp
BINS := 1 2

all: $(BINS)

debug: CFLAGS += -g
debug: $(BINS)

ifeq ($(OS),Windows_NT)
	BIN_EXT := .exe
else
	BIN_EXT :=
endif

define MAKE_BINS

$1: $1.cpp $$(LIBS)
	$$(CC) $$< -o $$@$$(BIN_EXT) $$(CFLAGS)

endef

$(foreach bin,$(BINS),$(eval $(call MAKE_BINS,$(bin))))

clean:
	rm -f $(BINS)
