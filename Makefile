
CC = gcc
CFLAGS = -Wall -Wextra -O2 -fopenmp -Iinclude
LDFLAGS = -fopenmp

SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/distances.exe

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Link final executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if missing (Windows cmd.exe style)
$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(BIN_DIR):
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Clean build artifacts
clean:
	-del /Q $(OBJ_DIR)\*.o 2>nul || true
	-rmdir /S /Q $(OBJ_DIR) 2>nul || true
	-del /Q $(BIN_DIR)\*.exe 2>nul || true

