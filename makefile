CC=g++
CFLAGS=-I.
DEPS = WordleBoard.h
OBJ = wordle.cpp WordleBoard.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

wordle: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o wordle
