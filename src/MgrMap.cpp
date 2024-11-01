#include "../include/MgrMap.h"
#include "../include/GameMap.h"

MgrMap::MgrMap(Game *game) {
  this->game = game;
  this->currentMap = this->maps.end();
  this->lastMap = this->maps.end();
}

void MgrMap::update() {
  if (this->lastMap != this->currentMap) {
    if (this->lastMap != this->maps.end()) {
      // (*this->lastMap)->end();
    }
    if (this->currentMap != this->maps.end()) {
      (*this->currentMap)->begin();
    }
    this->lastMap = this->currentMap;
  }

  if (this->currentMap != this->maps.end()) {
    (*this->currentMap)->update();
  }
}

void MgrMap::render(SDL_Renderer *gRender) {
  if (this->currentMap == this->maps.end())
    return;
  (*this->currentMap)->render(gRender);
}

void MgrMap::clear() {
  for (auto i = this->maps.begin(); i != this->maps.end();) {
    (*i)->clear();
    delete *i;
    i = this->maps.erase(i);
  }

  this->maps.clear();
}

int MgrMap::loadMap(const char *file, int texId) {
  GameMap *map = new GameMap(texId);
  map->load(file);
  this->addGameMap(map);
  return this->maps.size() - 1;
}

void MgrMap::addGameMap(GameMap *map) {
  this->maps.push_back(map);
  this->gotoMap(this->maps.size() - 1);
}

void MgrMap::goNext() {
  this->lastMap = this->currentMap;
  ++this->currentMap;
  if (this->currentMap == this->maps.end()) {
    this->currentMap = this->maps.begin();
  }
}

GameMap *MgrMap::getMap(int mapid) {
  if (mapid >= this->maps.size())
    return nullptr;
  return this->maps[mapid];
}

GameMap *MgrMap::getCurrentMap() {
  if (this->currentMap == this->maps.end())
    return nullptr;
  return *this->currentMap;
}

void MgrMap::gotoMap(int mapid) {
  this->lastMap = this->currentMap;
  this->currentMap = this->maps.begin() + mapid;
}
