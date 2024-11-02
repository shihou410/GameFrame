#pragma once

#include <string>
#include <vector>
class Game;
class GameMap;
class SDL_Renderer;
class MgrMap {
  std::vector<GameMap *> maps;
  std::vector<GameMap *>::iterator currentMap;
  std::vector<GameMap *>::iterator lastMap;

  Game *game;
  friend Game;

private:
  MgrMap(Game *);
  void update();
  void render(SDL_Renderer *);
  void clear();

public:
  int loadMap(const std::string &, int);
  void addGameMap(GameMap *);
  void goNext();
  GameMap *getMap(int);
  GameMap *getCurrentMap();
  void gotoMap(int);
};
