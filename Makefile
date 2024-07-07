.PHONY: all build rebuild run clean

BUILD_DIR = ./build
PROJECT_NAME = scene2D

all: build

rebuild: clean build

build:
	@cmake -S . -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR) --target $(PROJECT_NAME)

run: build
	@./$(BUILD_DIR)/$(PROJECT_NAME)

clean:
	@rm -rf $(BUILD_DIR) *.bmp