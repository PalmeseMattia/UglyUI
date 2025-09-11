# TUI Library Makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
SRCDIR = src
INCDIR = include
EXAMPLEDIR = examples
TESTDIR = tests
BUILDDIR = build
TARGETDIR = target

# Find all source files
SOURCES = $(shell find $(SRCDIR) -name "*.c")
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Library name
LIBRARY = $(TARGETDIR)/uglyui.a

# Default target
all: $(LIBRARY) examples

# Create directories
$(BUILDDIR) $(TARGETDIR):
	mkdir -p $@

# Build static library
$(LIBRARY): $(OBJECTS) | $(TARGETDIR)
	ar rcs $@ $^

# Compile source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build examples
examples: $(LIBRARY)
	$(CC) $(CFLAGS) $(EXAMPLEDIR)/basic_example.c -L$(TARGETDIR) -l:uglyui.a -o $(TARGETDIR)/basic_example

# Build tests (when you add them)
tests: $(LIBRARY)
	@echo "No tests yet"

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR) $(TARGETDIR)

# Install headers and library (optional)
install: $(LIBRARY)
	sudo cp -r $(INCDIR)/* /usr/local/include/
	sudo cp $(LIBRARY) /usr/local/lib/

# Uninstall
uninstall:
	sudo rm -rf /usr/local/include/uglyui
	sudo rm -f /usr/local/lib/uglyui.a

# Development helper - rebuild everything
rebuild: clean all

.PHONY: all examples tests clean install uninstall rebuild
