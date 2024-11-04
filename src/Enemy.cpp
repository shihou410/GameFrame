#include "../include/Enemy.h"
#include "../include/Bullet.h"
#include "../include/Config.h"
#include "../include/Game.h"
#include "../include/MgrAnima.h"
#include "../include/MgrEntity.h"
#include "../include/MgrTex.h"
#include "../include/Utils.h"
#include <algorithm>
#include <cmath>
#include <vector>
Enemy::Enemy(int x, int y) : Actor(), animas(), fireCd(1) {
  auto game = Game::getInstance();
  auto mgrTex = game->mgrTex;
  auto mgrAnima = game->mgrAnima;
  auto mgrEntity = game->mgrEntity;

  int mTex = mgrTex->loadTexture(resource_url + "img/tank/enemy1.png");
  this->animas[static_cast<int>(EnumActorDirection::DIR_UP)] =
      game->mgrAnima->addAnima(mTex, {6, 7}, 64, 64, 0.3f);

  this->animas[static_cast<int>(EnumActorDirection::DIR_DOWN)] =
      game->mgrAnima->addAnima(mTex, {0, 1}, 64, 64, 0.3f);

  this->animas[static_cast<int>(EnumActorDirection::DIR_LEFT)] =
      game->mgrAnima->addAnima(mTex, {2, 3}, 64, 64, 0.3f);

  this->animas[static_cast<int>(EnumActorDirection::DIR_RIGHT)] =
      game->mgrAnima->addAnima(mTex, {4, 5}, 64, 64, 0.3f);

  this->pos[0] = x;
  this->pos[1] = y;
  this->halfSize[0] = 64 / 2.f;
  this->halfSize[1] = 64 / 2.f;
  this->dir = EnumActorDirection::DIR_DOWN;
  this->moveSpeed = 150;
  this->maxMoveCount = 10;
  this->moveCount = 0;

  mgrEntity->addEntity(this);
}

void Enemy::on_enter() { Actor::on_enter(); }
void Enemy::on_update() {
  auto game = Game::getInstance();

  this->fireCd = std::fmax(this->fireCd - game->deltaTime, 0);

  this->animaId = this->animas[static_cast<int>(this->dir)];
  game->mgrAnima->playAnima(this->animaId, true);

  switch (this->dir) {
  case EnumActorDirection::DIR_DOWN:
    this->horizontal = 0;
    this->vertical = 1;
    break;
  case EnumActorDirection::DIR_UP:
    this->horizontal = 0;
    this->vertical = -1;
    break;
  case EnumActorDirection::DIR_LEFT:
    this->horizontal = -1;
    this->vertical = 0;
    break;
  case EnumActorDirection::DIR_RIGHT:
    this->horizontal = 1;
    this->vertical = 0;
    break;
  }

  int movex = this->moveSpeed * this->horizontal * game->deltaTime;
  int movey = this->moveSpeed * this->vertical * game->deltaTime;
  this->moveCount += movex;
  this->moveCount += movey;
  this->pos[0] += movex;
  this->pos[1] += movey;

  if (this->moveCount > this->maxMoveCount) {
    this->randomDir();
    this->moveCount = 0;
  }

  if (this->fireCd <= 0) {
    this->fire();
  }

  vec2 min, max;
  vec2_sub(min, this->pos, this->halfSize);
  vec2_sub(max, this->pos, this->halfSize);
  if (min[0] < 0) {
    this->pos[0] += abs(movex);
    this->randomDir();
  }
  if (min[1] < 0) {
    this->pos[1] += abs(movey);
    this->randomDir();
  }
  if (max[0] > game->getWindowW() - this->halfSize[0]) {
    this->pos[0] += -abs(movex);
    this->randomDir();
  }
  if (max[1] > game->getWindowH() - this->halfSize[1]) {
    this->pos[0] += -abs(movex);
    this->randomDir();
  }
}
void Enemy::on_draw() { Actor::on_draw(); }
void Enemy::on_destroy() { Actor::on_destroy(); }

void Enemy::randomDir() {
  std::vector<int> temp({0, 1, 2, 3});
  int curDir = static_cast<int>(this->dir);
  temp.erase(std::remove(temp.begin(), temp.end(), curDir), temp.end());
  int randomInt = temp[Tools::random(0, temp.size() - 1)];
  this->dir = static_cast<EnumActorDirection>(randomInt);
}
void Enemy::fire() {
  auto bullet = new Bullet(this->pos[0], this->pos[1], this->dir);
  this->fireCd = Tools::random(1, 3);
}
