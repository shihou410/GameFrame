#pragma once
#include <vector>
class Game;
class Animation;
class SDL_Texture;
class MgrAnima {
private:
  std::vector<Animation *> animas;
  friend Game;
  Game *game;
  MgrAnima(Game *);
  void clear();

public:
  int addAnima(int, const int *, int, float, int, int);
  void update();
  void playAnima(int, bool);
  void stopAnima(int);
  bool animaCompolate(int);
  bool atFrame(int, int);
  Animation *getAnima(int);
  SDL_Texture *getTexture(int);
};
