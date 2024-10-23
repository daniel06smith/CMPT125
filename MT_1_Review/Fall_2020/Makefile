# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files (add more here if needed)
SRCS = f2020_q1.c f2020_q2.c

# Object files generated from the source files
OBJS = $(SRCS:.c=.o)

# Targets (executables) generated from the source files
TARGETS = $(SRCS:.c=)

# Default rule to build all targets
all: $(TARGETS)

# Pattern rule to create an executable from an object file
%: %.o
	$(CC) $(CFLAGS) -o $@ $<

# Pattern rule to compile a .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean rule to remove all object files and executables
clean:
	rm -f $(OBJS) $(TARGETS)
