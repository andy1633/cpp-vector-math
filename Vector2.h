#pragma once

#include <cmath>

template <typename T>
struct Vector2 {
  // Constructors.
  inline Vector2<T> () : x(0.0f), y(0.0f) {};
  inline Vector2<T> (T nx, T ny) : x(nx), y(ny) {};

  // Fields.
  T x, y;

  // Unary operators.
  inline Vector2<T> operator+ () const { return Vector2<T>(x, y); };
  inline Vector2<T> operator- () const { return Vector2<T>(-x, -y); };

  // Addition and subtraction operators.
  inline Vector2<T>& operator+= (const Vector2<T>& in) {
    x += in.x;
    y += in.y;
    return *this;
  }
  inline Vector2<T>& operator-= (const Vector2<T>& in) {
    x -= in.x;
    y -= in.y;
    return *this;
  }


  inline Vector2<T>& operator*= (const T in) {
    x *= in;
    y *= in;
    return *this;
  }
  inline Vector2<T>& operator /= (const T in) {
    x /= in;
    y /= in;
    return *this;
  }

  // Utility functions.
  inline T dot (const Vector2<T>& in) const{
    return (x * in.x) + (y * in.y);
  };
  inline T cross (const Vector2<T>& in) const {
    return (x * in.y) - (y * in.x);
  }

  inline T length_sq () const { return (x*x) + (y*y); };
  inline T length () const { return sqrt(length_sq()); };

  inline void normalise () { *this /= length(); };
  inline Vector2<T> normalised () const { return *this / length(); };
};

template<typename T>
inline bool operator== (const Vector2<T>& v1, const Vector2<T>& v2) {
  return (v1.x == v2.x) && (v1.y == v2.y);
}
template<typename T>
inline bool operator!= (const Vector2<T>& v1, const Vector2<T>& v2) {
  return !(v1 == v2);
}
// Binary addition, subtraction, multiplication and division operators.
template <typename T>
inline Vector2<T> operator+ (Vector2<T> v1, const Vector2<T>& v2) {
  v1 += v2;
  return v1;
}
template <typename T>
inline Vector2<T> operator- (Vector2<T> v1, const Vector2<T>& v2) {
  v1 -= v2;
  return v1;
}
template <typename T>
inline Vector2<T> operator* (const T s, Vector2<T> v) {
  v *= s;
  return v;
}
template <typename T>
inline Vector2<T> operator* (Vector2<T> v, const T s) {
  v *= s;
  return v;
}
template <typename T>
inline Vector2<T> operator/ (Vector2<T> v, const T s) {
  v /= s;
  return v;
}

typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

