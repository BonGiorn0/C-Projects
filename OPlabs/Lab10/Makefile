SRCMODULES = linked.c sort.c table.c
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -g -Wall

%.o: %.c %.h
	gcc $(CFLAGS) -c $< -o $@

main: main.c $(OBJMODULES)
	gcc $(CFLAGS) $^ -o $@

%Test: %Test.c $(OBJMODULES)
	gcc $(CFLAGS) $^ -o $@

-include deps.mk

deps.mk: $(SRCMODULES)
	gcc -MM $^ > $@