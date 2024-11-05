#include "../include/Config.h"
#include "./include/Enemy.h"
#include "./include/Game.h"
#include "./include/GameEntity.h"
#include "./include/MgrAnima.h"
#include "./include/MgrEntity.h"
#include "./include/MgrInput.h"
#include "./include/MgrMap.h"
#include "./include/MgrTex.h"
#include "./include/Player.h"
#include "./include/Utils.h"
#include "iostream"
#include <cstdlib>
#include <string>
#include <vector>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int, char **) {
  Game *game = Game::getInstance();
  game->init(WINDOW_WIDTH, WINDOW_HEIGHT);
  auto mgrTex = game->mgrTex;
  auto mgrEntity = game->mgrEntity;

  int mapTex = mgrTex->loadTexture(resource_url + "img/tile/map.png");
  int boomTex = mgrTex->loadTexture(resource_url + "boom.png");

  int mapId = game->mgrMap->loadMap(resource_url + "map/map1", mapTex);

  float rx = Tools::random(50, 300);
  float ry = Tools::random(50, 300);

  auto player = new Player(rx, ry);
  auto enemy = new Enemy(200, 200);
  // auto enemy1 = new Enemy(200, 200);
  // auto enemy2 = new Enemy(200, 200);

  game->gameRun();
  game->gameClean();

  return 0;
}
