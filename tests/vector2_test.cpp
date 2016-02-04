#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Vec2Test
#include <boost/test/unit_test.hpp>

#include "../Vector2.h"
typedef Vector2f Vec2;

// Test cases for Vector2 math class.

BOOST_AUTO_TEST_CASE(equality) {
  Vec2 v1(10.0f, 10.0f);
  Vec2 v2(10.0f, 10.0f);
  BOOST_REQUIRE(v1 == v2);
}

BOOST_AUTO_TEST_CASE(inequality) {
  Vec2 v1(1.0f, 0.0f);
  Vec2 v2(-1.0f, 0.0f);
  BOOST_REQUIRE(v1 != v2);
}

BOOST_AUTO_TEST_CASE(positive) {
  Vec2 v1(-1.0f, -5.0f);
  BOOST_REQUIRE(+v1 == Vec2(-1.0f, -5.0f));
}

BOOST_AUTO_TEST_CASE(negative) {
  Vec2 v1(-5.0f, -3.0f);
  BOOST_REQUIRE(-v1 == Vec2(5.0f, 3.0f));
}

BOOST_AUTO_TEST_CASE(add_two_pos) {
  Vec2 v1(1.0f, 3.0f);
  Vec2 v2(5.0f, 2.0f);
  BOOST_REQUIRE((v1 + v2) == Vec2(6.0f, 5.0f));
}

BOOST_AUTO_TEST_CASE(add_two_neg) {
  Vec2 v1(-5.0f, -20.0f);
  Vec2 v2(-2.0f, -12.0f);
  BOOST_REQUIRE((v1 + v2) == Vec2(-7.0f, -32.0f));
}

BOOST_AUTO_TEST_CASE(sub_two_pos) {
  Vec2 v1(12.0f, 5.0f);
  Vec2 v2(20.0f, 8.0f);
  BOOST_REQUIRE((v1 - v2) == Vec2(-8.0f, -3.0f));
}

BOOST_AUTO_TEST_CASE(sub_two_neg) {
  Vec2 v1(-10.0f, -15.0f);
  Vec2 v2(-2.0f, -5.0f);
  BOOST_REQUIRE((v1 - v2) == Vec2(-8.0f, -10.0f));
}

BOOST_AUTO_TEST_CASE(compound_add) {
  Vec2 v1(-1.0f, 5.0f);
  Vec2 v2(10.0f, 10.0f);
  v1 += v2;
  BOOST_REQUIRE(v1 == Vec2(9.0f, 15.0f));
}

BOOST_AUTO_TEST_CASE(compound_sub) {
  Vec2 v1(12.0f, 5.0f);
  Vec2 v2(6.0f, 6.0f);
  v1 -= v2;
  BOOST_REQUIRE(v1 == Vec2(6.0f, -1.0f));
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
  Vec2 v1(-5.0f, 10.0f);
  BOOST_REQUIRE(v1 * 5.0f == Vec2(-25.0f, 50.0f));
  BOOST_REQUIRE(5.0f * v1 == Vec2(-25.0f, 50.0f));
}

BOOST_AUTO_TEST_CASE(scalar_div) {
  Vec2 v1(-5.0f, 10.0f);
  BOOST_REQUIRE(v1 / 5.0f == Vec2(-1.0f, 2.0f));
}

BOOST_AUTO_TEST_CASE(dot_product) {
  Vec2 v1(2.0f, 5.0f);
  Vec2 v2(-3.0f, 10.0f);
  BOOST_REQUIRE(v1.dot(v2) == 44.0f);
}

BOOST_AUTO_TEST_CASE(cross_product) {
  Vec2 v1(100.0f, 100.0f);
  Vec2 v2(500.0f, 200.0f);
  BOOST_REQUIRE(v1.cross(v2) == -30000.0f);
}

BOOST_AUTO_TEST_CASE(length_sq) {
  BOOST_REQUIRE(Vec2(3.0f, 4.0f).length_sq() == 25.0f);
}

BOOST_AUTO_TEST_CASE(length) {
  BOOST_REQUIRE(Vec2(4.0f, 3.0f).length() == 5.0f);
}

BOOST_AUTO_TEST_CASE(normalise) {
  Vec2 v1(4.0f, 3.0f);
  v1.normalise();
  BOOST_REQUIRE(v1 == Vec2(4.0f/5.0f, 3.0f / 5.0f));
}

BOOST_AUTO_TEST_CASE(normalised) {
  BOOST_REQUIRE(Vec2(3.0f, 4.0f).normalised() == Vec2(3.0f/5.0f, 4.0f/5.0f));
}
