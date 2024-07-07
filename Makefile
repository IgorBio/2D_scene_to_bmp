.PHONY: all build rebuild run clean

BUILD_DIR = ./build

all: build

rebuild: clean build

build:
	@cmake -S . -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR) --target example

clean:
	@rm -rf $(BUILD_DIR) *.log