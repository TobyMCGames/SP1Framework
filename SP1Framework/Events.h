#pragma once
class Events
{
private:
	bool isActive;

public:
	Events();
	~Events();

	//mutator
	void toggle();

	//getter
	bool getActive();

};

