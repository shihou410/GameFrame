#include "../include/Actor.h"
#include "../include/Game.h"
#include <iostream>

Actor::Actor(EnumActorDirection _dir) : GameEntity(), dir(_dir) {

  this->onEnter = [this](GameEntity *Actor) -> void { this->on_enter(); };
  this->onUpdate = [this](GameEntity *Actor) -> void { this->on_update(); };
  this->onDraw = [this](GameEntity *Actor) -> void { this->on_draw(); };
  this->onDestroy = [this](GameEntity *Actor) -> void { this->on_destroy(); };
}

void Actor::on_enter() {}
void Actor::on_update() {
  Game *game = Game::getInstance();
  this->pos[0] += this->moveSpeed * this->horizontal * game->deltaTime;
  this->pos[1] += this->moveSpeed * this->vertical * game->deltaTime;
}
void Actor::on_draw() {}
void Actor::on_destroy() {
  this->onEnter = std::function<void(GameEntity *)>();
  this->onUpdate = std::function<void(GameEntity *)>();
  this->onDraw = std::function<void(GameEntity *)>();
  this->onDestroy = std::function<void(GameEntity *)>();
}
