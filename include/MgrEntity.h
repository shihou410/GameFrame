#pragma once
#include <map>
#include <string>
#include <vector>

class Game;
class GameEntity;
class MgrEntity {
private:
  int gw, gh;

  friend Game;
  Game *game;
  std::vector<GameEntity *> entityPool;
  std::vector<GameEntity *> awaitEntitys;
  std::map<int, GameEntity *> activeEntitys;

  std::map<std::string, std::vector<GameEntity *>> data;

  int starId;
  MgrEntity(Game *);
  void initGrid(int, int);
  void update();
  void draw();
  void clear();

  void addEntityToGrid(GameEntity *);
  void removeEntityFromGrid();

public:
  int createEntity(int animaId, int x, int y, int w = 100, int h = 100);
  int addEntity(GameEntity *);
  GameEntity *getEntity(int);
  void destroyEntity(int);

  std::vector<GameEntity *> &getEntityFromGrid(GameEntity *);
};