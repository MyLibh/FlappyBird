#ifndef __HUD_HPP_INCLUDED__
#define __HUD_HPP_INCLUDED__

#include "../Core/GameData.hpp"

namespace Game
{
	class HUD
	{
	public:
		HUD(Core::ptr_game_data_t gameData);

		inline void draw() { m_gameData->window.draw(m_score); }

		inline void updateScore(const unsigned score) { m_score.setString(std::to_string(score)); }

	private:
		Core::ptr_game_data_t m_gameData;
		sf::Text              m_score;
	};
} // namespace Game

#endif /* !__HUD_HPP_INCLUDED__ */