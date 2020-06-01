#ifndef BREAKOUT_BREAKOUT_HPP
#define BREAKOUT_BREAKOUT_HPP

#include "Application.hpp"

namespace game
{
    struct ScreenDimensions
    {
        std::uint32_t width;
        std::uint32_t height;
    };
    class Breakout : public Application
    {
    public:
        explicit Breakout(const ScreenDimensions dimensions);
         ~Breakout() = default;
         int run() override;

    protected:
        void loop() override;

    private:
        const ScreenDimensions mScreenDimensions;
    };
}




#endif //BREAKOUT_BREAKOUT_HPP
