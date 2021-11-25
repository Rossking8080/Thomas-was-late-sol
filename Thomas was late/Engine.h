#ifndef ENGINE_H
#define	ENGINE_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"

class Engine
{
private:
// TEXTURE HOLDER
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;

	const int TILE_SIZE = 50;
	const int  VERT_IN_QUAD = 4;
	const int GRAVITY = 300;

	sf::RenderWindow m_window;

	//The main veiw
	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;


	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;
	sf::View m_HUDView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_backgroundTexture;

	bool m_isPlaying = false;
	bool m_Character1 = true;
	bool m_isSplitScreen = false;
	bool m_NewLevelRequired = true;
	
	float m_timeRemaining = 10;
	sf::Time m_gameTimeTotal;

	void input();
	void update(float dtAsSeconds);
	void draw();


public:
	Engine();

	void run();

};

#endif ENGINE_H
