#pragma once
#include "Vector.h"
namespace ZLC {

// 判断四边形是否是凸的
template <typename T>
bool IsConvexQuad(const Point<T, 3>& a, const Point<T, 3>& b, const Point<T, 3>& c, const Point<T, 3>& d) {
  using Vec3 = Vector<T, 3>;

  Vec3 bda = Vec3::Cross(d - b, a - b);
  Vec3 bdc = Vec3::Cross(d - b, c - b);

  if (bda.Dot(bdc) >= 0.0) {
    return false;
  }

  Vec3 acd = Vec3::Cross(c - a, d - a);
  Vec3 acb = Vec3::Cross(c - a, b - a);

  return acd.Dot(acb) < 0.0;
}

}