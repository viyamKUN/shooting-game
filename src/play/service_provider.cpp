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


}  // namespace play
}  // namespace gamelogic
}  // namespace sg
