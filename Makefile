CC = gcc
CFLAGS = -I include
LDFLAGS = -L lib -lraylib -lgdi32 -lwinmm

TARGET = game
SRC = solitaire.c

all:
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe

