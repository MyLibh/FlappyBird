// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Core/GameManager.hpp"
#include "Game/LogoScreen.hpp"

#include <iostream>

auto main() -> int
{
    std::ios::sync_with_stdio(false);
    try
    {
        Core::GameManager game(512, 910, "Flappy Bird");

        game.getGameData()->stateManager.addState(std::make_unique<Game::LogoScreen>(game.getGameData()));

        game.run();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "[FATAL] " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "[FATAL] Unknown exception" << std::endl;
    }

    return 0;
}