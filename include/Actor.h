#pragma once
#include "./Enums.h"
#include "./GameEntity.h"
class Actor : public GameEntity {

protected:
  EnumActorDirection dir;
  int horizontal;
  int vertical;

  float moveSpeed;

public:
  Actor(EnumActorDirection = EnumActorDirection::DIR_UP);
  virtual ~Actor(){};

protected:
  virtual void on_enter();
  virtual void on_update();
  virtual void on_draw();
  virtual void on_destroy();
};
