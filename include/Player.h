#pragma once
#include "Actor.h"
class Player : public Actor {
private:
  int animas[4];

public:
  Player(int, int);
  virtual ~Player() {}

  float fireCd;
  void fire();

protected:
  void on_enter() override;
  void on_update() override;
  void on_draw() override;
  void on_destroy() override;
};