#include "utils.h"

std::vector<std::shared_ptr<Object>> parse_file(const std::string& filename,
                                                int& width, int& height) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  std::vector<std::shared_ptr<Object>> objects;
  std::string line;
  int x1, y1, x2, y2;

  // Read canvas size
  if (std::getline(file, line)) {
    std::istringstream ss(line);
    ss >> x1 >> y1 >> x2 >> y2;
    width = x2 - x1;
    height = y2 - y1;
  }

  // Read objects
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string type;
    ss >> type;
    if (type == "point") {
      ss >> x1 >> y1;
      objects.push_back(std::make_shared<Point>(x1, y1));
    } else if (type == "rect") {
      ss >> x1 >> y1 >> x2 >> y2;
      objects.push_back(std::make_shared<Rect>(x1, y1, x2, y2));
    } else if (type == "hline") {
      ss >> x1 >> x2 >> y1;
      objects.push_back(std::make_shared<HLine>(x1, x2, y1));
    } else if (type == "vline") {
      ss >> y1 >> y2 >> x1;
      objects.push_back(std::make_shared<VLine>(y1, y2, x1));
    } else if (type == "sline") {
      ss >> x1 >> y1 >> x2 >> y2;
      objects.push_back(std::make_shared<SLine>(x1, y1, x2, y2));
    }
  }
  return objects;
}

void draw_scene(const std::vector<std::shared_ptr<Object>>& objects, int width,
                int height, const std::string& output_filename) {
  Bitmap bmp;
  bmp.m_height = height;
  bmp.m_width = width;
  bmp.m_buffer = new uint8_t[width * height * 3];

  for (const auto& obj : objects) {
    obj->draw(bmp);
  }

  bmp.save(output_filename.c_str());
}