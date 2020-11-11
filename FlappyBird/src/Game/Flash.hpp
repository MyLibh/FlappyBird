#ifndef __FLASH_HPP_INCLUDED__
#define __FLASH_HPP_INCLUDED__

#include "../Core/GameData.hpp"

namespace Game
{
	class Flash
	{
	private:
		inline static constexpr auto SPEED{ 1500.f };

	public:
		Flash(Core::ptr_game_data_t gameData) :
			m_gameData(gameData),
			m_shape(sf::Vector2f(m_gameData->window.getSize().x, m_gameData->window.getSize().y)),
			m_isOn(true)
		{
			m_shape.setFillColor(sf::Color(255, 255, 255, 0));
		}

		void show(const float dt);

		void draw() { m_gameData->window.draw(m_shape); }

	private:
		Core::ptr_game_data_t m_gameData;
		sf::RectangleShape    m_shape;
		bool                  m_isOn;
	};
} // namespace Game

#endif /* !__FLASH_HPP_INCLUDED__ */