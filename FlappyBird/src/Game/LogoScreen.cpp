// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "LogoScreen.hpp"
#include "MainMenu.hpp"

namespace Game
{
	void LogoScreen::init()
	{
		auto& assetManager = m_gameData->assetManager;
		assetManager.loadTexture("LogoScreen", "assets/LogoScreen.png");

		m_sprite.setTexture(assetManager.getTexture("LogoScreen"));
	}

	void LogoScreen::handleEvents()
	{
		sf::Event event;
		while (m_gameData->window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				m_gameData->window.close();
	}

	void LogoScreen::update(const float dt)
	{
		if (m_clock.getElapsedTime().asSeconds() > 0.f)
			m_gameData->stateManager.addState(std::make_unique<MainMenu>(m_gameData), true);
	}
	
	void LogoScreen::draw(const float dt)
	{
		auto& window = m_gameData->window;
		window.clear();

		window.draw(m_sprite);

		window.display();
	}
} // namespace Game