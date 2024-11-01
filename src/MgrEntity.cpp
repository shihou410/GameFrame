#include "../include/MgrEntity.h"
#include "../include/GameEntity.h"
MgrEntity::MgrEntity(Game *game) { this->game = game; }

void MgrEntity::update() {
  for (auto e : this->entitys) {
    if (e->active) {
      e->update();
    }

    if (e->lastState != e->active) {
      if (e->active) {
        e->enter();
      } else {
        e->destroy();
      }
      e->lastState = e->active;
    }
  }
}
void MgrEntity::draw() {
  for (auto e : this->entitys) {
    if (e->active)
      e->draw();
  }
}

int MgrEntity::createEntity(int animaId, int x, int y, int w, int h) {

  GameEntity *e = nullptr;
  int index = -1;

  for (size_t i = 0; i < this->entitys.size(); ++i) {
    if (!this->entitys[i]->active) {
      e = this->entitys[i];
      index = i;
      break;
    }
  }

  if (!e) {
    e = new GameEntity();
    this->entitys.push_back(e);
    index = this->entitys.size() - 1;
  }

  e->animaId = animaId;
  e->pos[0] = x;
  e->pos[1] = y;
  e->halfSize[0] = w / 2.f;
  e->halfSize[1] = h / 2.f;
  e->active = true;

  return index;
}

GameEntity *MgrEntity::getEntity(int index) {
  if (index >= this->entitys.size())
    return nullptr;
  return *(this->entitys.begin() + index);
}

void MgrEntity::destroyEntity(int index) {
  if (index >= this->entitys.size())
    return;
  auto e = this->entitys[index];
  e->active = false;
}

void MgrEntity::clear() {
  for (auto e = this->entitys.begin(); e != this->entitys.end();) {
    delete *e;
    e = this->entitys.erase(e);
  }
}