#include "../include/MgrAnima.h"
#include "../include/Animation.h"
#include "../include/Game.h"
#include <iostream>
MgrAnima::MgrAnima(Game *game) : starId(0) { this->game = game; }

int MgrAnima::addAnima(int texId, std::vector<int> frames, int w, int h,
                       float interval) {
  auto anima = new Animation();
  anima->id = this->starId;
  anima->texId = texId;
  int len = frames.size();
  for (int i = 0; i < len; i++) {
    anima->addFrame(frames[i]);
  }
  anima->width = w;
  anima->height = h;
  anima->interval = interval;
  this->animas[this->starId] = anima;
  this->starId++;
  return anima->id;
}

void MgrAnima::update() {
  for (auto item : this->animas) {
    item.second->update();
  }
}
void MgrAnima::playAnima(int id, bool loop) {
  if (this->animas.count(id) <= 0)
    return;
  auto anima = this->animas[id];
  anima->isLoop = loop;
  anima->start();
}
void MgrAnima::stopAnima(int id) {
  if (this->animas.count(id) <= 0)
    return;
  auto anima = this->animas[id];
  anima->stop();
}
bool MgrAnima::animaCompolate(int id) {
  if (this->animas.count(id) <= 0)
    return false;
  auto anima = this->animas[id];

  return anima->currentFrame == anima->frames.end() - 1;
}
bool MgrAnima::atFrame(int id, int frame) {
  if (this->animas.count(id) <= 0)
    return false;
  auto anima = this->animas[id];
  return anima->currentFrame == anima->frames.begin() + frame;
}
Animation *MgrAnima::getAnima(int id) {
  if (this->animas.count(id) <= 0)
    return nullptr;

  return this->animas[id];
}

SDL_Texture *MgrAnima::getTexture(int id) {
  if (this->animas.count(id) <= 0)
    return nullptr;
  return this->animas[id]->getTexture();
}
void MgrAnima::removeAnima(int id) {
  if (this->animas.count(id) <= 0)
    return;

  delete this->animas[id];
  this->animas.erase(id);
}
void MgrAnima::clear() {
  for (auto item = this->animas.begin(); item != this->animas.end();) {
    delete item->second;
    item = this->animas.erase(item);
  }
  this->animas.clear();
}
