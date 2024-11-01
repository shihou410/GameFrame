#pragma once
#include <vector>

class Game;
class GameEntity;
class MgrEntity {
private:
  friend Game;
  Game *game;
  std::vector<GameEntity *> entitys;
  MgrEntity(Game *);
  void update();
  void draw();
  void destroyEntity(int);
  void clear();

public:
  int createEntity(int animaId, int x, int y, int w = 100, int h = 100);
  GameEntity *getEntity(int);
};