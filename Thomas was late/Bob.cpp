#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
    m_Sprite = Sprite(TextureHolder::GetTexture("Assets/graphics/bob.png"));
    m_JumpDuration = .25;
}

bool Bob::handleInput()
{
    return false;
	//JumpCode
	m_JustJumped = false;
	if (sf::Keyboard::isKeyPressed(Keyboard::Up))
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
	if (sf::Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}
	return m_JustJumped;
}
