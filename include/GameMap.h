#pragma once
#include <cstddef>
#include <string>
#include <sys/types.h>
#include <vector>
class SDL_Renderer;

class GameMap {
  std::vector<uint> mapdata;

  uint width, height, tilew, tileh,scale;
  std::string imgSrc;
  uint textureId;

public:
  std::string name;

  GameMap();
  GameMap(const char *);

  void load(const char *path);
  void render(SDL_Renderer *);

  void begin();
  void update();
  void end();
  void clear();

private:
  int column;
  int row;

  void loadTexture(const char *);
};
