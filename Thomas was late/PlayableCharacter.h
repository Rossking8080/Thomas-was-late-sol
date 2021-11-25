#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <SFML/Graphics.hpp>
using namespace sf;

class playableCharacter
{
protected:
	//character sprite
	sf::Sprite m_Sprite;

	//character variables
	float m_JumpDuration;
	bool m_IsJumping;
	bool m_isFalling;
	bool m_LeftPressed;
	bool m_RightPressed;
	float m_TimeThisJump;
	bool m_JustJumped = false;

private:
	//character in relation to world
	float m_Gravity;
	float m_speed = 400;
	sf::Vector2f m_Position;
	sf::FloatRect m_Feet;
	sf::FloatRect m_Head;
	sf::FloatRect m_Right;
	sf::FloatRect m_Left;

	//Character texture
	sf::Texture m_Texture;

public:
	void spawn(sf::Vector2f startPosition, float gravity);
	bool virtual handleInput() = 0;
	sf::FloatRect getPosition();
	sf::FloatRect getFeet();
	sf::FloatRect getHead();
	sf::FloatRect getRight();
	sf::FloatRect getLeft();

	sf::Sprite getSprite();

	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	sf::Vector2f getCenter();
	void update(float elapsedTime);
};
#endif PLAYER_CHARACTER_H
