#include <conio.h>
#include <cstdio>
#include <iostream>
using namespace std;

class StateBase
{
public:
	virtual StateBase* GetNextState() = 0;
	virtual    char* ToString() = 0;
};

// State Closed
class Closed : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Closed";
	}
};

// State Locked
class Locked : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Locked";
	}
};

// State Opened
class Opened : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Opened";
	}
};


StateBase* Closed::GetNextState() {
	int a;
	do
	{
		cout << "Nhap lua chon 1 (Open) 0 (Look): ";
		cin >> a;
	} while (a < 0 || a > 1);
	if (a == 0)
		return new Locked();
	else
		return new Opened();
	
}

StateBase* Locked::GetNextState() {
	return new Closed();
}

StateBase* Opened::GetNextState() {
	return new Closed();
}

class Door
{
public:
	Door() {}
	Door(StateBase* pContext) {
		m_pState = pContext;
	}
	~Door() {
		delete m_pState;
	}
	// Handles the next state
	void StateChanged() {
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState();
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStateName() {
		return m_pState->ToString();
	}
protected:
	StateBase* m_pState;
};


void main()
{

	Door objDoor(new Opened);
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	objDoor.StateChanged();
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	objDoor.StateChanged();
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	objDoor.StateChanged();
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	objDoor.StateChanged();
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	objDoor.StateChanged();
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	system("pause");

}