#pragma once
#include <GL/gl.h>

class Sprite
{
public:
	struct Point
	{
		GLfloat x;
		GLfloat y;
	};

	struct Size
	{
		GLfloat width;
		GLfloat height;
	};

	struct Rect
	{
		GLfloat top;
		GLfloat bottom;
		GLfloat left;
		GLfloat right;
	};

protected:
	GLuint* m_textures;
	unsigned int m_textureIndex;
	unsigned int m_currentFrame;
	unsigned int m_numberOfFrames;
	GLfloat m_animationDelay;
	GLfloat m_animationElapsed;

	Point m_position;
	Size m_size;
	GLfloat m_velocity;

	bool m_isCollideable;
	bool m_flipHorizontal;
	bool m_flipVertical;
	bool m_isVisible;
	bool m_isActive;
	bool m_useTransparency;
	bool m_isSpriteSheet;

public:
	Sprite(const unsigned int m_pNumberOfTextures);
	~Sprite();

	void Update(const float p_deltaTime);
	void Render();

	const bool AddTexture(const char* p_fileName, const bool p_useTransparency = true);
	const GLuint GetCurrentFrame() {
		if (m_isSpriteSheet) {
			return m_textures[0];
		}
		else
		{
			return m_textures[m_currentFrame];
		}
	}

	void SetPosition(const Point p_position) { m_position = p_position; }
	const Size GetSize() const { return m_size; }

	void SetFrameSize(const GLfloat p_width, const GLfloat p_height)
	{
		m_size.width = p_width;
		m_size.height = p_height;
	}
	void SetVelocity(const GLfloat p_velocity) { m_velocity = p_velocity; }
	void SetNumberOfFrames(const unsigned int p_frames) { m_numberOfFrames = p_frames; }
	const bool isCollideable() const { return m_isCollideable; }
	void IsCollideable(const bool p_value) { m_isCollideable = p_value; }
	void FlipHorizontal(const bool p_value) { m_flipHorizontal = p_value; }
	void FlipVertical(const bool p_value) { m_flipVertical = p_value; }
	void IsActive(const bool p_value) { m_isActive = p_value; }
	const bool IsActive() const { return m_isActive; }
	void IsVisible(const bool p_value) {m_isVisible = p_value; }
	const bool IsVisible() const { return m_isVisible; }
	void UseTransparency(const bool p_value) { m_useTransparency = p_value; }
};


