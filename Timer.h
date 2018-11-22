
//THIS CLASS IS CURRENTLY USELESS. IGNORE UNTIL OTHERWISE STATED.

#pragma once
#include <ctime>
class Timer
{
public:
	static void InitializeDeltaTime()
	{
		m_DeltaTime = (float)(std::clock() / 1000);
	};
	static void CalculateDeltaTime()
	{
		float timeCycle = (float)std::clock() / 1000.0f;
		m_DeltaTime = timeCycle - Last;
		Last = timeCycle;
	};
	static float GetDeltaTime()
	{
		return m_DeltaTime;
	};
private:
	static float Last;
	static float m_DeltaTime;
};

float Timer::Last = 0.0f;
float Timer::m_DeltaTime = 0.0f;
