IMAGE ?= images/image.c
OUTPUT ?= image.rif

CC      := gcc
CFLAGS  := -Wall -Werror -Wextra
DEFINES := -DIMAGE=\"$(IMAGE)\" -DOUTPUT=\"$(OUTPUT)\"
INCLUDE := -Iinclude

SRC := \
	src/main.c \
	src/writer.c \
    $(IMAGE)

OBJ := $(SRC:.c=.o)

TARGET := out/image_converter

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p out
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(DEFINES) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf out
	find . -name '*.o' -delete

force:

.PHONY: all run clean
