#ifndef __SERVICE_PROVIDER_H_
#define __SERVICE_PROVIDER_H_

#include "play/bullet_pool.h"
#include "play/enemy/enemy_blood_pool.h"

namespace sg {
namespace gamelogic {
namespace play {
class ServiceProvider {
 public:
  static ServiceProvider* GetInstance();

  ServiceProvider();
  ~ServiceProvider();

  BulletPool* GetBulletPool();
  enemy::EnemyBloodPool* GetBloodPool();

 private:
  static ServiceProvider* instance;
  BulletPool* bulletPool;
  enemy::EnemyBloodPool* bloodPool;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
