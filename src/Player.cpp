#include "../include/Player.h"
#include "../include/Bullet.h"
#include "../include/Config.h"
#include "../include/Game.h"
#include "../include/MgrAnima.h"
#include "../include/MgrEntity.h"
#include "../include/MgrInput.h"
#include "../include/MgrTex.h"

#include "iostream"
#include <algorithm>

Player::Player(int x, int y) : Actor(), animas(), fireCd(0.2) {
  auto game = Game::getInstance();
  auto mgrTex = game->mgrTex;
  auto mgrAnima = game->mgrAnima;
  auto mgrEntity = game->mgrEntity;

  int mTex = mgrTex->loadTexture(resource_url + "img/tank/player1.png");
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
  mgrEntity->addEntity(this);
}

void Player::on_enter() { Actor::on_enter(); }
void Player::on_update() {
  auto game = Game::getInstance();

  this->fireCd = std::fmax(this->fireCd - game->deltaTime, 0);

  this->animaId = this->animas[static_cast<int>(this->dir)];
  game->mgrAnima->playAnima(this->animaId, true);
  if (game->mgrInput->check_keyboard(k_up)) {
    this->dir = EnumActorDirection::DIR_UP;
    this->vertical = -1;
    this->horizontal = 0;
  } else if (game->mgrInput->check_keyboard(k_down)) {
    this->dir = EnumActorDirection::DIR_DOWN;
    this->vertical = 1;
    this->horizontal = 0;
  } else if (game->mgrInput->check_keyboard(k_left)) {
    this->dir = EnumActorDirection::DIR_LEFT;
    this->vertical = 0;
    this->horizontal = -1;
  } else if (game->mgrInput->check_keyboard(k_right)) {
    this->dir = EnumActorDirection::DIR_RIGHT;
    this->horizontal = 1;
    this->vertical = 0;
  } else {
    game->mgrAnima->stopAnima(this->animaId);
    this->horizontal = 0;
    this->vertical = 0;
  }

  if (game->mgrInput->check_keyboard(k_space) && this->fireCd == 0) {
    this->fire();
  }

  Actor::on_update();
}
void Player::on_draw() { Actor::on_draw(); }
void Player::on_destroy() { Actor::on_destroy(); }

void Player::fire() {
  auto bullet = new Bullet(this->pos[0], this->pos[1], this->dir);
  this->fireCd = 0.2;
}
