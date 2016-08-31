ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT =
	endif
endif

CC = gcc
CFLAGS = -msse4.2 -O3 -fomit-frame-pointer -funroll-loops -lm -I .

all: shift-or
	$(CC) $(CFLAGS) -o shift-or$(EXT) shift-or.o main.o

shift-or:
	$(CC) $(CFLAGS) -c shift-or.c main.c

clean:
	$(RM) shift-or.o main.o shift-or$(EXT)
