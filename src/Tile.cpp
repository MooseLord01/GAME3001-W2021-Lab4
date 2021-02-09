#include "Tile.h"

#include <iomanip>
#include <sstream>

#include "Config.h"
#include "TextureManager.h"
#include "Util.h"

Tile::Tile() : m_cost(0.0f)
{
	setWidth(Config::TILE_SIZE);
	setHeight(Config::TILE_SIZE);
}

Tile::~Tile()
= default;

void Tile::draw()
{
	Util::DrawRect(getTransform()->position, getWidth(), getHeight());
}

void Tile::update()
{
}

void Tile::clean()
{
}

void Tile::addLabels()
{
	auto offset = glm::vec2(Config::TILE_SIZE * 0.5f, Config::TILE_SIZE * 0.5f);
	
	m_costLabel = new Label("99.9", "Consolas", 12);
	m_costLabel->getTransform()->position = getTransform()->position + offset + glm::vec2(0.0f, -6.0f);
	getParent()->addChild(m_costLabel);
	m_costLabel->setEnabled(false);

	m_statusLabel = new Label("--", "Consolas", 12);
	m_statusLabel->getTransform()->position = getTransform()->position + offset + glm::vec2(0.0f, 6.0f);
	getParent()->addChild(m_statusLabel);
	m_statusLabel->setEnabled(false);
}

void Tile::setLabelsEnabled(const bool state)
{
	m_costLabel->setEnabled(state);
	m_statusLabel->setEnabled(state);
}

// Setters
void Tile::SetNeighbourTile(const NeighbourTile position, Tile* tile) { m_neighbours[position] = tile; }
void Tile::SetGridPosition(float col, float row) { m_gridPosition = glm::vec2(col, row); }
void Tile::SetTileCost(float cost) {
	m_cost = cost;

	// Format string to 1 decimal place
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << cost;
	const std::string cost_string = stream.str();

	m_costLabel->setText(cost_string);
}

// Getters
Tile* Tile::GetNeighbourTile(const NeighbourTile position) { return m_neighbours[position]; }
glm::vec2 Tile::GetGridPosition() { return m_gridPosition; }
float Tile::GetTileCost() { return m_cost; }
