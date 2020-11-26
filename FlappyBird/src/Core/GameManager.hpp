#ifndef __GAME_MANAGER_HPP_INCLUDED__
#define __GAME_MANAGER_HPP_INCLUDED__

#include "GameData.hpp"

namespace Core
{
	class GameManager
	{
	private:
		inline static constexpr auto DELTA_TIME{ 1.f / 60.f };

	public:
		inline GameManager(const unsigned width, const unsigned height, const std::string_view title) :
			m_gameData(std::make_shared<GameData>())
		{
			m_gameData->window.create(sf::VideoMode(width, height), title.data(), sf::Style::Close | sf::Style::Titlebar);
		}

		[[nodiscard]] inline const auto getGameData() { return m_gameData; }

		void run();

	private:
		ptr_game_data_t m_gameData;
		sf::Clock       m_clock;
	};
} // namespace Core

#endif /* !__GAME_MANAGER_HPP_INCLUDED__ */