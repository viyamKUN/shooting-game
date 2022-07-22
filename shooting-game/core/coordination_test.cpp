#include "shooting-game/core/coordination.h"

#include <gtest/gtest.h>

TEST(CoordinationTest, BasicCoordination) {
  sg::core::Coordination c(1, 2);

  EXPECT_EQ(c.getX(), 1);
  EXPECT_EQ(c.getY(), 2);

  c.setX(13);
  EXPECT_EQ(c.getX(), 13);
  EXPECT_EQ(c.getY(), 2);

  c.setY(25);
  EXPECT_EQ(c.getX(), 13);
  EXPECT_EQ(c.getY(), 25);
}
