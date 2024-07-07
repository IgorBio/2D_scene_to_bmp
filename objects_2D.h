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
  void draw(Bitmap& bmp) override {}

 private:
  int x, y;
};

class Rect : public Object {
 public:
  Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
  void draw(Bitmap& bmp) override {}

 private:
  int x1, y1, x2, y2;
};

class HLine : public Object {
 public:
  HLine(int x1, int x2, int y) : x1(x1), x2(x2), y(y) {}
  void draw(Bitmap& bmp) override {}

 private:
  int x1, x2, y;
};

class VLine : public Object {
 public:
  VLine(int y1, int y2, int x) : y1(y1), y2(y2), x(x) {}
  void draw(Bitmap& bmp) override {}

 private:
  int y1, y2, x;
};
