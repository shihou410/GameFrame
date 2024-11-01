#include "./include/Game.h"
#include "./include/GameEntity.h"
#include "./include/MgrAnima.h"
#include "./include/MgrEntity.h"
#include "./include/MgrInput.h"
#include "./include/MgrMap.h"
#include "./include/MgrTex.h"
#include "./include/Utils.h"
#include <iostream>
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int, char **) {

  Game *game = Game::getInstance();
  game->init(WINDOW_WIDTH, WINDOW_HEIGHT);

  int mapTex =
      game->mgrTex->loadTexture("/root/myGame/GameFrame/res/img/tile/map.png");

  int boomTex =
      game->mgrTex->loadTexture("/root/myGame/GameFrame/res/img/boom.png");

  int map3 =
      game->mgrMap->loadMap("/root/myGame/GameFrame/res/map/map3", mapTex);
  int map2 =
      game->mgrMap->loadMap("/root/myGame/GameFrame/res/map/map2", mapTex);
  int map1 =
      game->mgrMap->loadMap("/root/myGame/GameFrame/res/map/map1", mapTex);
  const int frames[5] = {0, 1, 2, 3, 4};
  int boomAni = game->mgrAnima->addAnima(boomTex, frames, 5, 0.1f, 128, 128);

  game->mgrAnima->playAnima(boomAni, true);

  int playerId = game->mgrEntity->createEntity(boomAni, Tools::random(50, 300),
                                               Tools::random(50, 300));

  auto player = game->mgrEntity->getEntity(playerId);
  player->onUpdate = [&game](GameEntity *player) -> void {
    auto input = game->mgrInput;
    if (input->check_keyboard(k_a)) {
      player->pos[0] -= 130 * game->deltaTime;
    }
    if (input->check_keyboard(k_d)) {
      player->pos[0] += 130 * game->deltaTime;
    }

    if (input->check_keyboard(k_w)) {
      player->pos[1] -= 130 * game->deltaTime;
    }
    if (input->check_keyboard(k_s)) {
      player->pos[1] += 130 * game->deltaTime;
    }
  };

  game->gameRun();
  game->gameClean();

  return 0;
}
