// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "GameManager.hpp"

namespace Core
{
	void GameManager::run()
	{
		float currentTime = m_clock.getElapsedTime().asSeconds();
		float accumulator{};
		while (m_gameData->window.isOpen())
		{
			m_gameData->stateManager.update();

			float newTime = m_clock.getElapsedTime().asSeconds();
			float frameTime = std::min(newTime - currentTime, .25f);

			currentTime = newTime;
			accumulator += frameTime;

			auto& state = m_gameData->stateManager.getActiveState();
			while (accumulator >= GameManager::DELTA_TIME)
			{
				state->handleEvents();
				state->update(GameManager::DELTA_TIME);

				accumulator -= GameManager::DELTA_TIME;
			}

			state->draw(accumulator / GameManager::DELTA_TIME);
		}
	}
} // namespace Core