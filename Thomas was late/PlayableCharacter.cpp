#include "PlayableCharacter.h"

void playableCharacter::spawn(sf::Vector2f startPosition, float gravity)
{
	//place player at spawn point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;
	//initialize gravity
	m_Gravity = gravity;
	//move the sprite
	m_Sprite.setPosition(m_Position);
}

void playableCharacter::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		m_Position.x += m_speed * elapsedTime;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= m_speed * elapsedTime;
	}

	//the Jump Code
	if (m_IsJumping)
	{
		m_TimeThisJump += elapsedTime;
		if (m_TimeThisJump < m_JumpDuration)
		{
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_IsJumping = false;
			m_isFalling = true;
		}
	}
	if (m_isFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	}
	// Update the rect for all body parts
	FloatRect r = getPosition();
	// Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;
	// Head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * .3);
	m_Head.width = r.width;
	m_Head.height = 1;
	// Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height + .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;
	//Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .5;
	m_Left.width = 1;
	m_Left.height = r.height * .3;
	// Move the sprite into position
	m_Sprite.setPosition(m_Position);
}

sf::FloatRect playableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

sf::Vector2f playableCharacter::getCenter()
{
	return Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2, m_Position.y + m_Sprite.getGlobalBounds().height / 2);
}

sf::FloatRect playableCharacter::getFeet()
{
	return m_Feet;
}

sf::FloatRect playableCharacter::getHead()
{
	return m_Head;
}

sf::FloatRect playableCharacter::getRight()
{
	return m_Right;
}

sf::FloatRect playableCharacter::getLeft()
{
	return m_Left;
}

sf::Sprite playableCharacter::getSprite()
{
	return m_Sprite;
}

void playableCharacter::stopFalling(float position)
{
	m_Position.y - position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_isFalling = false;
}

void playableCharacter::stopRight(float position)
{
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void playableCharacter::stopLeft(float position)
{
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void playableCharacter::stopJump()
{
	m_IsJumping = false;
	m_isFalling = true;
}

