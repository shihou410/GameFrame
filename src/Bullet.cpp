#include "../include/Bullet.h"
#include "../include/Config.h"
#include "../include/Game.h"
#include "../include/GameCamera.h"
#include "../include/MgrAnima.h"
#include "../include/MgrEntity.h"
#include "../include/MgrInput.h"
#include "../include/MgrTex.h"
#include <iostream>
Bullet::Bullet(int x, int y, EnumActorDirection dir) : Actor(), animas() {
  this->dir = dir;

  auto game = Game::getInstance();
  auto mgrTex = game->mgrTex;
  auto mgrAnima = game->mgrAnima;
  auto mgrEntity = game->mgrEntity;

  int mTex = mgrTex->loadTexture(resource_url + "img/bullet/bullet.png");
  this->animas[static_cast<int>(EnumActorDirection::DIR_UP)] =
      game->mgrAnima->addAnima(mTex, {7}, 16, 16, 0.3f);

  this->animas[static_cast<int>(EnumActorDirection::DIR_DOWN)] =
      game->mgrAnima->addAnima(mTex, {0}, 16, 16, 0.3f);

  this->animas[static_cast<int>(EnumActorDirection::DIR_LEFT)] =
      game->mgrAnima->addAnima(mTex, {5}, 16, 16, 0.3f);

  this->animas[static_cast<int>(EnumActorDirection::DIR_RIGHT)] =
      game->mgrAnima->addAnima(mTex, {6}, 16, 16, 0.3f);

  this->pos[0] = x;
  this->pos[1] = y;
  this->halfSize[0] = 16 / 2.f;
  this->halfSize[1] = 16 / 2.f;
  this->dir = dir;
  this->moveSpeed = 350;
  mgrEntity->addEntity(this);
}
void Bullet::on_enter() {}
void Bullet::on_update() {
  Game *game = Game::getInstance();
  this->animaId = this->animas[static_cast<int>(this->dir)];
  int h = 0;
  int v = 0;

  switch (this->dir) {
  case EnumActorDirection::DIR_DOWN:
    v = 1;
    break;
  case EnumActorDirection::DIR_UP:
    v = -1;
    break;
  case EnumActorDirection::DIR_LEFT:
    h = -1;
    break;
  case EnumActorDirection::DIR_RIGHT:
    h = 1;
    break;
  }

  this->pos[0] += game->deltaTime * h * moveSpeed;
  this->pos[1] += game->deltaTime * v * moveSpeed;

  vec2 min, max;
  vec2_sub(min, this->pos, this->halfSize);
  vec2_sub(max, this->pos, this->halfSize);

  if (min[0] < 0) {
    game->mgrEntity->destroyEntity(this->id);
  }
  if (min[1] < 0) {
    game->mgrEntity->destroyEntity(this->id);
  }
  if (max[0] > game->getWindowW() - this->halfSize[0]) {
    game->mgrEntity->destroyEntity(this->id);
  }
  if (max[1] > game->getWindowH() - this->halfSize[1]) {
    game->mgrEntity->destroyEntity(this->id);
    // game->camera->playShake(6.0f);
  }
}
void Bullet::on_draw() {}
void Bullet::on_destroy() {}
