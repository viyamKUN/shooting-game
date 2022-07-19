#ifndef __SERVICE_PROVIDER_H_
#define __SERVICE_PROVIDER_H_


namespace sg {
namespace gamelogic {
namespace play {
class ServiceProvider {
 public:
  static ServiceProvider* GetInstance();

  ServiceProvider();
  ~ServiceProvider();


 private:
  static ServiceProvider* instance;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
