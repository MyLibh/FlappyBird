#ifndef __GAME_DATA_HPP_INCLUDED__
#define __GAME_DATA_HPP_INCLUDED__

#include "InputManager.hpp"
#include "StateManager.hpp"
#include "AssetManager.hpp"

namespace Core
{
	struct GameData
	{
		sf::RenderWindow window;

		StateManager stateManager;
		AssetManager assetManager;
	};

	using ptr_game_data_t = std::shared_ptr<GameData>;
} // namespace Core

#endif /* !__GAME_DATA_HPP_INCLUDED__ */