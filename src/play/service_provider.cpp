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

ServiceProvider::ServiceProvider() : bulletPool(NULL) {}

ServiceProvider::~ServiceProvider() {}

BulletPool* ServiceProvider::GetBulletPool() {
  if (bulletPool == NULL) {
    bulletPool = new BulletPool();
  }
  return bulletPool;
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
