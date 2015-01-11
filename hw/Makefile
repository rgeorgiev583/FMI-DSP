CC := g++
CFLAGS := -I. -MMD -MP
LD := g++
LDFLAGS := -I.
SRCS_ALL := $(wildcard *.cpp)
SRCS_EXCLUDE := exprtree.cpp
SRCS := $(filter-out $(SRCS_EXCLUDE),$(SRCS_ALL))
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
BINS := 1 2 3-test 4
OBJS_BIN := $(foreach bin,$(BINS),$(bin).o)
OBJS_LIB := $(filter-out $(OBJS_BIN),$(OBJS))

all: $(BINS)

debug: CFLAGS += -g
debug: $(BINS)

define MAKE_EXEC

$1: $$(OBJS_LIB)
	$$(LD) $$^ -o $$@ $$(LDFLAGS)

endef

$(foreach bin,$(BINS),$(eval $(call MAKE_EXEC,$(bin))))

%.o: %.cpp %.h
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS) $(DEPS)

-include $(DEPS)
