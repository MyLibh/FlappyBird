// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Game.hpp"
#include "Bird.hpp"
#include "Pipes.hpp"
#include "Land.hpp"
#include "HUD.hpp"
#include "Flash.hpp"
#include "Collision.hpp"
#include "GameOver.hpp"

namespace Game
{
	void Game::_load()
	{
		auto& assetManager = m_gameData->assetManager;
		assetManager.loadTexture("Background", "assets/Background.png");
		assetManager.loadTexture("Bird1", "assets/Bird1.png");
		assetManager.loadTexture("Bird2", "assets/Bird2.png");
		assetManager.loadTexture("Bird3", "assets/Bird3.png");
		assetManager.loadTexture("PipeUp", "assets/PipeUp.png");
		assetManager.loadTexture("PipeDown", "assets/PipeDown.png");
		assetManager.loadTexture("ScoringPipe", "assets/ScoringPipe.png");
		assetManager.loadTexture("Land", "assets/Land.png");
		assetManager.loadTexture("TapToPlay", "assets/TapToPlay.png");
		assetManager.loadTexture("GetReady", "assets/GetReady.png");

		assetManager.loadFont("FlappyFont", "assets/fonts/FlappyFont.ttf");
	}

	void Game::init()
	{
		_load();

		auto& assetManager = m_gameData->assetManager;
		m_bckg.setTexture(assetManager.getTexture("Background"));

		m_tapToPlay.setTexture(assetManager.getTexture("TapToPlay"));
		m_tapToPlay.setPosition(m_gameData->window.getSize().x / 2 - m_tapToPlay.getGlobalBounds().width / 2, m_gameData->window.getSize().y / 2 - m_tapToPlay.getGlobalBounds().height / 2);

		m_getReady.setTexture(assetManager.getTexture("GetReady"));
		m_getReady.setPosition(m_gameData->window.getSize().x / 2 - m_getReady.getGlobalBounds().width / 2, m_tapToPlay.getPosition().y - m_getReady.getGlobalBounds().height / 2 - m_getReady.getGlobalBounds().height);

		m_bird  = std::make_shared<Bird>(m_gameData);
		m_pipes = std::make_shared<Pipes>(m_gameData);
		m_land  = std::make_shared<Land>(m_gameData);
		m_hud   = std::make_shared<HUD>(m_gameData);
		m_flash = std::make_shared<Flash>(m_gameData);
	}

	void Game::handleEvents()
	{
		sf::Event event;
		while (m_gameData->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_gameData->window.close();

			if (Core::InputManager::isSpriteClicked(m_bckg, sf::Mouse::Left, m_gameData->window)&& m_state != State::GameOver)
			{
				m_state = State::Playing;

				m_bird->jump();
			}
		}
	}

	void Game::update(const float dt)
	{
		if (m_state != State::GameOver)
		{
			m_bird->animate(dt);
			m_land->move(dt);
		}

		if (m_state == State::Playing)
		{
			m_pipes->move(dt);

			if (m_clock.getElapsedTime().asSeconds() > 1.5f)
			{
				m_pipes->randomizeOffset();

				m_pipes->spawnBottomPipe();
				m_pipes->spawnTopPipe();
				m_pipes->spawnScoringPipe();

				m_clock.restart();
			}

			m_bird->update(dt);

			for (const auto& land : m_land->getSprites())
				if (Physics::Collision::checkSpriteCollision(m_bird->getSprite(), .7f, land, 1.f))
				{
					m_state = State::GameOver;

					m_clock.restart();
				}

			for (const auto& pipe : m_pipes->getSprites())
				if (Physics::Collision::checkSpriteCollision(m_bird->getSprite(), 0.625f, pipe, 1.f))
				{
					m_state = State::GameOver;

					m_clock.restart();
				}

			if (m_state == State::Playing)
			{
				auto& scoringPipes = m_pipes->getScoringSprites();
				for (size_t i{}; i < scoringPipes.size(); ++i)
					if (Physics::Collision::checkSpriteCollision(m_bird->getSprite(), 0.625f, scoringPipes.at(i), 1.f))
					{
						m_score++;

						m_hud->updateScore(m_score);

						scoringPipes.erase(std::begin(scoringPipes) + i);
					}
			}
		}

		if (m_state == State::GameOver)
		{
			m_flash->show(dt);

			if (m_clock.getElapsedTime().asSeconds() > 1.f)
				m_gameData->stateManager.addState(std::make_unique<GameOver>(m_gameData, m_score), true);
		}
	}

	void Game::draw(const float dt)
	{
		auto& window = m_gameData->window;
		window.clear();

		window.draw(m_bckg);

		if (m_state == State::Ready)
		{
			window.draw(m_tapToPlay);
			window.draw(m_getReady);
		}

		m_bird->draw();
		m_pipes->draw();
		m_land->draw();
		m_hud->draw();
		m_flash->draw();

		window.display();
	}
} // namespace Game