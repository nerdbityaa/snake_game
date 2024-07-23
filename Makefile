CC := gcc
CC_FLAGS := -std=c99 -Wall -Wextra

SRC_DIR := ./src
BUILD_DIR := ./build

LIBS := -lSDL2
EXEC := main

.PHONY: clean all build debug run

debug: CC_FLAGS += -ggdb
debug: build

all: $(BUILD_DIR)/$(EXEC)

run: clean all
	$(BUILD_DIR)/$(EXEC)

$(BUILD_DIR)/$(EXEC): build

build: $(SRC_DIR)/*.c
	$(CC) $(CC_FLAGS) $^ -o $(BUILD_DIR)/$(EXEC) $(LIBS)

clean:
	-rm $(BUILD_DIR)/*