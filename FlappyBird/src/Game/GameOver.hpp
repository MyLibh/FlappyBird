#ifndef __GAME_OVER_HPP_INCLUDED__
#define __GAME_OVER_HPP_INCLUDED__

#include "../Core/base_state.hpp"
#include "../Core/GameData.hpp"

namespace Game
{
	class GameOver final : public Core::base_state
	{
	private:
		enum class State
		{
			Animating,
			ReadyToRestart
		};

	private:
		void _load();
		void _checkHighscore();

	public:
		inline GameOver(Core::ptr_game_data_t gameData, const int score) :
			m_gameData(gameData),
			m_score(score),
			m_highscore{},
			m_state(State::Animating)
		{ }

		void init() override;

		void handleEvents() override;
		void update(const float dt) override;
		void draw(const float dt) override;

	private:
		Core::ptr_game_data_t m_gameData;
		sf::Sprite            m_bckg;
		sf::Sprite            m_title;
		sf::Sprite            m_block;
		sf::Sprite            m_retryButton;
		sf::Sprite            m_medal;
		int                   m_score;
		int                   m_highscore;
		sf::Text              m_scoreText;
		sf::Text              m_highscoreText;
		State                 m_state;
	};
} // namespace Game

#endif /* !__GAME_OVER_HPP_INCLUDED__ */