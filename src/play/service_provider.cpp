#include "play/service_provider.h"

namespace sg {
namespace gamelogic {
namespace play {

ServiceProvider* ServiceProvider::instance = NULL;

ServiceProvider* ServiceProvider::GetInstance() {
  if (instance == NULL) {
    instance = new ServiceProvider();
  }
  return instance;
}

ServiceProvider::ServiceProvider() : bulletPool(NULL), bloodPool(NULL) {}

ServiceProvider::~ServiceProvider() {}

BulletPool* ServiceProvider::GetBulletPool() {
  if (bulletPool == NULL) {
    bulletPool = new BulletPool();
  }
  return bulletPool;
}

enemy::EnemyBloodPool* ServiceProvider::GetBloodPool() {
  if (bloodPool == NULL) {
    bloodPool = new enemy::EnemyBloodPool();
  }
  return bloodPool;
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
