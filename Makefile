CC = gcc
SRC = $(wildcard src/*.c)
EXE = $(patsubst src/%.c, %.exe, $(SRC))
BUILT_EXE = $(wildcard *.exe)

.PHONY: all clean

all: $(EXE)
%.exe: src/%.c
	$(CC) $^ -o $@

%: src/%.c
	$(CC) $^ -o $@

clean:
	del $(BUILT_EXE)