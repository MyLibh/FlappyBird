// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "StateManager.hpp"

namespace Core
{
	void StateManager::addState(state_ptr_t newState, bool hasToReplace /* = true */)
	{
		m_hasToAdd     = true;
		m_hasToReplace = hasToReplace;
		m_newState     = std::move(newState);
	}

	void StateManager::update()
	{
		if (m_hasToRemove && !m_states.empty())
		{
			m_states.pop();
		
			m_hasToRemove = false;

			if (!m_states.empty())
				m_states.top()->resume();
		}

		if (m_hasToAdd)
		{
			if (!m_states.empty())
			{
				if (m_hasToReplace)
					m_states.pop();
				else
					m_states.top()->pause();
			}

			m_states.push(std::move(m_newState));
			m_states.top()->init();

			m_hasToAdd = false;
		}
	}
} // namespace Core
