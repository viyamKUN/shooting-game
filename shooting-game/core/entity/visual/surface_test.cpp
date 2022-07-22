#include "shooting-game/core/entity/visual/surface.h"

#include <gtest/gtest.h>

TEST(SurfaceTest, BasicSurfaceTest) {
  sg::core::entity::visual::Surface surface("box.bmp", 32, 32);

  EXPECT_EQ(surface.GetSize()->getX(), 32);
  EXPECT_EQ(surface.GetSize()->getY(), 32);
}
