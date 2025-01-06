CC=gcc
CFLAGS= -Wall -Wextra -std=c99
TARGET= aoc24

OBJDIR=obj
SRCDIR=src
INCDIR=include

SOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))


all: $(TARGET)

# Règle de construction de l'exécutable final
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle générique pour la création des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Assurer que le répertoire obj existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Nettoyage des fichiers générés
clean:
	rm -rf $(OBJDIR) $(TARGET)