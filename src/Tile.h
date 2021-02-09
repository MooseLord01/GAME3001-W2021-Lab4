#pragma once
#ifndef __TILE__
#define __TILE__
#include "DisplayObject.h"
#include "Label.h"
#include "NeighbourTile.h"

class Tile : public DisplayObject
{
public:
	// Constructor
	Tile();
	
	// Destructor
	~Tile();
	
	// Life-Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

	void addLabels();
	void setLabelsEnabled(bool state);
	
	// Setters
	void SetNeighbourTile(NeighbourTile position, Tile* tile);
	void SetGridPosition(float col, float row);
	void SetTileCost(float cost);
	
	// Getters
	Tile* GetNeighbourTile(NeighbourTile position);
	glm::vec2 GetGridPosition();
	float GetTileCost();

private:
	float m_cost;

	Label* m_costLabel;
	Label* m_statusLabel;

	glm::vec2 m_gridPosition;
	
	Tile* m_neighbours[NUM_OF_NEIGHBOUR_TILES];
};

#endif /* defined (__TILE__) */ 