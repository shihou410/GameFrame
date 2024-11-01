#include "../include/GameCamera.h"
#include "../include/Game.h"
#include "../include/GameMap.h"
#include "../include/MgrMap.h"
#include "../include/Utils.h"
#include <algorithm>
GameCamera::GameCamera(Game *game) : x(0), y(0), w(0), h(0) {
  this->game = game;
  this->shake_leng = 60.f;
  this->shake_magnitude = 6.f;
  this->shake_remain = 0.f;

  this->w = game->getWindowW();
  this->h = game->getWindowH();
}

void GameCamera::playShake(float reman) { this->shake_remain = reman; }

void GameCamera::update() {

  auto currentMap = this->game->mgrMap->getCurrentMap();

  if (currentMap != nullptr) {
    int mapw = currentMap->getMapWidth();
    int maph = currentMap->getMapHeight();

    int cameraWidth = this->w;
    int cameraHeight = this->h;

    // this->x = std::clamp(this->x, 0, mapw - cameraWidth);
    // this->y = std::clamp(this->y, 0, maph - cameraHeight);
  }

  if (this->shake_remain > 0) {
    this->x = Tools::random(-this->shake_remain, this->shake_remain);
    this->y = Tools::random(-this->shake_remain, this->shake_remain);
    this->shake_remain = std::max<float>(
        0, this->shake_remain - (1.f / this->shake_leng) * shake_magnitude);
  }
}
