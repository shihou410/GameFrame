#include "../include/MgrInput.h"
#include "SDL2/SDL_keyboard.h"
#include "SDL2/SDL_scancode.h"

MgrInput::MgrInput(Game *game) : state() { this->game = game; }

void MgrInput::update() {
  const Uint8 *state = SDL_GetKeyboardState(NULL);

  this->state[k_a] = state[SDL_SCANCODE_A];
  this->state[k_d] = state[SDL_SCANCODE_D];
  this->state[k_s] = state[SDL_SCANCODE_S];
  this->state[k_w] = state[SDL_SCANCODE_W];
  this->state[k_left] = state[SDL_SCANCODE_LEFT];
  this->state[k_right] = state[SDL_SCANCODE_RIGHT];
  this->state[k_up] = state[SDL_SCANCODE_UP];
  this->state[k_down] = state[SDL_SCANCODE_DOWN];
  this->state[k_space] = state[SDL_SCANCODE_SPACE];
}

bool MgrInput::check_keyboard(KeyBoard key) { return this->state[key]; }
