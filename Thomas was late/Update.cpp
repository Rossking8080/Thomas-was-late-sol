#include <SFML/Graphics.hpp>
#include <sstream>
#include "Engine.h"

using namespace sf;
void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);
		m_timeRemaining = 10;
		m_NewLevelRequired = false;
	}

	if (m_isPlaying)
	{
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);
		m_timeRemaining -= dtAsSeconds;

		if (m_timeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}

	if (m_isSplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}