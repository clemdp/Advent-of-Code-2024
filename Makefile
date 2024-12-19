CC=gcc
CFLAGS= -Wall -Wextra -std=c99
TARGET= aoc24

OBJDIR= obj
OBJS= $(OBJDIR)/main.o
SRCDIR= src
INCDIR= include

all: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): obj/main.o
	$(CC) $(CFLAGS) -o $(TARGET) obj/main.o

clean:
	rm -rf $(OBJDIR) $(TARGET)
