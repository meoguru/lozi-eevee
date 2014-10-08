/**
 * Copyright (c) 2014, LOZI., JSC
 * All rights reserved.
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 */

#include <vector>

#include <gtest/gtest.h>
#include <json11/json11.hpp>

using json11::Json;

TEST(json11, implicit_serialize) {
  class Point {
  public:
    int x;
    int y;

    Point (int x, int y): x(x), y(y) {}

    Json to_json() const {
      return Json::array { x, y };
    }
  };

  std::vector<Point> points = {
    { 1, 2 },
    { 10, 20 },
    { 100, 200 }
  };

  Json expected_rep = Json::array {
    Json::array {1, 2},
    Json::array {10, 20},
    Json::array {100, 200}
  };

  EXPECT_EQ(Json(points), expected_rep);
}
