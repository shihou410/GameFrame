#include "../include/GameMap.h"
#include "../include/Game.h"
#include "../include/GameCamera.h"
#include "../include/MgrTex.h"
#include "../include/Utils.h"
#include <SDL2/SDL_render.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
GameMap::GameMap(int texId)
    : column(0), row(0), width(0), height(0), tilew(0), tileh(0), name(""),
      textureId(texId), scale(1) {}
GameMap::GameMap(const std::string &file, int texId)
    : column(0), row(0), width(0), height(0), tilew(0), tileh(0), name(""),
      textureId(texId), scale(1) {
  this->load(file);
}

void GameMap::load(const std::string &name) {

  std::fstream file(name);
  if (file.is_open()) {
    std::string line;

    bool isconfig = false;
    while (std::getline(file, line)) {
      if (line.empty())
        continue;
      auto title = Tools::string_strim(line);
      if (title == "[config]") {
        isconfig = true;
      }
      if (title == "[data]") {
        break;
      }
      if (!isconfig) {
        std::cout << "不是有效的配置文件：" << name << std::endl;
        break;
      } else {
        auto lineArr = Tools::string_splice(line, '=');
        if (Tools::string_strim(lineArr[0]) == "name") {
          this->name = lineArr[1];
        } else if (Tools::string_strim(lineArr[0]) == "tileW") {
          this->tilew = std::stoi(lineArr[1]);
        } else if (Tools::string_strim(lineArr[0]) == "tileH") {
          this->tileh = std::stoi(lineArr[1]);
        } else if (Tools::string_strim(lineArr[0]) == "width") {
          this->width = std::stoi(lineArr[1]);
        } else if (Tools::string_strim(lineArr[0]) == "height") {
          this->height = std::stoi(lineArr[1]);
        } else if (Tools::string_strim(lineArr[0]) == "scale") {
          this->scale = std::stoi(lineArr[1]);
        }
      }
    }

    while (std::getline(file, line)) {
      std::string s;
      std::stringstream st(line);
      if (line.empty())
        continue;
      if (line == "[animation]")
        break;
      int c = 0;
      while (std::getline(st, s, ',')) {
        this->mapdata.push_back(std::stoi(s));
        c++;
      }
      this->column = std::max(this->column, c);
      this->row++;
    }
    std::cout << name << "  加载完成。" << std::endl;
    file.close();
  } else {
    std::cout << "打开文件失败：" << name << std::endl;
  }
}

void GameMap::render(SDL_Renderer *render) {

  auto game = Game::getInstance();

  SDL_Texture *tex = game->mgrTex->getTextureById(this->textureId);
  auto camera = game->camera;

  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->column; j++) {
      int index = i * this->column + j;
      int tile = this->mapdata[index];

      int tw = this->tilew * (int)this->scale;
      int th = this->tileh * (int)this->scale;

      SDL_Rect srcrect = {tile * (int)this->tilew, 0, (int)this->tilew,
                          (int)this->tileh};
      SDL_Rect dstrect = {j * tw - camera->x, i * th - camera->y, tw, th};
      SDL_RenderCopy(render, tex, &srcrect, &dstrect);
    }
  }
}

void GameMap::begin() { std::cout << this->name << "begin();" << std::endl; }
void GameMap::update() {
  // std::cout << this->name << "update();" << std::endl;
}
void GameMap::end() { std::cout << this->name << "end();" << std::endl; }
void GameMap::clear() {
  this->mapdata.clear();
  std::cout << this->name << "clear();" << std::endl;
}
