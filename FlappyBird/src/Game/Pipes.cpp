// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Pipes.hpp"

namespace Game
{
	void Pipes::move(const float dt)
	{
		for (size_t i{}; i < m_pipes.size(); ++i)
			if (auto& pipe = m_pipes.at(i); pipe.getPosition().x < -m_pipes.at(i).getLocalBounds().width)
				m_pipes.erase(m_pipes.begin() + i);
			else
				pipe.move(-Pipes::SPEED * dt, 0.f);

		for (size_t i{}; i < m_scoringPipes.size(); ++i)
			if (auto& pipe = m_scoringPipes.at(i); pipe.getPosition().x < -pipe.getLocalBounds().width)
				m_scoringPipes.erase(m_scoringPipes.begin() + i);
			else
				pipe.move(-Pipes::SPEED * dt, 0.f);
	}
} // namespace Game