#ifndef __INPUT_MANAGER_HPP_INCLUDED__
#define __INPUT_MANAGER_HPP_INCLUDED__

#include <SFML/Graphics.hpp>

namespace Core
{
	class InputManager
	{
	public:
		static auto getMousePos(const sf::RenderWindow& window) noexcept { return sf::Mouse::getPosition(window); }

		static bool isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, const sf::RenderWindow& window);
	};
} // namespace Core

#endif /* !__INPUT_MANAGER_HPP_INCLUDED__ */