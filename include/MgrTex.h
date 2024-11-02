
#include <string>
#include <vector>
class Game;
class SDL_Texture;
class SDL_Renderer;

class MgrTex {
  friend Game;
  Game *game;

private:
  std::vector<SDL_Texture *> texs;

  MgrTex(Game *);
  void init();
  void clear();

public:
  int loadTexture(const std::string &);
  SDL_Texture *getTextureById(int id);
};
