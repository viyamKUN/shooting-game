#include "shooting-game/core/entity/entity.h"

#include <gtest/gtest.h>

TEST(EntityTest, BasicEntityTest) {
  sg::core::entity::Entity ent("box.bmp", 32, 32, 0, 0);
  EXPECT_EQ(ent.GetIsActive(), true);
}

TEST(EntityTest, CloneEntityTest) {
  sg::core::entity::Entity ent("box.bmp", 32, 32, 0, 0);
  EXPECT_EQ(ent.GetIsActive(), true);

  auto clone = ent.Clone();
}
