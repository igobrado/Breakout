#ifndef BREAKOUT_SCOREBOARD_HPP
#define BREAKOUT_SCOREBOARD_HPP

#include <cinttypes>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "private/Textbox.hpp"

struct Player
{
    Player() = default;
    explicit Player(std::string name)  //
        : playerName{ std::move(name) }
        , score{ 0U }
    {
    }

    [[nodiscard]] std::string toString() const
    {
        try
        {
            std::string scoreString = std::to_string(score);
            return std::string{ playerName + " " + scoreString };
        }
        catch (const std::bad_alloc& ex)
        {
            std::cerr << ex.what() << std::endl;
            return std::string{};
        }
    }

    const Player&        operator=(const Player& other);
    friend std::istream& operator>>(std::istream& is, Player& player);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    std::string   playerName = "";
    std::uint32_t score{};
};

class Scoreboard
{
public:
    explicit Scoreboard(const char* scoreboardPath, sf::Font& font);

    void write();
    void draw(sf::RenderWindow& window);

private:
    const char*          mScoreboardPath;
    std::vector<Player>  mPlayers;
    std::vector<Textbox> mTextboxes;

    std::vector<Player>::iterator mCurrentPlayer;
};

#endif  // BREAKOUT_SCOREBOARD_HPP
