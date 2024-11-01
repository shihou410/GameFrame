#include "../include/Game.h"
#include "../include/GameCamera.h"
#include "../include/MgrAnima.h"
#include "../include/MgrEntity.h"
#include "../include/MgrInput.h"
#include "../include/MgrMap.h"
#include "../include/MgrTex.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_render.h"
Game *Game::_ins = nullptr;

Game::Game() : gRender(nullptr), gWindow(nullptr) {

  this->startTime = 0.0f;
  this->deltaTime = 0.0f;
  this->lastTime = 0.0f;
  this->gameTime = 0.0f;
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

  this->mgrMap = new MgrMap(this);
  this->mgrTex = new MgrTex(this);
  this->camera = new GameCamera(this);
  this->mgrEntity = new MgrEntity(this);
  this->mgrInput = new MgrInput(this);
  this->mgrAnima = new MgrAnima(this);

  this->startTime = SDL_GetTicks() / 1000.f;
  this->lastTime = this->startTime;
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
    }

    this->gameUpdate();

    SDL_SetRenderDrawColor(gRender, 255, 255, 255, 255);
    SDL_RenderClear(gRender);

    this->gameRender();

    SDL_RenderPresent(gRender);
  }
}

void Game::gameRender() {
  this->mgrMap->render(this->gRender);
  this->mgrEntity->draw();
}

void Game::gameUpdate() {
  this->mgrInput->update();
  this->camera->update();
  this->mgrAnima->update();
  this->mgrMap->update();
  this->mgrEntity->update();
}

void Game::gameClean() {

  this->mgrMap->clear();
  this->mgrTex->clear();
  this->mgrEntity->clear();
  this->mgrAnima->clear();
  SDL_DestroyRenderer(gRender);
  SDL_DestroyWindow(gWindow);
  SDL_Quit();

  delete Game::_ins;
}
