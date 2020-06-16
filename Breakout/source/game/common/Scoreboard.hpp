#ifndef BREAKOUT_SCOREBOARD_HPP
#define BREAKOUT_SCOREBOARD_HPP

#include <cinttypes>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "private/Textbox.hpp"

/**
 * @brief Represents player which is playing the game.
 *
 * Player struct holds player name and player's score.
 * Every instance of player shall be unique.
 */
struct Player
{
    Player() = default;
    explicit Player(std::string name)  //
        : playerName{ std::move(name) }
        , score{ 0U }
    {
    }

    /**
     * @brief Convert's player score and name to single string.
     *
     * @note Even if method is using std::to_string() for converting score (which is a number),
     * this method won't throw!
     *
     * @return valid string if conversion happen, if not string which will be returned shall be empty.
     */
    [[nodiscard]] std::string toString() const noexcept
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

    Player&              operator=(const Player& other);
    friend std::istream& operator>>(std::istream& is, Player& player);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    std::string   playerName = "";
    std::uint32_t score{};
};

class Scoreboard
{
public:
    explicit Scoreboard(const char* scoreboardPath, sf::Font& font);

    /**
     * @brief Sorts vector of players in ascending order.
     */
    void sort();

    /**
     * @brief Sort's vector of players in ascending order and output's it to file.
     */
    void write();

    /**
     * @brief Draws the scoreboard on window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Increases current player's score by the given number.
     *
     * @param increaseNumber
     */
    void increaseCurrentPlayerScore(const int increaseNumber);

    void newPlayer(const Player& newPlayer);

private:
    const char*          mScoreboardPath;
    std::vector<Player>  mPlayers;
    std::vector<Textbox> mTextboxes;
    sf::Font&            mFont;

    std::vector<Player>::iterator mCurrentPlayer;

    /**
     * @brief Callable object which shall be called only to convert player object to printable player object.
     */
    struct ConvertPlayerToTextbox
    {
        explicit ConvertPlayerToTextbox(sf::Font& font)  //
            : i{ 1 }
            , xBegin{ 300 }
            , yBegin{ 100 }
            , font{ font }
        {
        }

        Textbox operator()(const Player& player)
        {
            try
            {
                std::string tmp = std::to_string(i);
                tmp += " " + player.toString();

                Textbox tb{ static_cast<uint32_t>(xBegin),
                            static_cast<uint32_t>(yBegin),
                            font,
                            sf::Color::Red,
                            tmp.c_str() };
                yBegin += 200;
                ++i;
                return tb;
            }
            catch (const std::bad_alloc& ex)
            {
                std::cerr << ex.what() << std::endl;
            }
            return Textbox{ 0, 0, font, sf::Color::Black, "" };
        }

    private:
        std::uint8_t  i;
        std::uint32_t xBegin;
        std::uint32_t yBegin;
        sf::Font&     font;
    };
};

#endif  // BREAKOUT_SCOREBOARD_HPP
