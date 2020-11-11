// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Pipes.hpp"

namespace Game
{
	void Pipes::move(const float dt)
	{
		for (size_t i{}; i < m_pipes.size(); ++i)
			if (m_pipes.at(i).getPosition().x < -m_pipes.at(i).getLocalBounds().width)
				m_pipes.erase(m_pipes.begin() + i);
			else
				m_pipes.at(i).move(-Pipes::SPEED * dt, 0);

		for (size_t i{}; i < m_scoringPipes.size(); ++i)
			if (m_scoringPipes.at(i).getPosition().x < -m_scoringPipes.at(i).getLocalBounds().width)
				m_scoringPipes.erase(m_scoringPipes.begin() + i);
			else
				m_scoringPipes.at(i).move(-Pipes::SPEED * dt, 0);
	}
} // namespace Game