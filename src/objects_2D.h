#pragma once
#include <libbitmap.h>

class Object {
 public:
  virtual ~Object() = default;

  virtual void draw(Bitmap& bmp) = 0;

 protected:
  void draw_pixel(Bitmap& bmp, int x, int y) {
    if (x >= 0 && x < bmp.m_width && y >= 0 && y < bmp.m_height) {
      size_t idx = (y * bmp.m_width + x) * 3;
      bmp.m_buffer[idx] = 255;
      bmp.m_buffer[idx + 1] = 0;
      bmp.m_buffer[idx + 2] = 0;
    }
  }
};

class Point : public Object {
 public:
  Point(int x, int y) : x(x), y(y) {}
  void draw(Bitmap& bmp) override { draw_pixel(bmp, x, y); }

 private:
  int x, y;
};

class Rect : public Object {
 public:
  Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
  void draw(Bitmap& bmp) override {
    for (int x = x1; x <= x2; ++x) {
      for (int y = y1; y <= y2; ++y) {
        if (x == x1 || x == x2 || y == y1 || y == y2) {
          draw_pixel(bmp, x, y);
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
      draw_pixel(bmp, x, y);
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
      draw_pixel(bmp, x, y);
    }
  }

 private:
  int y1, y2, x;
};

class SLine : public Object {
 public:
  SLine(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

  void draw(Bitmap& bmp) override {
    int err = abs(x2 - x1) - abs(y2 - y1);

    while (true) {
      draw_pixel(bmp, x1, y1);
      if (x1 == x2 && y1 == y2) break;
      if (err * 2 > -abs(y2 - y1)) {
        err -= abs(y2 - y1);
        x1 += (x1 < x2) ? 1 : -1;
      }
      if (err * 2 < abs(x2 - x1)) {
        err += abs(x2 - x1);
        y1 += (y1 < y2) ? 1 : -1;
      }
    }
  }

 private:
  int x1, y1, x2, y2;
};
