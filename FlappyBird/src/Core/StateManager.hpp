#ifndef __STATE_MANAGER_HPP_INCLUDED__
#define __STATE_MANAGER_HPP_INCLUDED__

#include <memory>
#include <stack>

#include "BaseState.hpp"

namespace Core
{
	using state_ptr_t = std::unique_ptr<BaseState>;

	class StateManager
	{
	public:
		[[nodiscard]] inline const state_ptr_t& getActiveState() const { return m_states.top(); }

		void addState(state_ptr_t newState, bool hasToReplace = true) noexcept;

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