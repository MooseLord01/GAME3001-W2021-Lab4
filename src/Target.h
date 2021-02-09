#pragma once
#ifndef __TARGET__
#define __TARGET__

#include "DisplayObject.h"

class Target final : public DisplayObject {
public:
	Target();
	~Target();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// Setters
	void SetGridPosition(float col, float row);
	
	// Getter
	glm::vec2 GetGridPosition();

private:
	void m_move();
	void m_checkBounds();
	void m_reset();

	glm::vec2 m_gridPosition;
};


#endif /* defined (__TARGET__) */