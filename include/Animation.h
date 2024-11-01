#pragma once
#include <vector>
class MgrAnima;
class SDL_Texture;
class Animation {
private:
  friend MgrAnima;
  std::vector<int> frames;
  std::vector<int>::iterator currentFrame;

  int id;
  float interval;
  bool isLoop;
  bool isStop;

  Animation();

  float passTime;
  int width;
  int height;

public:
  inline int getTid() const { return this->id; }
  void load(const char *);
  void update();
  inline void addFrame(int f) { this->frames.push_back(f); };
  inline void start() {
    if (this->frames.empty())
      return;
    this->isStop = false;
    this->currentFrame = this->frames.end();
  }
  inline void stop() { this->isStop = true; };
  inline int getSize() const { return this->frames.size(); }
  inline int getCurrentFrame() const {
    return this->currentFrame - this->frames.begin();
  }
  inline int getWidth() const { return this->width; }
  inline int getHeight() const { return this->height; }
  SDL_Texture *getTexture();
};
