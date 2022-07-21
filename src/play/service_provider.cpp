#include "play/service_provider.h"

namespace sg {
namespace play {

ServiceProvider* ServiceProvider::instance = NULL;

ServiceProvider* ServiceProvider::GetInstance() {
  if (instance == NULL) {
    instance = new ServiceProvider();
  }
  return instance;
}

ServiceProvider::ServiceProvider()
    : uiManager(NULL), bulletPool(NULL), bloodPool(NULL) {}

ServiceProvider::~ServiceProvider() {}

ui::UiManager* ServiceProvider::GetUIManager() {
  if (uiManager == NULL) {
    uiManager = new ui::UiManager();
  }
  return uiManager;
}

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
}  // namespace sg
