// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "MainMenu.hpp"
#include "Game.hpp"

namespace Game
{
	void MainMenu::_load()
	{
		auto& assetManager = m_gameData->assetManager;
		assetManager.loadTexture("Background", "assets/Background.png");
		assetManager.loadTexture("Title", "assets/Title.png");
		assetManager.loadTexture("PlayButton", "assets/PlayButton.png");
	}

	void MainMenu::init()
	{
		_load();

		auto& assetManager = m_gameData->assetManager;
		m_bckg.setTexture(assetManager.getTexture("Background"));

		m_title.setTexture(assetManager.getTexture("Title"));
		m_title.setPosition(512 / 2 - m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2);

		m_playButton.setTexture(assetManager.getTexture("PlayButton"));
		m_playButton.setPosition(512 / 2 - m_playButton.getGlobalBounds().width / 2, 910 / 2 - m_playButton.getGlobalBounds().height / 2);
	}

	void MainMenu::handleEvents()
	{
		sf::Event event;
		while (m_gameData->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_gameData->window.close();

			if (Core::InputManager::isSpriteClicked(m_playButton, sf::Mouse::Left, m_gameData->window))
				m_gameData->stateManager.addState(std::make_unique<Game>(m_gameData));
		}
	}

	void MainMenu::draw(const float dt)
	{
		auto& window = m_gameData->window;
		window.clear();

		window.draw(m_bckg);
		window.draw(m_title);
		window.draw(m_playButton);

		window.display();
	}
} // namespace Game