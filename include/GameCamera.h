#pragma once

class Game;
class GameCamera {
  friend Game;
  Game *game;

  float shake_leng;
  float shake_magnitude;
  float shake_remain;

private:
  GameCamera(Game *);
  void update();

public:
  int x, y, w, h;
  void playShake(float);
};
