CC := g++
CFLAGS := -I.
OBJDIR := obj
DEPS := $(wildcard *.h)
SRCS := $(wildcard *.cpp)
BIN := 3

ifeq ($(OS),Windows_NT)

OBJEXT := .obj
BINEXT := .exe

else

OBJEXT := .o
BINEXT :=

endif

OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.cpp=$(OBJEXT)))
BINFILE := $(BIN)$(BINEXT)

.PHONY: all debug dirs clean

all: dirs $(BINFILE)

debug: CFLAGS += -g
debug: dirs $(BINFILE)

ifeq ($(OS),Windows_NT)

dirs:
	if not exist $(OBJDIR) mkdir $(OBJDIR)

else

dirs:
	test -d $(OBJDIR) || mkdir $(OBJDIR)

endif

$(BINFILE): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJDIR)/%$(OBJEXT): %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

ifeq ($(OS),Windows_NT)

clean:
	del /f $(BINFILE)
	rmdir /s $(OBJDIR)

else

clean:
	rm -rf $(BINFILE) $(OBJDIR)

endif
