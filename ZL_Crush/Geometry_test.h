#pragma once
#include <iostream>
#include "Geometry.h"

// 测试函数
void test_IsConvexQuad() {
  using namespace ZLC;
  using Point2D = Point<double, 2>;
  using Point3D = Point<double, 3>;

  // 2D 测试
  Point2D p1({ 0, 0 });
  Point2D p2({ 1, 0 });
  Point2D p3({ 1, 1 });
  Point2D p4({ 0, 1 });

  Vector<double, 2> v2d1 = p2 - p1;
  Vector<double, 2> v2d2 = p3 - p2;
  auto cross2d = Vector<double, 2>::Cross(v2d1, v2d2);

  std::cout << "2D Cross Product: " << cross2d << std::endl;

  // 3D 测试
  Point3D a({ 0, 0, 0 });
  Point3D b({ 1, 0, 0 });
  Point3D c({ 1, 1, 0 });
  Point3D d({ 0, 1, 0 });

  if (IsConvexQuad(a, b, c, d)) {
    std::cout << "The quadrilateral is convex." << std::endl;
  }
  else {
    std::cout << "The quadrilateral is not convex." << std::endl;
  }
}