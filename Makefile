CC = g++ -g
STDFLAGS = -std=c++11

all: Gobang test

Gobang:
	$(CC) board.cc ai.cc game.cc main.cc -o $@ $(STDFLAGS)

test:
	$(CC) board.cc test.cc -o $@ $(STDFLAGS)

.PHONY: clean

clean:
	rm -rf Gobang test
