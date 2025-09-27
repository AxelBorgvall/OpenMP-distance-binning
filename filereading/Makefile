CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = write_data

all: $(TARGET)

$(TARGET): write_data.c
	$(CC) $(CFLAGS) -o $(TARGET) write_data.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
