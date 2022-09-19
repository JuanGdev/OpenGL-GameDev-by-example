#include <xstddef>
#include "Sprite.h"
#include "SOIL.h"

Sprite::Sprite(const unsigned int p_numberOfTextures)
{
	m_textures = new GLuint[p_numberOfTextures];
	m_textureIndex = 0;
	m_currentFrame = 0;
	m_numberOfFrames = 0;
	m_animationDelay = 0.25f;
	m_animationElapsed = 0.0f;
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_size.height = 0.0f;
	m_size.width = 0.0f;
	m_velocity = 0.0f;

	m_isCollideable = true;
	m_flipHorizontal = false;
	m_flipVertical = false;
	m_isVisible = false;
	m_isActive = false;
	m_isSpriteSheet = false;
}

Sprite::~Sprite()
{
	delete[] m_textures;
}
