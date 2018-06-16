#pragma once

#include <memory>
//Top state is the running and then pop to get back to game
#include <stack>

#include "State.hpp"

namespace Cari {

	typedef std::unique_ptr<State> StateRef;

	//handle all states, what is running, what input is being handle, what is the stte at given time
	class StateMachine {
	public:
		StateMachine() {}

		~StateMachine() {}

		//adds state on to stack, isReplacing -> pop the old state and put the state on
		void AddState(StateRef newState, bool isReplacing = true);

		void RemoveState();
		//runs at start of each loop of game.cpp
		void ProcessStateChanges();

		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef newState;
		bool isRemoving;
		bool isAdding;
		bool isReplacing;
	};
}
