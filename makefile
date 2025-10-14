# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic
COMPILE = $(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@ 

# Directories
# all directories are dfined of relative path from the location of this makefile
SRC_DIR = src/
OUTPUT_DIR = bin/
HEADERS_DIR = headers/
TEST_DIR = tests/

# Source&Object files
SRC_FILES = $(SRC_DIR)labyrinthe.c $(SRC_DIR)matrix.c $(SRC_DIR)file_handling.c $(SRC_DIR)game_handler.c
OBJ_FILES = $(OUTPUT_DIR)labyrinthe.o $(OUTPUT_DIR)matrix.o $(OUTPUT_DIR)file_handling.o $(OUTPUT_DIR)game_handler.o

MAIN_SRC= $(SRC_DIR)main.c
MAIN_OBJ= $(OUTPUT_DIR)main.o

TARGET=labyrinthe_game

# Test files
TEST_BIN = bin/test_lab
TEST_SRC = tests/mainTest.c
MINUNIT_DIR = minunit/

.PHONY : all clean test

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(OBJ_FILES)
	$(CC) $^ -o $@
$(MAIN_OBJ) : $(MAIN_SRC)
	$(COMPILE)

# rule means : any .o file is compiled with its .c file
$(OUTPUT_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(COMPILE)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(SRC_FILES)
	$(CC) $^ -I$(HEADERS_DIR) -I$(MINUNIT_DIR) -o $@

clean:
	@rm $(OUTPUT_DIR)*
	@rm $(TARGET)
