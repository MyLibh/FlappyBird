#ifndef __MAIN_MENU_HPP_INCLUDED__
#define __MAIN_MENU_HPP_INCLUDED__

#include "../Core/BaseState.hpp"
#include "../Core/GameData.hpp"

namespace Game
{
	class MainMenu final : public Core::BaseState
	{
	private:
		void _load();

	public:
		inline explicit MainMenu(Core::ptr_game_data_t gameData) :
			m_gameData(gameData)
		{ }

		void init() override;

		void handleEvents() override;
		void update(const float dt) override {};
		void draw(const float dt) override;

	private:
		Core::ptr_game_data_t m_gameData;
		sf::Sprite            m_bckg;
		sf::Sprite            m_title;
		sf::Sprite            m_playButton;
	};
} // namespace Game

#endif /* !__MAIN_MENU_HPP_INCLUDED__ */