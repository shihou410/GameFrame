#include "../include/Animation.h"
#include "../include/Game.h"
#include "../include/MgrTex.h"

Animation::Animation()
    : id(-1), texId(0), interval(0.f), isLoop(false), isStop(true),
      passTime(0.f), width(0), height(0) {
  this->currentFrame = this->frames.end();
}

void Animation::load(const char *file) {}

void Animation::update() {
  if (this->isStop || this->frames.empty())
    return;

  auto game = Game::getInstance();

  this->passTime += game->deltaTime;
  if (this->passTime > this->interval) {
    this->currentFrame++;
    this->passTime = 0.f;
  }

  if (this->currentFrame == this->frames.end()) {
    if (this->isLoop) {
      this->currentFrame = this->frames.begin();
    } else {
      this->currentFrame = this->frames.end() - 1;
    }
  }
}

SDL_Texture *Animation::getTexture() {
  Game *game = Game::getInstance();
  auto texture = game->mgrTex->getTextureById(this->texId);
  return texture;
}
