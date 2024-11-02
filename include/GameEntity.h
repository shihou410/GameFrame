#pragma once
#include "./linmath.h"
#include <functional>
class MgrEntity;
class GameEntity {
  friend MgrEntity;

public:
  std::function<void(GameEntity *)> onEnter;
  std::function<void(GameEntity *)> onUpdate;
  std::function<void(GameEntity *)> onDraw;
  std::function<void(GameEntity *)> onDestroy;

  vec2 pos;

private:
  int id;
  bool lastState;
  bool active;
  GameEntity();
  vec2 halfSize;
  int animaId;

  void enter();
  void update();
  void draw();
  void destroy();

public:
  inline int getId() const { return this->id; }
  inline int getAnimaId() const { return this->animaId; }
  inline void setAnimaId(int value) { this->animaId = value; }
};
