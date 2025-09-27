CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = compute_distances

all: $(TARGET)

$(TARGET): compute_distances.c
	$(CC) $(CFLAGS) -o $(TARGET) compute_distances.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
