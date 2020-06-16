
#include "Scoreboard.hpp"

#include <fstream>

std::istream& operator>>(std::istream& is, Player& player)
{
    return is >> player.playerName >> player.score;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    return os << player.playerName << std::setw(10) << player.score << "\n";
}

Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        score      = other.score;
        playerName = other.playerName;
    }
    return *this;
}

Scoreboard::Scoreboard(const char* scoreboardPath, sf::Font& font)  //
    : mScoreboardPath{ scoreboardPath }
    , mPlayers{}
    , mCurrentPlayer{}
    , mFont{ font }
{
    std::ifstream inScoreboard(mScoreboardPath);
    if (inScoreboard.is_open())
    {
        std::istream_iterator<Player> in(inScoreboard), eof;
        std::copy(in, eof, std::back_inserter(mPlayers));
    }

    std::transform(mPlayers.begin(), mPlayers.end(), std::back_inserter(mTextboxes), ConvertPlayerToTextbox(mFont));
}
void Scoreboard::sort()
{
    if (mPlayers.size() > 1)
    {
        std::sort(
                std::begin(mPlayers),
                std::end(mPlayers),
                [](const Player& first, const Player& second)  //
                {                                              //
                    return first.score > second.score;
                });
    }
}

void Scoreboard::write()
{
    sort();

    std::transform(mPlayers.begin(), mPlayers.end(), std::back_inserter(mTextboxes), ConvertPlayerToTextbox(mFont));

    {
        std::ofstream outScoreboard(mScoreboardPath);

        if (outScoreboard.is_open())
        {
            std::ostream_iterator<Player> it(outScoreboard, "\n");
            std::copy(std::begin(mPlayers), std::end(mPlayers), it);
        }
    }
}

void Scoreboard::draw(sf::RenderWindow& window)
{
    // Not everyone deserves to be on scoreboard ;)
    int i = 0;
    for (auto& textbox : mTextboxes)
    {
        if (i < 4)
        {
            textbox.draw(window);
        }
        ++i;
    }
}

void Scoreboard::increaseCurrentPlayerScore(const int increaseNumber)
{
    mCurrentPlayer->score += increaseNumber;
}

void Scoreboard::newPlayer(const Player& newPlayer)
{
    mPlayers.emplace_back(newPlayer);
    mCurrentPlayer = mPlayers.end() - 1;
}
