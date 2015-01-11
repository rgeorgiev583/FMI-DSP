CC := g++
CFLAGS :=
LIBS := stack.cpp
BINS := 1 2

ifeq ($(OS),Windows_NT)

BINEXT := .exe

else

BINEXT :=

endif

BINFILES := $(patsubst %,%$(BINEXT),$(BINS))

.PHONY: all debug clean

all: $(BINFILES)

debug: CFLAGS += -g
debug: $(BINFILES)

define MAKE_BINS

$1: $$(patsubst %$$(BINEXT),%.cpp,$1) $$(LIBS)
	$$(CC) $$< -o $$@ $$(CFLAGS)

endef

$(foreach bin,$(BINFILES),$(eval $(call MAKE_BINS,$(bin))))

ifeq ($(OS),Windows_NT)

clean:
	del /f $(BINFILES)

else

clean:
	rm -f $(BINFILES)

endif
