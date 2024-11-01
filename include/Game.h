#pragma once

class SDL_Window;
class SDL_Renderer;

class MgrTex;
class MgrMap;
class GameCamera;
class MgrEntity;
class MgrInput;
class MgrAnima;

class Game {
public:
  MgrTex *mgrTex;
  MgrMap *mgrMap;
  GameCamera *camera;
  MgrEntity *mgrEntity;
  MgrInput *mgrInput;
  MgrAnima *mgrAnima;

private:
  SDL_Window *gWindow;
  SDL_Renderer *gRender;

  bool isExit;
  unsigned int width;
  unsigned int height;

  float FPS = 0.016f;

public:
  inline unsigned int getWindowW() const { return this->width; }
  inline unsigned int getWindowH() const { return this->height; }

  void init(int, int);
  static Game *getInstance();
  void gameRun();
  void gameUpdate();
  void gameClean();
  void gameRender();

  inline SDL_Renderer *getRenderer() const { return this->gRender; }

  //------------------时间相关
  float startTime;
  float deltaTime;
  float lastTime;
  float gameTime;

private:
  Game();
  static Game *_ins;
};
