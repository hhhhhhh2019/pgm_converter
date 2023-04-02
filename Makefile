CC = gcc -c -I ./include -Os
LD = gcc


SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)



%.o: %.c
	$(CC) $< -o $@

all: $(OBJECTS)
	$(LD) $^ -o pgm_converter


clean:
	rm *.o pgm_converter -rf
