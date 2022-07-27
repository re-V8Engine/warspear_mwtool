#pragma once
class Controller
{
private:
	PrimaryInstance* primary;
	vector<PrimaryInstance*> second;
	short prevX = 0;
	short prevY = 0;
public:
	Controller(vector<PrimaryInstance*> instances);
	void Follower();
};

