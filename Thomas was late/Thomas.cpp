#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("Assets/graphics/thomas.png"));
	m_JumpDuration = .45;
}

bool Thomas::handleInput()
{
	//JumpCode
	m_JustJumped = false;
	if (sf::Keyboard::isKeyPressed(Keyboard::W))
	{
		if (!m_IsJumping && !m_isFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_isFalling = true;
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}
	return m_JustJumped;
}
