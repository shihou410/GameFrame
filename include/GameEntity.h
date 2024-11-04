#pragma once
#include "./linmath.h"
#include <any>
#include <functional>
#include <map>
#include <string>

class MgrEntity;

class GameEntity {
  friend MgrEntity;

  // std::map<std::string, std::any> data;

public:
  std::function<void(GameEntity *)> onEnter;
  std::function<void(GameEntity *)> onUpdate;
  std::function<void(GameEntity *)> onDraw;
  std::function<void(GameEntity *)> onDestroy;

  vec2 pos;
  bool lastState;
  virtual ~GameEntity() {}

protected:
  int id;
  bool active;
  vec2 halfSize;
  int animaId;

  GameEntity(); // 保护构造函数

private:
  void enter();
  void update();
  void draw();
  void destroy();

public:
  inline int getId() const { return this->id; }
  inline int getAnimaId() const { return this->animaId; }
  inline void setAnimaId(int value) { this->animaId = value; }

  // inline void setValue(const std::string &key, std::any value) {
  //   this->data[key] = std::move(value);
  // }

  // template <typename T> inline T getValue(const std::string &key) {
  //   if (this->data.count(key) == 0)
  //     return T(); // 返回默认值
  //   return std::any_cast<T>(this->data[key]);
  // }
};
