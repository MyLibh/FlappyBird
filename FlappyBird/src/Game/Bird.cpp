// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Bird.hpp"

namespace Game
{
	Bird::Bird(Core::ptr_game_data_t gameData) :
		m_gameData(gameData),
		m_sprite(),
		m_animations(),
		m_currentAnim{},
		m_clock(),
		m_movementClock(),
		m_state(State::Still),
		m_rotation{}
	{
		auto& assetManager = m_gameData->assetManager;
		m_animations.push_back(assetManager.getTexture("Bird1"));
		m_animations.push_back(assetManager.getTexture("Bird2"));
		m_animations.push_back(assetManager.getTexture("Bird3"));

		m_sprite.setTexture(m_animations.at(m_currentAnim));
		m_sprite.setPosition(m_gameData->window.getSize().x / 4 - m_sprite.getGlobalBounds().width / 2, m_gameData->window.getSize().y / 2 - m_sprite.getGlobalBounds().height / 2);
		m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	}

	void Bird::update(const float dt)
	{
		if (m_state == State::Falling)
		{
			m_sprite.move(0, Bird::GRAVITY * dt);

			m_rotation = std::min(m_rotation + Bird::ROTATION_SPEED * dt, 25.f);

		}
		else if (m_state == State::Flying)
		{
			m_sprite.move(0, -Bird::FLYING_SPEED * dt);

			m_rotation = std::max(m_rotation - Bird::ROTATION_SPEED * dt, -25.f);
		}

		m_sprite.setRotation(m_rotation);

		if (m_movementClock.getElapsedTime().asSeconds() > Bird::FLYING_DURATION)
		{
			m_movementClock.restart();

			m_state = State::Falling;
		}
	}
} // namespace Game