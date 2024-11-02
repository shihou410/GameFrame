#include "./include/Game.h"
#include "./include/GameEntity.h"
#include "./include/MgrAnima.h"
#include "./include/MgrEntity.h"
#include "./include/MgrInput.h"
#include "./include/MgrMap.h"
#include "./include/MgrTex.h"
#include "./include/Utils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const std::string imgBase = "/root/myGame/GameFrame/res/img/";
const std::string mapBase = "/root/myGame/GameFrame/res/map/";

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int pa_up = -1;
int pa_down = -1;
int pa_left = -1;
int pa_right = -1;

int ba_up = -1;
int ba_down = -1;
int ba_left = -1;
int ba_right = -1;

float fireCd = 1;

void createBullet(int, int, int);

void playerUpDate(GameEntity *);
void bulletUpdate(GameEntity *);

int main(int, char **) {

  Game *game = Game::getInstance();
  game->init(WINDOW_WIDTH, WINDOW_HEIGHT);
  auto mgrTex = game->mgrTex;
  auto mgrEntity = game->mgrEntity;

  int mapTex = mgrTex->loadTexture(imgBase + "tile/map.png");
  int boomTex = mgrTex->loadTexture(imgBase + "boom.png");
  int playerTex = game->mgrTex->loadTexture(imgBase + "tank/player1.png");
  int bulletTex = game->mgrTex->loadTexture(imgBase + "bullet/bullet.png");

  int mapId = game->mgrMap->loadMap(mapBase + "map1", mapTex);

  // const int frames[5] = {0, 1, 2, 3, 4};
  // int boomAni = game->mgrAnima->addAnima(boomTex, frames, 5, 0.1f, 128, 128);

  pa_up = game->mgrAnima->addAnima(playerTex, {6, 7}, 64, 64, 0.3f);
  pa_down = game->mgrAnima->addAnima(playerTex, {0, 1}, 64, 64, 0.3f);
  pa_left = game->mgrAnima->addAnima(playerTex, {2, 3}, 64, 64, 0.3f);
  pa_right = game->mgrAnima->addAnima(playerTex, {4, 5}, 64, 64, 0.3f);

  game->mgrAnima->playAnima(pa_up, true);
  game->mgrAnima->playAnima(pa_down, true);
  game->mgrAnima->playAnima(pa_left, true);
  game->mgrAnima->playAnima(pa_right, true);

  const int b_down = 0;
  const int b_up = 8;
  const int b_left = 6;
  const int b_right = 7;
  ba_up = game->mgrAnima->addAnima(bulletTex, {8}, 16, 16, 0.3f);
  ba_down = game->mgrAnima->addAnima(bulletTex, {0}, 16, 16, 0.3f);
  ba_left = game->mgrAnima->addAnima(bulletTex, {6}, 16, 16, 0.3f);
  ba_right = game->mgrAnima->addAnima(bulletTex, {7}, 16, 16, 0.3f);

  game->mgrAnima->playAnima(ba_up, true);
  game->mgrAnima->playAnima(ba_down, true);
  game->mgrAnima->playAnima(ba_left, true);
  game->mgrAnima->playAnima(ba_right, true);

  float rx = Tools::random(50, 300);
  float ry = Tools::random(50, 300);
  int p_Id = mgrEntity->createEntity(pa_up, rx, ry, 64, 64);
  auto player = mgrEntity->getEntity(p_Id);

  player->onUpdate = playerUpDate;

  game->gameRun();
  game->gameClean();

  return 0;
}

void playerUpDate(GameEntity *player) {
  Game *game = Game::getInstance();
  fireCd = std::fmax(fireCd - game->deltaTime, 0);

  auto input = game->mgrInput;
  if (input->check_keyboard(k_a)) {
    player->pos[0] -= 130 * game->deltaTime;
    player->setAnimaId(pa_left);
  } else if (input->check_keyboard(k_d)) {
    player->pos[0] += 130 * game->deltaTime;
    player->setAnimaId(pa_right);
  } else if (input->check_keyboard(k_w)) {
    player->pos[1] -= 130 * game->deltaTime;
    player->setAnimaId(pa_up);
  } else if (input->check_keyboard(k_s)) {
    player->pos[1] += 130 * game->deltaTime;
    player->setAnimaId(pa_down);
  }
  if (input->check_keyboard(k_space)) {
    if (fireCd == 0) {
      fireCd = 1;
      createBullet(player->pos[0], player->pos[1], ba_down);
    }
  }
}

void createBullet(int x, int y, int animaId) {
  Game *game = Game::getInstance();
  int id = game->mgrEntity->createEntity(animaId, x, y, 16, 16);
  auto bullet = game->mgrEntity->getEntity(id);
  game->mgrAnima->playAnima(animaId, true);
  bullet->onUpdate = bulletUpdate;
}

void bulletUpdate(GameEntity *bullet) {
  Game *game = Game::getInstance();
  bullet->pos[0] += 560 * game->deltaTime;

  if (bullet->pos[0] < 0 || bullet->pos[0] > game->getWindowW()) {
    game->mgrEntity->destroyEntity(bullet->getId());
  }
}
