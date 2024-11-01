#include "../include/MgrAnima.h"
#include "../include/Animation.h"
#include "../include/Game.h"
#include <iostream>
MgrAnima::MgrAnima(Game *game) { this->game = game; }

int MgrAnima::addAnima(int texId, const int *frames, int len, float interval,
                       int w, int h) {
  auto ani = new Animation();
  this->animas.push_back(ani);
  ani->id = texId;
  for (int i = 0; i < len; i++) {
    ani->addFrame(frames[i]);
  }
  ani->width = w;
  ani->height = h;
  ani->interval = interval;
  return this->animas.size() - 1;
}

void MgrAnima::update() {
  for (auto i : this->animas)
    i->update();
}
void MgrAnima::playAnima(int index, bool loop) {
  if (index >= this->animas.size())
    return;
  auto anima = this->animas[index];
  anima->isLoop = loop;
  anima->start();
}
void MgrAnima::stopAnima(int index) {
  if (index >= this->animas.size())
    return;
  auto anima = this->animas[index];
  anima->stop();
}
bool MgrAnima::animaCompolate(int index) {
  if (index >= this->animas.size())
    return false;
  auto anima = this->animas[index];
  return true;
}
bool MgrAnima::atFrame(int index, int frame) {
  if (index >= this->animas.size())
    return false;
  auto anima = this->animas[index];
  return anima->currentFrame == anima->frames.begin() + frame;
}
Animation *MgrAnima::getAnima(int index) { return this->animas[index]; }

SDL_Texture *MgrAnima::getTexture(int aid) {
  return this->animas[aid]->getTexture();
}

void MgrAnima::clear() {
  for (auto i = this->animas.begin(); i != this->animas.end();) {
    delete *i;
    i = this->animas.erase(i);
  }
}
