.PHONY: all build rebuild run clean

BUILD_DIR = ./build

all: build

rebuild: clean build

build:
	@cmake -S . -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR) --target scene

run: build
	@./$(BUILD_DIR)/scene

clean:
	@rm -rf $(BUILD_DIR) *.log