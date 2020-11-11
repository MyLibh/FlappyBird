// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Land.hpp"

namespace Game
{
	Land::Land(Core::ptr_game_data_t gameData) :
		m_gameData(gameData)
	{
		m_land.emplace_back(m_gameData->assetManager.getTexture("Land"));
		m_land.back().setPosition(0, gameData->window.getSize().y - m_land.back().getLocalBounds().height);

		m_land.emplace_back(m_gameData->assetManager.getTexture("Land"));
		m_land.back().setPosition(m_land.back().getLocalBounds().width, gameData->window.getSize().y - m_land.back().getLocalBounds().height);
	}

	void Land::move(const float dt)
	{
		for (auto& sprite : m_land)
		{
			auto pos = sprite.getPosition();

			sprite.move(-Land::SPEED * dt, 0.f);

			if (sprite.getPosition().x < -sprite.getLocalBounds().width)
				sprite.setPosition(m_gameData->window.getSize().x, sprite.getPosition().y);
		}
	}
} // namespace Game