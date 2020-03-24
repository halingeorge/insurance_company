#include "game.h"

void Game::SetOptions(GameOptions options) {
    options_ = std::move(options);
}
