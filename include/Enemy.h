#pragma once

#include "Actor.h"
class Enemy : public Actor {
private:
  int animas[4];

  float fireCd;

  float moveCount;
  float maxMoveCount;

public:
  Enemy(int, int);
  virtual ~Enemy() {}

private:
  void randomDir();
  void fire();

protected:
  void on_enter() override;
  void on_update() override;
  void on_draw() override;
  void on_destroy() override;
};