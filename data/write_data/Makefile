
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = write_data
SOURCE = write_data.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) -lm

clean:
	del /f $(TARGET)

.PHONY: all clean

