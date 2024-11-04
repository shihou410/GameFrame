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
  int texId;

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
  inline void addFrame(int f) {
    this->frames.push_back(f);
    this->currentFrame = this->frames.begin();
  };
  inline void start() { this->isStop = false; }
  inline void stop() { this->isStop = true; };
  inline int getSize() const { return this->frames.size(); }
  inline int getCurrentFrame() const {
    if (this->currentFrame == this->frames.end()) {
      return this->frames[0];
    }
    return *this->currentFrame;
  }
  inline int getWidth() const { return this->width; }
  inline int getHeight() const { return this->height; }
  SDL_Texture *getTexture();
};
