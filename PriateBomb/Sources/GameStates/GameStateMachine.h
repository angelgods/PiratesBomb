#pragma once
#include "../GameManager/Singleton.h"
#include <list>

class GameStateBase;

enum StateTypes
{
	STATE_INVALID = 0,
	STATE_Intro,
	STATE_Menu,
	STATE_Play,
	STATE_End,
};

class GameStateMachine
	:public CSingleton<GameStateMachine>
{

public:
	GameStateMachine();
	~GameStateMachine();
public:

	void Cleanup();

	void ChangeState(GameStateBase* state);
	void ChangeState(StateTypes stt);
	void PushState(StateTypes stt);
	void PopState();

	bool isRunning() { return m_running; }
	void Quit() { m_running = false; }
	void PerformStateChange();
	void ReLoadCurrentState(StateTypes stt);

	inline GameStateBase*	CurrentState()const
	{
		return m_pActiveState;
	}
	inline GameStateBase* NextState()const
	{
		return m_pNextState;
	}
	inline bool		NeedsToChangeState()const
	{
		return (m_pNextState != 0);
	}

	inline bool		HasState()const
	{
		return m_StatesStack.size() > 0;
	}

private:

	std::list < GameStateBase*>	m_StatesStack;
	GameStateBase*	m_pActiveState;
	GameStateBase*	m_pNextState;
	bool m_running;
};