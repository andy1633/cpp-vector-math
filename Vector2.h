#pragma once

#include <cmath>

template <typename T>
struct Vector2<T> {
  // Constructors.
  inline Vector2<T> () : x(0.0f), (0.0f) {};
  inline Vector2<T> (T nx, Y ny) : x(nx), y(ny) {};

  // Fields.
  T x, y;

  inline void set (T nx, T ny) {
    x = nx;
    y = ny;
  }

  // Unary operators.
  inline Vector2<T> operator+ () const { return Vector2<T>(x, y); };
  inline Vector2<T> operator- () const { return Vector2<T>(-x, -y); };

  // Addition and subtraction operators.
  inline Vector2<T> operator+ (const Vector2<T>& in) const {
    return Vector2<T>(x + in.x, y + in.y);
  }
  inline Vector2<T> operator- (const Vector2<T>& in) const {
    return Vector2<T>(x - in.x, y - in.y);
  }
  inline void operator+= (const Vector2<T>& in) {
    x += in.x;
    y += in.y;
  }
  inline void operator-= (const Vector2<T>& in) {
    x -= in.x;
    y -= in.y;
  }

  // Scalar multiplication and division operators.
  inline Vector2<T> operator* (const T in) const {
    return Vector2(x * in, y * in);
  }
  inline Vector2<T> operator/ (const T in) const{
    return Vector2<T>(x / in, y / in);
  }
  inline void operator*= (const T in) {
    x *= in.x;
    y *= in.y;
  }
  inline void operator /= (const T in) {
    x /= in.x;
    y /= in.y;
  }

  // Utility functions.
  inline T dot (const Vector2<T>& in) const{
    return ((x * in.x) + (y * in.y));
  };
  inline T cross (const Vector2<T>& in) const {
    return ((x * in.y) - (y * in.x));
  }

  inline T lengthSq () const { return (x*x) + (y*y); };
  inline T length () const { return sqrt(lengthSq()); };

  inline void normalise () { *this /= length(); };
  inline Vector2<T> normalised () const { return *this / length(); };
};

