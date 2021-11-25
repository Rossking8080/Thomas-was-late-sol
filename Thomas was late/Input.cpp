#include <SFML/Graphics.hpp>
#include <sstream>
#include "Engine.h"

using namespace sf;

void Engine::input()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			//Quiting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_window.close();
			}

			//starting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				m_isPlaying = true;
			}

			//swap characters
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}

			//Swich full/split screen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				m_isSplitScreen = !m_isSplitScreen;
			}
		}
	}
	//handle input to thomas
	if (m_Thomas.handleInput())
	{
		//play sound
	}
	if (m_Bob.handleInput())
	{
		//play sound
	}
}