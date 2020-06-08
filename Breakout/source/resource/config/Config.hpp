#ifndef BREAKOUT_CONFIG_HPP
#define BREAKOUT_CONFIG_HPP

class Config
{
public:
    virtual ~Config() = default;

    /**
     * @brief Loads provided config.
     * 
     * @note Loads config and configures scene with provided definitions.
     * 
     */
    virtual void configure() = 0;
}

#endif // BREAKOUT_CONFIG_HPP