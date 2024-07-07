#pragma once
#include <libbitmap.h>

class Object {
 public:
  virtual void draw(Bitmap& bmp) = 0;
  virtual ~Object() = default;
};

class Point : public Object {
 public:
  Point(int x, int y) : x(x), y(y) {}
  void draw(Bitmap& bmp) override {
    if (x >= 0 && x < bmp.m_width && y >= 0 && y < bmp.m_height) {
      size_t idx = (y * bmp.m_width + x) * 3;
      bmp.m_buffer[idx] = 255;
      bmp.m_buffer[idx + 1] = 0;
      bmp.m_buffer[idx + 2] = 0;
    }
  }

 private:
  int x, y;
};

class Rect : public Object {
 public:
  Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
  void draw(Bitmap& bmp) override {
    for (int x = x1; x <= x2; ++x) {
      for (int y = y1; y <= y2; ++y) {
        if (x >= 0 && x < bmp.m_width && y >= 0 && y < bmp.m_height &&
            (x == x1 || x == x2 || y == y1 || y == y2)) {
          size_t idx = (y * bmp.m_width + x) * 3;
          bmp.m_buffer[idx] = 255;
          bmp.m_buffer[idx + 1] = 0;
          bmp.m_buffer[idx + 2] = 0;
        }
      }
    }
  }

 private:
  int x1, y1, x2, y2;
};

class HLine : public Object {
 public:
  HLine(int x1, int x2, int y) : x1(x1), x2(x2), y(y) {}
  void draw(Bitmap& bmp) override {
    for (int x = x1; x <= x2; ++x) {
      if (x >= 0 && x < bmp.m_width && y >= 0 && y < bmp.m_height) {
        size_t idx = (y * bmp.m_width + x) * 3;
        bmp.m_buffer[idx] = 255;
        bmp.m_buffer[idx + 1] = 0;
        bmp.m_buffer[idx + 2] = 0;
      }
    }
  }

 private:
  int x1, x2, y;
};

class VLine : public Object {
 public:
  VLine(int y1, int y2, int x) : y1(y1), y2(y2), x(x) {}
  void draw(Bitmap& bmp) override {
    for (int y = y1; y <= y2; ++y) {
      if (x >= 0 && x < bmp.m_width && y >= 0 && y < bmp.m_height) {
        size_t idx = (y * bmp.m_width + x) * 3;
        bmp.m_buffer[idx] = 255;
        bmp.m_buffer[idx + 1] = 0;
        bmp.m_buffer[idx + 2] = 0;
      }
    }
  }

 private:
  int y1, y2, x;
};
