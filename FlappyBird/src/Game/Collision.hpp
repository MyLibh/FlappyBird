#ifndef __COLLISION_HPP_INCLUDED__
#define __COLLISION_HPP_INCLUDED__

#include <SFML/Graphics.hpp>

namespace Game::Physics
{
	class Collision final
	{
	public:
		inline static bool checkSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
		{
			return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
		}

		inline static bool checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
		{
			sprite1.setScale(scale1, scale1);
			sprite2.setScale(scale2, scale2);

			return Collision::checkSpriteCollision(sprite1, sprite2);
		}
	};
} // namespace Game::Physics

#endif /* !__COLLISION_HPP_INCLUDED__ */