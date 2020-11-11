#ifndef __LAND_HPP_INCLUDED__
#define __LAND_HPP_INCLUDED__

#include "../Core/GameData.hpp"

namespace Game
{
	class Land
	{
	private:
		inline static constexpr auto SPEED{ 200.f };

	public:
		Land(Core::ptr_game_data_t gameData);

		inline const auto& getSprites() const noexcept { return m_land; }

		void move(const float dt);
		
		inline void draw() const
		{
			for (const auto& sprite : m_land)
				m_gameData->window.draw(sprite);
		}

	private:
		Core::ptr_game_data_t   m_gameData;
		std::vector<sf::Sprite> m_land;
	};
} // namespace Game

#endif /* !__LAND_HPP_INLCLUDED__ */