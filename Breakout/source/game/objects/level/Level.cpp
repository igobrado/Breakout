#include "Level.hpp"

Level::Level()
{
}
Level::~Level()
{
}

Level& Level::operator=(Level&& other)
{
    return *this;
}

void Level::Update(const float& deltaTime)
{
}

void Level::Draw(sf::RenderWindow& window)
{
}

bool Level::LoadLevel()
{
    return true;
}

void Level::CreateRow(const uint8_t& row)
{
}

// std::vector<obj::Brick>::iterator Level::CheckBrickCollision(){}
BrickDefinitions::const_iterator Level::BrickDefinition(const int& brickIndex)
{
    return BrickDefinitions::const_iterator{};
}