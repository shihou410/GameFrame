#include "../include/Game.h"
#include "../include/Utils.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_render.h"
#include <algorithm>
#include <iostream>
Game *Game::_ins = nullptr;

Game::Game() : gRender(nullptr), gWindow(nullptr), camera({0, 0, 0, 0}) {

  this->startTime = 0.0f;
  this->deltaTime = 0.0f;
  this->lastTime = 0.0f;
  this->gameTime = 0.0f;

  this->currentMap = this->maps.end();
  this->lastMap = this->maps.end();
}

Game *Game::getInstance() {
  if (Game::_ins == nullptr) {
    Game::_ins = new Game();
  }
  return Game::_ins;
}

void Game::init(int w, int h) {
  this->width = w;
  this->height = h;
  SDL_Init(SDL_INIT_EVENTS);
  this->gWindow =
      SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       this->width, this->height, SDL_WINDOW_SHOWN);
  if (this->gWindow == nullptr) {
    SDL_Log("窗口创建失败: %s", SDL_GetError());
    return;
  }
  this->gRender = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
  if (this->gRender == nullptr) {
    SDL_Log("渲染器创建失败: %s", SDL_GetError());
    return;
  }

  IMG_Init(IMG_INIT_PNG);
  this->camera.w = w;
  this->camera.h = h;

  this->startTime = SDL_GetTicks() / 1000.f;
  this->lastTime = this->startTime;
}

uint Game::loadTexture(const char *name) {
  SDL_Texture *tex = IMG_LoadTexture(this->gRender, name);
  if (tex == nullptr) {
    SDL_Log("图片加载失败: %s", IMG_GetError());
    return -1;
  }
  this->textures.push_back(tex);
  return this->textures.size() - 1;
}

void Game::gameRun() {
  while (!this->isExit) {

    float currentTime = SDL_GetTicks() / 1000.f;
    float passTime = currentTime - this->lastTime;

    if (passTime < FPS) {
      SDL_Delay(static_cast<Uint32>((FPS - passTime) * 1000));
      continue;
    }
    this->deltaTime = passTime;
    this->lastTime = currentTime;
    this->gameTime = currentTime - this->startTime;

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        this->isExit = true;
      }
      if (e.type == SDL_KEYDOWN) {
        this->goNext();
        if (e.key.keysym.sym == SDLK_a) {
          this->camera.x -= 10;
        }
        if (e.key.keysym.sym == SDLK_d) {
          this->camera.x += 10;
        }
      }
    }

    this->gameUpdate();

    SDL_SetRenderDrawColor(gRender, 255, 255, 255, 255);
    SDL_RenderClear(gRender);

    this->gameRender();

    SDL_RenderPresent(gRender);
  }
}

void Game::gameRender() { this->drawMap(); }

void Game::drawMap() {
  if (this->currentMap == this->maps.end())
    return;
  (*this->currentMap)->render(this->gRender);
}

void Game::gameUpdate() {
  this->updateCamera();
  this->updateMap();
}
void Game::updateCamera() {
  this->camera.x = Tools::random(-this->shake_remain, this->shake_remain);
  this->camera.y = Tools::random(-this->shake_remain, this->shake_remain);
  this->shake_remain = std::max<float>(
      0, this->shake_remain - (1.f / this->shake_leng) * shake_magnitude);
}

void Game::updateMap() {
  if (this->lastMap != this->currentMap) {
    if (this->lastMap != this->maps.end()) {
      (*this->lastMap)->end();
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

void Game::gameClean() {

  for (auto i = this->maps.begin(); i != this->maps.end();) {
    (*i)->clear();
    delete *i;
    i = this->maps.erase(i);
  }

  this->maps.clear();
  for (auto texture : this->textures) {
    SDL_DestroyTexture(texture);
  }
  this->textures.clear();

  SDL_DestroyRenderer(gRender);
  SDL_DestroyWindow(gWindow);
  SDL_Quit();

  delete Game::_ins;
}
