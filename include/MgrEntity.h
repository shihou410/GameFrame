#pragma once
#include <map>
#include <vector>

class Game;
class GameEntity;
class MgrEntity {
private:
  friend Game;
  Game *game;
  std::vector<GameEntity *> entityPool;
  std::vector<GameEntity *> awaitEntitys;
  std::map<int, GameEntity *> activeEntitys;

  int starId;
  MgrEntity(Game *);
  void update();
  void draw();
  void clear();

public:
  int createEntity(int animaId, int x, int y, int w = 100, int h = 100);
  GameEntity *getEntity(int);
  void destroyEntity(int);
};