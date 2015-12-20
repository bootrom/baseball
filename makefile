PROG =baseball
SRCS =$(wildcard *.c)
OBJS =$(SRCS:.c=.o)

CFLAGS +=-Wall
LDLIBS +=-lncurses

all: $(PROG)
.PHONY: all

$(PROG): $(OBJS)

clean:
	$(RM) $(PROG)
	$(RM) $(OBJS)
.PHONY: all
