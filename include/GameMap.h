#pragma once
#include <string>
#include <vector>
class SDL_Renderer;

class MgrMap;
class GameMap {

  friend MgrMap;

  std::vector<uint> mapdata;
  uint width, height, tilew, tileh, scale;
  uint textureId;

public:
  std::string name;

  GameMap(int);
  GameMap(const std::string &, int);

  void load(const std::string &path);
  void render(SDL_Renderer *);

  void begin();
  void update();
  void end();
  void clear();

  inline int getMapWidth() const { return this->width; }
  inline int getMapHeight() const { return this->height; }

private:
  int column;
  int row;

  void loadTexture(const char *);
};
