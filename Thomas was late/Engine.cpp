#include "Engine.h"
#include <SFML/Graphics.hpp>

Engine::Engine()
{
	//generating the windows resolution
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	m_window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas was late", sf::Style::Fullscreen);

	//initialize the full screen veiw
	m_MainView.setSize(resolution);
	m_HUDView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//Initialize the split-screen views
	m_LeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_backgroundTexture = TextureHolder::GetTexture("graphics/background.png");
	m_BackgroundSprite.setTexture(m_backgroundTexture);
}

void Engine::run()
{
	//Timing
	sf::Clock clock;
	
	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();
		m_gameTimeTotal += dt;
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}

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
}

void Engine::draw()
{
	m_window.clear(sf::Color::White);
	if (!m_isSplitScreen)
	{
		m_window.setView(m_BGMainView);
		m_window.draw(m_BackgroundSprite);
		m_window.setView(m_MainView);
	}
	else
	{
		m_window.setView(m_BGLeftView);
		m_window.draw(m_BackgroundSprite);
		m_window.setView(m_LeftView);

		m_window.setView(m_BGRightView);
		m_window.draw(m_BackgroundSprite);
		m_window.setView(m_RightView);
	}

	//Draw the hud
	m_window.setView(m_HUDView);
	m_window.display();
}
