#pragma once
#include <SDL2/SDL_stdinc.h>

enum KeyBoard {
  k_left = 0,
  k_right,
  k_up,
  k_down,
  k_w,
  k_s,
  k_a,
  k_d,
  k_space,
};

class Game;
class MgrInput {
private:
  friend Game;
  Game *game;
  Uint8 state[9];

  MgrInput(Game *);
  void update();

public:
  bool check_keyboard(KeyBoard);
};
