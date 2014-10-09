/**
 * Copyright (c) 2014, LOZI., JSC
 * All rights reserved.
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 */

#include <eevee/eevee.hpp>
#include <gtest/gtest.h>

using eevee::hello;

TEST(eevee, hello_world) {
  auto s = hello::world();
  EXPECT_EQ(s, "Hello world!");
}
