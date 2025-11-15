# Compiler and flags
CC       = gcc
CFLAGS   = -Wall -Wextra -pedantic -I$(HEADERS_DIR)
COMPILE  = $(CC) $(CFLAGS) -c $< -o $@
RM       = rm
RM_DIR   = rm -rf
MAKE_DIR = mkdir -p

# Directories
SRC_DIR     = src/files/
OUTPUT_DIR  = bin/
HEADERS_DIR = headers/
TEST_DIR    = tests/

# Source & Object files
SRC_FILES   = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)%.c=$(OUTPUT_DIR)%.o)

MAIN_SRC    = src/main.c
MAIN_OBJ    = $(OUTPUT_DIR)main.o
TARGET      = labyrinthe_game

# Test files
TEST_BIN    = $(OUTPUT_DIR)test_lab
TEST_SRC    = $(TEST_DIR)mainTest.c
MINUNIT_DIR = minunit/

.PHONY: all clean test

# Default build target
all: $(OUTPUT_DIR) $(TARGET)

# Create the output directory
$(OUTPUT_DIR):
	$(MAKE_DIR) $@

# Compile the main executable
$(TARGET): $(MAIN_OBJ) $(OBJ_FILES)
	$(CC) $^ -o $@

# Compile the main object file
$(MAIN_OBJ): $(MAIN_SRC)
	$(COMPILE)

# Rule for compiling object files
$(OUTPUT_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILE)

# Test target
test: $(OUTPUT_DIR) $(TEST_BIN)
	./$(TEST_BIN)

# Compile the test suite
$(TEST_BIN): $(TEST_SRC) $(SRC_FILES)
	$(CC) $^ -I$(HEADERS_DIR) -I$(MINUNIT_DIR) -o $@

# Clean compiled files
clean:
	$(RM_DIR) $(OUTPUT_DIR)
	$(RM) $(TARGET)