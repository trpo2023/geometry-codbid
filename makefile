CFLAGS = -Wall -Wextra -Werror
INCLUDE_PATH = /src/libgeometry/
PATH = /src/geometry/

main: main.o parser.o
	$(CC) $(CFLAGS) -o $@ $^

main.c: main.o
	$(CC) -c $(CFLAGS) -I$(PATH) -o $@ $<

parser.o: parser.c
	$(CC) -c $(CFLAGS) -I$(INCLUDE_PATH) -o $@ $<
