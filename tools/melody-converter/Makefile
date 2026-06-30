SONG ?= songs/song.c
OUTPUT ?= song.rmf

CC      := gcc
CFLAGS  := -Wall -Werror -Wextra
DEFINES := -DSONG=\"$(SONG)\" -DOUTPUT=\"$(OUTPUT)\"
INCLUDE := -Iinclude

SRC := \
	src/main.c \
	src/writer.c \
    $(SONG)

OBJ := $(SRC:.c=.o)

TARGET := out/melody_converter

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p out
	$(CC) $^ -o $@

%.o: %.c force
	$(CC) $(CFLAGS) $(INCLUDE) $(DEFINES) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf out
	find . -name '*.o' -delete

force:

.PHONY: all run clean force
