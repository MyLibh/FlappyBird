// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "HUD.hpp"

namespace Game
{
	HUD::HUD(Core::ptr_game_data_t gameData) :
		m_gameData(gameData),
		m_score{}
	{
		m_score.setFont(m_gameData->assetManager.getFont("FlappyFont"));
		m_score.setString("0");
		m_score.setCharacterSize(64);
		m_score.setFillColor(sf::Color::White);
		m_score.setOutlineColor(sf::Color::Black);
		m_score.setOutlineThickness(2.f);
		m_score.setOrigin(sf::Vector2f(m_score.getGlobalBounds().width / 2, m_score.getGlobalBounds().height / 2));
		m_score.setPosition(sf::Vector2f(m_gameData->window.getSize().x / 2.f, m_gameData->window.getSize().y / 15.f));
	}
} // namespace Game
