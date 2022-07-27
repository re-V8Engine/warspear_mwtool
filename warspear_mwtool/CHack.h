#pragma once

bool isPressed(WPARAM key)
{
	if (GetAsyncKeyState(key))
	{
		return true;
	}
}

class Command
{
public:
	virtual ~Command() {};
	virtual void execute() = 0;
};

class ClickCommand : public Command
{
private:
	PrimaryInstance* instance;
	int x_, y_;
public:
	ClickCommand(PrimaryInstance* instance, int x, int y) : instance(instance), x_(x), y_(y) {};
	virtual void execute() { instance->Click(x_, y_); }
};

class InputHandler
{
private:
	Command* leftmb_;
public:
	Command* handleInput();
};

Command* InputHandler::handleInput()
{
	if(isPressed(VK_LBUTTON)) return leftmb_;
	return NULL;
}


enum BotState
{
	BOT_INIT,
	BOT_COMBAT,
	BOT_WAITING,
	BOT_LOOT,
	BOT_FINAL
};

class CHack
{
private:
	CWindow& wnd;
	CDirectX d3d;
	CGUI gui;

	InputHandler inputHandler;

	Controller* controller;

	BotState botState = BOT_INIT;

	vector<PrimaryInstance*> _instance;

	

public:
	void Init();
	void Tick();

	void FindGameWindows();

	//Features
	void Bot(wstring name, int distance);
	CHack(class CWindow& wnd);
	~CHack();
};

