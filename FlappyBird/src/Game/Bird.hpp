#ifndef __BIRD_HPP_INCLUDED__
#define __BIRD_HPP_INCLUDED__

#include "../Core/GameData.hpp"

namespace Game
{
	class Bird final
	{
	private:
		inline static constexpr auto ANIMATION_DURATION{ .4f };
		inline static constexpr auto FLYING_DURATION{ .3f };

		inline static constexpr auto ROTATION_SPEED{ 100.f };
		inline static constexpr auto FLYING_SPEED{ 350.f };

		inline static constexpr auto GRAVITY{ 300.f };

	private:
		enum class State
		{
			Still,
			Flying,
			Falling
		};

	public:
		explicit Bird(Core::ptr_game_data_t gameData);

		inline const auto& getSprite() const { return m_sprite; }

		void update(const float dt);

		inline void draw() { m_gameData->window.draw(m_sprite); }

		inline void animate(const float dt)
		{
			if (auto size = m_animations.size(); m_clock.getElapsedTime().asSeconds() > Bird::ANIMATION_DURATION / size)
			{
				++m_currentAnim;
				m_currentAnim %= size;

				m_sprite.setTexture(m_animations.at(m_currentAnim));

				m_clock.restart();
			}
		}

		inline void jump()
		{
			m_movementClock.restart();

			m_state = State::Flying;
		}

	private:
		Core::ptr_game_data_t    m_gameData;
		sf::Sprite               m_sprite;
		std::vector<sf::Texture> m_animations;
		unsigned short           m_currentAnim;
		sf::Clock                m_clock;
		sf::Clock                m_movementClock;
		State                    m_state;
		float                    m_rotation;
	};
} // namespace Game

#endif /* !__BIRD_HPP_INCLUDED__ */