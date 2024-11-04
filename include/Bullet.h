#pragma once

#include "Actor.h"
#include "Enums.h"
class Bullet : public Actor {
private:
  int animas[4];
  float moveSpeed;

public:
  Bullet(int, int, EnumActorDirection dir = EnumActorDirection::DIR_UP);

protected:
  void on_enter() override;
  void on_update() override;
  void on_draw() override;
  void on_destroy() override;
};
