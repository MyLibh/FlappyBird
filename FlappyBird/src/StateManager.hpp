#ifndef __STATE_MANAGER_HPP_INCLUDED__
#define __STATE_MANAGER_HPP_INCLUDED__

#include <memory>
#include <stack>

#include "base_state.hpp"

namespace Core
{
	using state_ptr_t = std::unique_ptr<base_state>;

	class StateManager
	{
	public:
		[[nodiscard]] inline const state_ptr_t& getActiveState() const noexcept { return m_states.top(); }

		void addState(state_ptr_t newState, bool hasToReplace = true);

		inline void removeState() noexcept { m_hasToRemove = true; }

		void update();

	private:
		std::stack<state_ptr_t> m_states;
		state_ptr_t             m_newState;
		bool                    m_hasToRemove;
		bool                    m_hasToAdd;
		bool                    m_hasToReplace;
	};
} // namespace Core

#endif /* !__STATE_MANAGER_HPP_INCLUDED__ */