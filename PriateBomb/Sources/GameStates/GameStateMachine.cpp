#include "GameStateMachine.h"
#include "GameStateBase.h"

GameStateMachine::GameStateMachine()
{
	m_running = true;
	m_pActiveState = 0;
	m_pNextState = 0;
}


GameStateMachine::~GameStateMachine()
{
}


void GameStateMachine::Cleanup()
{
	// cleanup the all states
	while (!m_StatesStack.empty()) {
		m_StatesStack.back()->Exit();
		m_StatesStack.pop_back();
	}
}

void GameStateMachine::ChangeState(StateTypes stt)
{
	GameStateBase* gstb = GameStateBase::CreateState(stt);
	ChangeState(gstb);
}

void GameStateMachine::ChangeState(GameStateBase* state)
{
	m_pNextState = state;
}


void GameStateMachine::PushState(StateTypes stt)
{
	GameStateBase* state = GameStateBase::CreateState(stt);
	// pause current state
	if (!m_StatesStack.empty()) {
		m_StatesStack.back()->Pause();
	}

	// store and init the new state
	m_pNextState = state;
}

void GameStateMachine::PopState()
{
	// cleanup the current state
	if (!m_StatesStack.empty()) {
		m_StatesStack.back()->Exit();
		m_StatesStack.pop_back();
	}

	// resume previous state
	if (!m_StatesStack.empty()) {
		m_StatesStack.back()->Resume();
	}
	m_pActiveState = m_StatesStack.back();
}

void  GameStateMachine::PerformStateChange()
{
	if (m_pNextState != 0)
	{
		// cleanup the current state
		if (!m_StatesStack.empty()) {
			m_StatesStack.back()->Exit();
		}

		// store and init the new state
		m_StatesStack.push_back(m_pNextState);
		m_StatesStack.back()->Init();
		m_pActiveState = m_pNextState;
	}
	m_pNextState = 0;
}

void  GameStateMachine::ReLoadCurrentState(StateTypes stt)
{
	if (!m_StatesStack.empty()) {
		PopState();
		ChangeState(stt);
		PerformStateChange();
	}
}