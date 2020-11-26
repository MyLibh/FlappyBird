// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "GameOver.hpp"
#include "Game.hpp"

#include <fstream>

namespace Game
{
	void GameOver::_load()
	{
		auto& assetManager = m_gameData->assetManager;
		assetManager.loadTexture("GameOverTitle", "assets/GameOverTitle.png");
		assetManager.loadTexture("GameOver", "assets/GameOver.png");
		assetManager.loadTexture("BronzeMedal", "assets/BronzeMedal.png");
		assetManager.loadTexture("SilverMedal", "assets/SilverMedal.png");
		assetManager.loadTexture("GoldMedal", "assets/GoldMedal.png");
		assetManager.loadTexture("PlatinumMedal", "assets/PlatinumMedal.png");
	}

	void GameOver::_checkHighscore()
	{
		if (!std::filesystem::exists("data"))
			std::filesystem::create_directory("data");

		if (!std::filesystem::exists("data/highscore.txt"))
			std::ofstream("data/highscore.txt");

		std::fstream file("data/highscore.txt", std::ios::in);
		if (!file.is_open())
			throw std::runtime_error("Cannot open highscore file for reading");

		file >> m_highscore;
		file.close();

		file.open("data/highscore.txt", std::ios::out | std::ios::trunc);
		if (!file.is_open())
			throw std::runtime_error("Cannot open highscore file for writing");

		m_highscore = std::max(m_score, m_highscore);
		file << m_highscore;
		file.close();
	}

	void GameOver::init()
	{
		_load();
		_checkHighscore();

		auto& assetManager = m_gameData->assetManager;
		m_bckg.setTexture(assetManager.getTexture("Background"));
		
		const auto size = m_gameData->window.getSize();
		m_block.setTexture(assetManager.getTexture("GameOver"));

		const auto bounds = m_block.getGlobalBounds();
		m_block.setPosition(size.x / 2 - bounds.width / 2, size.y / 2 - bounds.height / 2);

		m_title.setTexture(assetManager.getTexture("GameOverTitle"));
		const auto titleBounds = m_title.getGlobalBounds();
		const auto blockY = m_block.getPosition().y;
		m_title.setPosition(size.x / 2 - titleBounds.width / 2, blockY - titleBounds.height * 1.2f);

		m_retryButton.setTexture(assetManager.getTexture("PlayButton"));
		const auto retryBounds = m_retryButton.getGlobalBounds();
		m_retryButton.setPosition(size.x / 2 - retryBounds.width / 2, blockY + bounds.height + retryBounds.height * .2f);

		std::string medal;
		if (m_score >= 40)
			medal = "Platinum";
		else if (m_score >= 30)
			medal = "Gold";
		else if (m_score >= 20)
			medal = "Silver";
		else if (m_score >= 10)
			medal = "Bronze";

		if (!medal.empty())
		{
			m_medal.setTexture(assetManager.getTexture(medal + "Medal"));
			m_medal.setPosition(m_block.getPosition().x + bounds.width * 0.12f, m_block.getPosition().y + bounds.height * 0.38f);
		}

		const auto& [w, h] = m_gameData->window.getSize();
		m_scoreText.setFont(m_gameData->assetManager.getFont("FlappyFont"));
		m_scoreText.setCharacterSize(40);
		m_scoreText.setString("0");
		m_scoreText.setFillColor(sf::Color::White);
		m_scoreText.setOutlineColor(sf::Color::Black);
		m_scoreText.setOutlineThickness(2.f);
		m_scoreText.setOrigin(sf::Vector2f(m_scoreText.getGlobalBounds().width / 2, m_scoreText.getGlobalBounds().height / 2));
		m_scoreText.setPosition(sf::Vector2f(w / 10 * 7.5f, h / 2.14f));

		m_highscoreText.setFont(m_gameData->assetManager.getFont("FlappyFont"));
		m_highscoreText.setCharacterSize(40);
		m_highscoreText.setString(std::to_string(m_highscore));
		m_highscoreText.setFillColor(sf::Color::White);
		m_highscoreText.setOutlineColor(sf::Color::Black);
		m_highscoreText.setOutlineThickness(2.f);
		m_highscoreText.setOrigin(sf::Vector2f(m_highscoreText.getGlobalBounds().width / 2, m_highscoreText.getGlobalBounds().height / 2));
		m_highscoreText.setPosition(sf::Vector2f(w / 10 * 7.5f, h / 1.82f));
	}

	void GameOver::handleEvents()
	{
		sf::Event event;
		while (m_gameData->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_gameData->window.close();

			if (m_state == State::ReadyToRestart && Core::InputManager::isSpriteClicked(m_retryButton, sf::Mouse::Left, m_gameData->window))
				m_gameData->stateManager.addState(std::make_unique<Game>(m_gameData), true);
		}
	}

	void GameOver::update(const float dt)
	{
		static float accumulator = 0.f;
		static int counter = 0;
		
		if (m_state == State::Animating)
		{
			accumulator += dt;
			if (accumulator >= .1f)
			{
				accumulator -= .1f;

				counter++;

				m_scoreText.setString(std::to_string(counter));
			}
		}

		if (counter == m_score)
		{
			m_state = State::ReadyToRestart;

			counter = 0;
			accumulator = 0.f;
		}
	}

	void GameOver::draw(const float dt)
	{
		auto& window = m_gameData->window;
		window.clear();

		window.draw(m_bckg);
		window.draw(m_block);
		window.draw(m_title);
		window.draw(m_medal);

		if (m_state == State::ReadyToRestart)
			window.draw(m_retryButton);

		window.draw(m_scoreText);
		window.draw(m_highscoreText);

		window.display();
	}
} // namespace Game