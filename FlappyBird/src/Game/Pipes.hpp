#ifndef __PIPES_HPP_INCLUDED__
#define __PIPES_HPP_INCLUDED__

#include "../Core/GameData.hpp"

namespace Game
{
	class Pipes final
	{
	private:
		inline static constexpr auto SPEED{ 200.f };

	public:
		inline explicit Pipes(Core::ptr_game_data_t gameData) :
			m_gameData(gameData),
			m_landHeight(m_gameData->assetManager.getTexture("Land").getSize().y),
			m_spawnOffset{}
		{}

		inline const auto& getSprites() const noexcept { return m_pipes; }

		inline auto& getScoringSprites() noexcept { return m_scoringPipes; }

		inline void spawnBottomPipe()
		{
			const auto [w, h] = m_gameData->window.getSize();
			m_pipes.emplace_back(m_gameData->assetManager.getTexture("PipeUp"));
			m_pipes.back().setPosition(static_cast<float>(w), h - m_pipes.back().getLocalBounds().height - m_spawnOffset);
		}

		inline void spawnTopPipe()
		{
			m_pipes.emplace_back(m_gameData->assetManager.getTexture("PipeDown"));
			m_pipes.back().setPosition(static_cast<float>(m_gameData->window.getSize().x), static_cast<float>(-m_spawnOffset));
		}

		inline void spawnScoringPipe()
		{
			m_scoringPipes.emplace_back(m_gameData->assetManager.getTexture("ScoringPipe"));
			m_scoringPipes.back().setPosition(static_cast<float>(m_gameData->window.getSize().x), 0.f);
		}

		void move(const float dt);
		
		inline void draw()
		{
			for (const auto& pipe : m_pipes)
				m_gameData->window.draw(pipe);
		}

		inline void randomizeOffset() noexcept { m_spawnOffset = rand() % (m_landHeight + 1); }

	private:
		Core::ptr_game_data_t   m_gameData;
		std::vector<sf::Sprite> m_pipes;
		std::vector<sf::Sprite> m_scoringPipes;
		int                     m_landHeight;
		int                     m_spawnOffset;
	};
} // namespace Game

#endif /* !__PIPES_HPP_INCLUDED__ */