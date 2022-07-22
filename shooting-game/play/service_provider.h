#ifndef __SERVICE_PROVIDER_H_
#define __SERVICE_PROVIDER_H_

#include "shooting-game/play/bullet/bullet_pool.h"
#include "shooting-game/play/enemy/enemy_blood_pool.h"
#include "shooting-game/play/ui/ui_manager.h"

namespace sg {
namespace play {
class ServiceProvider {
 public:
  static ServiceProvider* GetInstance();

  ServiceProvider();
  ~ServiceProvider();

  ui::UiManager* GetUIManager();
  BulletPool* GetBulletPool();
  enemy::EnemyBloodPool* GetBloodPool();

 private:
  static ServiceProvider* instance;
  ui::UiManager* uiManager;
  BulletPool* bulletPool;
  enemy::EnemyBloodPool* bloodPool;
};

}  // namespace play
}  // namespace sg

#endif
