#include "../include/MgrTex.h"
#include "../include/Game.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include <iostream>

MgrTex::MgrTex(Game *game) { this->game = game; }
void MgrTex::init() { IMG_Init(IMG_INIT_PNG); }
int MgrTex::loadTexture(const std::string &file) {
  auto tex = IMG_LoadTexture(this->game->getRenderer(), file.c_str());
  if (tex == nullptr) {
    std::cout << "图片加载失败：" << IMG_GetError() << std::endl;
    return -1;
  }
  this->texs.push_back(tex);
  return this->texs.size() - 1;
}

SDL_Texture *MgrTex::getTextureById(int id) {
  if (id >= this->texs.size())
    return nullptr;
  return this->texs[id];
}

void MgrTex::clear() {
  for (auto i : this->texs) {
    SDL_DestroyTexture(i);
  }
  this->texs.clear();
}
