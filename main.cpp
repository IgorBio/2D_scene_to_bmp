#include <libbitmap.h>

#include <iostream>

#include "objects_2D.h"
#include "utils.h"

int main() {
  try {
    int width, height;
    auto objects = parse_file("scene.txt", width, height);
    draw_scene(objects, width, height, "output.bmp");
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
