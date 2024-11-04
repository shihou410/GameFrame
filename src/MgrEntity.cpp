#include "../include/MgrEntity.h"
#include "../include/GameEntity.h"
#include <algorithm>
MgrEntity::MgrEntity(Game *game) : starId(0) { this->game = game; }

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
      entity->update();
      item++;
    } else {
      entity->destroy();
      this->entityPool.push_back(item->second);
      item = this->activeEntitys.erase(item);
    }
  }
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