#pragma once

#include "./GameMap.h"
#include "SDL2/SDL_rect.h"
#include <iostream>
#include <vector>
typedef SDL_Rect Camera;

class SDL_Texture;
class SDL_Window;
class SDL_Renderer;
class Game {
  std::vector<GameMap *> maps;
  std::vector<SDL_Texture *> textures;

  SDL_Window *gWindow;
  SDL_Renderer *gRender;

  bool isExit;
  unsigned int width;
  unsigned int height;

  float FPS = 0.016f;

  Camera camera;

  float shake_leng = 60.f;
  int shake_magnitude = 6;
  float shake_remain = 6.f;

public:
  void init(int, int);
  uint loadTexture(const char *);
  static Game *getInstance();
  void gameRun();
  void gameUpdate();
  void gameClean();
  void gameRender();

  inline SDL_Texture *getTextureById(uint id) {
    if (id >= this->textures.size())
      return nullptr;
    return this->textures[id];
  }
  inline SDL_Renderer *getRenderer() const { return this->gRender; }

  //------------------相机相关
  inline Camera &getCamera() { return this->camera; }
  void updateCamera();

  //------------------时间相关
  float startTime;
  float deltaTime;
  float lastTime;
  float gameTime;

  //------------------游戏地图相关
private:
  std::vector<GameMap *>::iterator currentMap;
  std::vector<GameMap *>::iterator lastMap;

public:
  void drawMap();
  void updateMap();

  inline void goNext() {
    std::cout << "下一个地图" << std::endl;
    this->lastMap = this->currentMap;
    ++this->currentMap;
    if (this->currentMap == this->maps.end()) {
      this->currentMap = this->maps.begin();
    }
  }

  inline GameMap *getMap(uint mapid) {
    if (mapid >= this->maps.size())
      return nullptr;
    return this->maps[mapid];
  }

  inline uint createGameMap(const char *name) {
    GameMap *map = new GameMap();
    map->load(name);
    this->addGameMap(map);
    // std::cout << "添加地图：" << map->name << std::endl;
    return this->maps.size() - 1;
  }

  inline void addGameMap(GameMap *map) {
    this->maps.push_back(map);
    this->gotoMap(this->maps.size() - 1);
  }

  inline GameMap *getCurrentMap() const {
    if (this->currentMap == this->maps.end())
      return nullptr;
    return *this->currentMap;
  }

  inline void gotoMap(uint mapid) {
    this->lastMap = this->currentMap;
    this->currentMap = this->maps.begin() + mapid;
    // std::cout << "gotu: " << (*this->currentMap)->name << std::endl;
  }

private:
  Game();
  static Game *_ins;
};
