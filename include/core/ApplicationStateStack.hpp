/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:  
 *
 *        Created:  16/01/2015 00:49:39
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATESTACK_HPP_
#define APPLICATIONSTATESTACK_HPP_

#include <memory>
#include <stack>

#include "ApplicationState.hpp"

class ApplicationStateStack {
	public:
		template<typename T, typename... Args>
		T &push(Args &&...args) {
			m_states.push(std::make_shared<T>(std::forward<Args>(args)...));
			return *std::static_pointer_cast<T>(m_states.top());
		}
		
		// WARNING: When you use this function, make sure that you're
		// not reading/writing anything from/to the deleted objects
		void pop() { m_states.pop(); }
		
		ApplicationState &top() const { return *m_states.top(); }
		
		std::size_t size() const { return m_states.size(); }
		
		static ApplicationStateStack &getInstance() {
			static ApplicationStateStack instance;
			return instance;
		}
		
	private:
		ApplicationStateStack() = default;
		
		std::stack<std::shared_ptr<ApplicationState>> m_states;
};

#endif // APPLICATIONSTATESTACK_HPP_
