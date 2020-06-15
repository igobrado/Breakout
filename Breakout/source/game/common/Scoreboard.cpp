
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
    , mIsSorted{ false }
{
    std::ifstream inScoreboard(mScoreboardPath);
    if (inScoreboard.is_open())
    {
        std::istream_iterator<Player> in(inScoreboard), eof;
        std::copy(in, eof, std::back_inserter(mPlayers));
    }

    std::uint32_t xBegin = 300;
    std::uint32_t yBegin = 100;

    std::uint32_t i = 1;
    for (auto& mPlayer : mPlayers)
    {
        try
        {
            std::string tmp = std::to_string(i);
            tmp += " " + mPlayer.toString();

            Textbox tb{ xBegin, yBegin, font, tmp.c_str() };
            mTextboxes.push_back(std::move(tb));
            yBegin += 200;
            ++i;
        }
        catch (const std::bad_alloc& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
    }
}

void Scoreboard::sort()
{
    if ((mPlayers.size() > 1) && (!mIsSorted))
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
    std::for_each(mTextboxes.begin(), mTextboxes.end(), [&window](Textbox& textbox) { textbox.draw(window); });
}

void Scoreboard::increaseCurrentPlayerScore(const int increaseNumber)
{
    mCurrentPlayer->score += increaseNumber;
}

void Scoreboard::newPlayer(const Player& newPlayer)
{
    mPlayers.emplace_back(newPlayer);
    mCurrentPlayer = mPlayers.end();
}
