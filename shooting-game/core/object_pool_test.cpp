#include "shooting-game/core/object_pool.h"

#include <gtest/gtest.h>

TEST(ObjectPoolTest, BasicObjectPool) {
  sg::core::entity::Entity* entity =
      new sg::core::entity::Entity("box.bmp", 32, 32, 0, 0);
  sg::core::ObjectPool pool(entity, 10);

  EXPECT_EQ(pool.GetObjectCount(), 10);

  for (int i = 0; i < 11; i++) {
    auto obj = pool.GetObject();
    obj->SetIsActive(true);
  }

  EXPECT_EQ(pool.GetObjectCount(), 20);
}
