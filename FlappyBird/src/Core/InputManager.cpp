// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "InputManager.hpp"

namespace Core
{
    bool InputManager::isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, const sf::RenderWindow& window)
    {
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButtonRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

			if (playButtonRect.contains(sf::Mouse::getPosition(window)))
				return true;
		}

		return false;
    }
} // namespace Core