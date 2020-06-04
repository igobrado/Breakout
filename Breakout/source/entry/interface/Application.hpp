#ifndef BREAKOUT_APPLICATION_HPP
#define BREAKOUT_APPLICATION_HPP

#include <cstdint>
#include <iostream>

/**
 * @brief Interface for application.
 *
 * If multiple applications needs to run in parallel,
 * they shall inherit from this class.
 */
class Application
{
public:
    Application()          = default;
    virtual ~Application() = default;

    /**
     * @brief Encapsulates main method.
     * @return 0 if exit was successful, -1 if not.
     */
    virtual int run() = 0;

protected:
    /**
     * @brief Encapsulates main loop.
     * @return 0 if exit was successful, -1 if not.
     */
    virtual int loop(float accumulator) = 0;
};

#endif  // BREAKOUT_APPLICATION_HPP
