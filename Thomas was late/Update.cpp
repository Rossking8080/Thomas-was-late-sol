#include <SFML/Graphics.hpp>
#include <sstream>
#include "Engine.h"

using namespace sf;
void Engine::update(float dtAsSeconds)
{
	if (m_isPlaying)
	{
		m_timeRemaining -= dtAsSeconds;

		if (m_timeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}
}