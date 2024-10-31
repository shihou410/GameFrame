#include "./include/Game.h"
#include "include/GameMap.h"
#include "include/Utils.h"
#include <iostream>
const int WINDOW_WIDTH = 450;
const int WINDOW_HEIGHT = 320;

int main(int, char **) {

  Game *game = Game::getInstance();
  game->init(WINDOW_WIDTH, WINDOW_HEIGHT);
  uint map1 = game->createGameMap("/root/myGame/GameFrame/map/map1");
  uint map2 = game->createGameMap("/root/myGame/GameFrame/map/map2");
  uint map3 = game->createGameMap("/root/myGame/GameFrame/map/map3");

  game->gotoMap(map1);
  game->gameRun();
  game->gameClean();

  return 0;
}
