
#pragma once

#include <functional>
class GameObject {

  bool active;

private:
  GameObject();

  void update();
  void draw();

public:
  std::function<void()> onUpdate;
};
