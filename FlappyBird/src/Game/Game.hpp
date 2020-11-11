#ifndef __GAME_HPP_INCLUDED__
#define __GAME_HPP_INCLUDED__

#include "../Core/base_state.hpp"
#include "../Core/GameData.hpp"

namespace Game
{
	class Bird;
	class Pipes;
	class Land;
	class HUD;
	class Flash;
	class Game final : public Core::base_state
	{
	private:
		enum class State
		{
			Ready,
			Playing,
			GameOver
		};

	private:
		void _load();

	public:
		inline Game(Core::ptr_game_data_t gameData) :
			m_gameData(gameData),
			m_score{},
			m_state(State::Ready)
		{ }

		void init() override;

		void handleEvents() override;
		void update(const float dt) override;
		void draw(const float dt) override;

	private:
		Core::ptr_game_data_t  m_gameData;
		sf::Sprite             m_bckg;
		sf::Sprite             m_tapToPlay;
		sf::Sprite             m_getReady;
		sf::Clock              m_clock;
		std::shared_ptr<Bird>  m_bird;
		std::shared_ptr<Pipes> m_pipes;
		std::shared_ptr<Land>  m_land;
		std::shared_ptr<HUD>   m_hud;
		std::shared_ptr<Flash> m_flash;
		unsigned short         m_score;
		State                  m_state;
	};
} // namespace Game

#endif /* !__GAME_HPP_INCLUDED__ */