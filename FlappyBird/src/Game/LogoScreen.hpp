#ifndef __LOGO_SREEN_HPP_INCLUDED__
#define __LOGO_SREEN_HPP_INCLUDED__

#include "../Core/base_state.hpp"
#include "../Core/GameData.hpp"

namespace Game
{
	class LogoScreen final : public Core::base_state
	{
	public:
		inline LogoScreen(Core::ptr_game_data_t gameData) :
			m_gameData(gameData),
			m_clock(),
			m_sprite()
		{}

		void init() override;

		void handleEvents() override;
		void update(const float dt) override;
		void draw(const float dt) override;

	private:
		Core::ptr_game_data_t m_gameData;
		sf::Clock             m_clock;
		sf::Sprite            m_sprite;
	};
} // namespace Game

#endif /* !__LOGO_SREEN_HPP_INCLUDED__ */