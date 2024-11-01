#include "../include/GameEntity.h"
#include "../include/Animation.h"
#include "../include/Game.h"
#include "../include/MgrAnima.h"
#include "../include/MgrTex.h"
#include "../include/linmath.h"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"

GameEntity::GameEntity()
    : active(false), lastState(false), pos(), halfSize(), animaId(-1) {}

void GameEntity::enter() {
  if (this->onEnter) {
    this->onEnter(this);
  }
}
void GameEntity::update() {
  if (this->onUpdate) {
    this->onUpdate(this);
  }
}
void GameEntity::draw() {
  Game *game = Game::getInstance();
  if (this->animaId < 0) {
    SDL_SetRenderDrawColor(game->getRenderer(), 255, 0, 0, 255);
    vec2 min;
    vec2_sub(min, this->pos, this->halfSize);
    SDL_FRect rect = {min[0], min[1], this->halfSize[0] * 2,
                      this->halfSize[1] * 2};

    SDL_RenderFillRectF(game->getRenderer(), &rect);
  } else {
    auto texture = game->mgrAnima->getTexture(this->animaId);
    auto anima = game->mgrAnima->getAnima(this->animaId);
    int width = anima->getWidth();
    int height = anima->getHeight();

    int index = anima->getCurrentFrame();
    vec2 min;
    vec2_sub(min, this->pos, this->halfSize);
    SDL_Rect srcrect = {index * width, 0, width, height};
    SDL_FRect dstrect = {min[0], min[1], this->halfSize[0] * 2,
                         this->halfSize[1] * 2};

    SDL_RenderCopyF(game->getRenderer(), texture, &srcrect, &dstrect);
  }

  if (this->onDraw) {
    this->onDraw(this);
  }
}
void GameEntity::destroy() {
  if (this->onDestroy) {
    this->onDestroy(this);
  }
}
