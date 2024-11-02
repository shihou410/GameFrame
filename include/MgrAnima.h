#pragma once
#include <map>
#include <vector>
class Game;
class Animation;
class SDL_Texture;
class MgrAnima {
private:
  int starId;
  std::map<int, Animation *> animas;
  friend Game;
  Game *game;
  MgrAnima(Game *);
  void clear();

public:
  int addAnima(int, std::vector<int>, int, int, float = 0.1f);
  void update();
  void playAnima(int, bool);
  void stopAnima(int);
  bool animaCompolate(int);
  bool atFrame(int, int);
  Animation *getAnima(int);
  SDL_Texture *getTexture(int);
  void removeAnima(int);
};
