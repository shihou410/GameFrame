#include "../include/MgrEntity.h"
#include "../include/GameEntity.h"
#include <algorithm>
#include <iostream>
#include <string>
MgrEntity::MgrEntity(Game *game) : starId(0) { this->game = game; }

void MgrEntity::initGrid(int w, int h) {
  this->gw = w;
  this->gh = h;
}

void MgrEntity::update() {

  for (auto &item : this->awaitEntitys) {
    item->active = true;
    item->enter();
    this->activeEntitys[item->id] = item;
  }
  this->awaitEntitys.clear();
  for (auto item = this->activeEntitys.begin();
       item != this->activeEntitys.end();) {
    auto entity = item->second;

    if (entity->active) {
      this->addEntityToGrid(entity);
      item++;
    } else {
      entity->destroy();
      this->entityPool.push_back(item->second);
      item = this->activeEntitys.erase(item);
    }
  }
  for (auto item : this->activeEntitys) {
    auto entity = item.second;
    entity->update();
  }

  this->removeEntityFromGrid();
}

void MgrEntity::draw() {
  for (auto item : this->activeEntitys) {
    auto entity = item.second;
    if (entity->active)
      entity->draw();
  }
}

int MgrEntity::createEntity(int animaId, int x, int y, int w, int h) {

  GameEntity *entity = nullptr;
  if (this->entityPool.empty()) {
    entity = new GameEntity();
  } else {
    entity = this->entityPool.back();
    this->entityPool.pop_back();
  }

  entity->animaId = animaId;
  entity->pos[0] = x;
  entity->pos[1] = y;
  entity->halfSize[0] = w / 2.f;
  entity->halfSize[1] = h / 2.f;

  return this->addEntity(entity);
}

int MgrEntity::addEntity(GameEntity *entity) {
  entity->active = true;
  entity->id = this->starId;
  this->awaitEntitys.push_back(entity);
  this->starId++;
  return entity->id;
}

GameEntity *MgrEntity::getEntity(int id) {
  if (this->activeEntitys.count(id) > 0)
    return this->activeEntitys[id];

  for (auto item : this->awaitEntitys) {
    if (item->id == id) {
      return item;
    }
  }

  return nullptr;
}

void MgrEntity::destroyEntity(int id) {
  if (this->activeEntitys.count(id) <= 0)
    return;
  this->activeEntitys[id]->active = false;
}

void MgrEntity::clear() {
  for (auto item : this->activeEntitys) {
    delete item.second;
  }
  for (auto item = this->entityPool.begin(); item != this->entityPool.end();) {
    delete *item;
    item = this->entityPool.erase(item);
  }
  this->activeEntitys.clear();
  this->entityPool.clear();
}

void MgrEntity::addEntityToGrid(GameEntity *entity) {
  auto x = std::to_string(static_cast<int>(entity->pos[0] / this->gw));
  auto y = std::to_string(static_cast<int>(entity->pos[1] / this->gh));
  auto key = x + y;
  this->data[key].push_back(entity);
}

std::vector<GameEntity *> &MgrEntity::getEntityFromGrid(GameEntity *entity) {
  auto x = std::to_string(static_cast<int>(entity->pos[0] / this->gw));
  auto y = std::to_string(static_cast<int>(entity->pos[1] / this->gh));
  auto key = x + y;
  return this->data[key];
}

void MgrEntity::removeEntityFromGrid() {
  for (auto item : this->data) {
    item.second.clear();
  }
  this->data.clear();
}
