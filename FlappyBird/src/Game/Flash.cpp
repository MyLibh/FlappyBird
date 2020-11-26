// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Flash.hpp"

#include <algorithm>

namespace Game
{
	void Flash::show(const float dt)
	{
		auto alpha = m_shape.getFillColor().a - Flash::SPEED * dt;
		alpha = m_isOn ? std::min(alpha, 255.f) : std::max(alpha, 0.f);

		m_isOn = false;

		m_shape.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
	}
} // namespace Game