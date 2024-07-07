#pragma once
#include <libbitmap.h>

#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "objects_2D.h"

std::vector<std::shared_ptr<Object>> parse_file(const std::string& filename,
                                                int& width, int& height) {}
void draw_scene(const std::vector<std::shared_ptr<Object>>& objects, int width,
                int height, const std::string& output_filename) {}