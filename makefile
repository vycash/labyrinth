# ----- Variables de Compilation et Flags
CC       = gcc
CFLAGS   = -Wall -Wextra -pedantic -I$(HEADERS_DIR)
COMPILE  = $(CC) $(CFLAGS) -c $< -o $@
RM       = rm
RM_DIR   = rm -rf
MAKE_DIR = mkdir -p
DOXYFILE = Doxyfile
DOXYGEN  = doxygen

# ----- Répértoires 
SRC_DIR     = src/files/
OUTPUT_DIR  = bin/
HEADERS_DIR = headers/
TEST_DIR    = tests/
DOC_DIR	    = doc/
MINUNIT_DIR = minunit/


# ----- Fichiers Source
SRC_FILES   = $(wildcard $(SRC_DIR)*.c)
MAIN_SRC    = src/main.c

# ----- Fichiers Objet
OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)%.c=$(OUTPUT_DIR)%.o)
MAIN_OBJ    = $(OUTPUT_DIR)main.o

# ----- fichiers test
TEST_SRC    = $(TEST_DIR)mainTest.c
TEST_BIN    = $(OUTPUT_DIR)test_lab

# -----Target principal
TARGET      = labyrinthe_game


# ================ Règles principales ============

.PHONY: all clean test doc

# règle par défaut
all: $(OUTPUT_DIR) $(TARGET)

# Compile l'executable
$(TARGET): $(MAIN_OBJ) $(OBJ_FILES)
	$(CC) $^ -o $@

# Compile le main
$(MAIN_OBJ): $(MAIN_SRC)
	$(COMPILE)

# règle pour compiler tous les fichiers objet
$(OUTPUT_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILE)

# ================ Règles pour créer les répértoires ============

$(OUTPUT_DIR):
	$(MAKE_DIR) $@

$(DOC_DIR):
	$(MAKE_DIR) $@

# =============== Règles pour créer et executer les test =======

test: $(OUTPUT_DIR) $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(SRC_FILES)
	$(CC) $^ -I$(HEADERS_DIR) -I$(MINUNIT_DIR) -o $@


# =============== Règles de documentation ===============

doc:  $(DOC_DIR)
	$(DOXYGEN) $(DOXYFILE)

doc-view:
	@make doc-clean
	@make doc
	@firefox --new-window doc/html/files.html


# =============== Règles de nettoyage ==================

clean:
	$(RM_DIR) $(OUTPUT_DIR)
	$(RM) 	  $(TARGET)
	
doc-clean:
	$(RM_DIR) $(DOC_DIR)

# =============== Aide ==================

help:
	@echo "====== Cibles disponibles ======"
	@echo "  make              - Compile le programme (défaut)"
	@echo "  make test         - Compile et exécute les tests"
	@echo "  make doc          - Génère la documentation"
	@echo "  make doc-view     - Génère et affiche la documentation"
	@echo "  make doc-clean    - Supprime la documentation"
	@echo "  make clean        - Supprime les fichiers compilés"
	@echo "  make help         - Affiche cette aide"