#pragma once
#include <iostream>
#include <array>
#include <cmath>
#include <type_traits>

namespace ZLC {

// 泛型 Point 和 Vector 类模板
// 支持不同维度，并允许 Point 和 Vector 互换

template <typename T, size_t N>
class Vector;

template <typename T, size_t N>
class Point {
public:
  std::array<T, N> coords;

  Point() { coords.fill(T{}); }

  explicit Point(const std::array<T, N>& c) : coords(c) {}

  T& operator[](size_t index) { return coords[index]; }
  const T& operator[](size_t index) const { return coords[index]; }

  // 减法运算，结果是一个 Vector
  Vector<T, N> operator-(const Point& other) const {
    Vector<T, N> result;
    for (size_t i = 0; i < N; ++i) {
      result[i] = coords[i] - other.coords[i];
    }
    return result;
  }

  // 加法运算，与 Vector 相加返回 Point
  Point operator+(const Vector<T, N>& vec) const {
    Point result;
    for (size_t i = 0; i < N; ++i) {
      result[i] = coords[i] + vec[i];
    }
    return result;
  }
};

template <typename T, size_t N>
class Vector {
public:
  std::array<T, N> coords;

  Vector() { coords.fill(T{}); }

  explicit Vector(const std::array<T, N>& c) : coords(c) {}

  T& operator[](size_t index) { return coords[index]; }
  const T& operator[](size_t index) const { return coords[index]; }

  // 加法运算，结果是 Vector
  Vector operator+(const Vector& other) const {
    Vector result;
    for (size_t i = 0; i < N; ++i) {
      result[i] = coords[i] + other.coords[i];
    }
    return result;
  }

  // 减法运算，结果是 Vector
  Vector operator-(const Vector& other) const {
    Vector result;
    for (size_t i = 0; i < N; ++i) {
      result[i] = coords[i] - other.coords[i];
    }
    return result;
  }

  // 点乘运算
  T Dot(const Vector& other) const {
    T result = T{};
    for (size_t i = 0; i < N; ++i) {
      result += coords[i] * other.coords[i];
    }
    return result;
  }

  // 叉乘运算 (适用于 2D 和 3D)
  static auto Cross(const Vector& u, const Vector& v) {
    if constexpr (N == 2) {
      // 在 2D 中，叉乘返回标量
      return u[0] * v[1] - u[1] * v[0];
    }
    else if constexpr (N == 3) {
      // 在 3D 中，叉乘返回 Vector
      return Vector({
          u[1] * v[2] - u[2] * v[1],
          u[2] * v[0] - u[0] * v[2],
          u[0] * v[1] - u[1] * v[0]
        });
    }
    else {
      static_assert(N == 2 || N == 3, "Cross product is only defined for 2D and 3D vectors.");
    }
  }
};

} // namespace