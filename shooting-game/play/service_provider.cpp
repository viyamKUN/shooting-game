#include "shooting-game/play/service_provider.h"

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

ServiceProvider::~ServiceProvider() {
  delete uiManager;
  delete bulletPool;
  delete bloodPool;
  delete scoreManager;
}

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

ScoreManager* ServiceProvider::GetScoreManager() {
  if (scoreManager == NULL) {
    scoreManager = new ScoreManager();
  }
  return scoreManager;
}

}  // namespace play
}  // namespace sg
