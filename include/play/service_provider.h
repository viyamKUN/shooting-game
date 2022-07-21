#ifndef __SERVICE_PROVIDER_H_
#define __SERVICE_PROVIDER_H_

#include "play/bullet_pool.h"
#include "play/enemy/enemy_blood_pool.h"
#include "play/ui/ui_manager.h"
#include "play/play_manager.h"

namespace sg {
namespace play {
class ServiceProvider {
 public:
  static ServiceProvider* GetInstance();

  ServiceProvider();
  ~ServiceProvider();

  PlayManager* GetPlayManager();
  ui::UiManager* GetUIManager();
  BulletPool* GetBulletPool();
  enemy::EnemyBloodPool* GetBloodPool();

 private:
  static ServiceProvider* instance;
  PlayManager* playManager;
  ui::UiManager* uiManager;
  BulletPool* bulletPool;
  enemy::EnemyBloodPool* bloodPool;
};

}  // namespace play
}  // namespace sg

#endif
