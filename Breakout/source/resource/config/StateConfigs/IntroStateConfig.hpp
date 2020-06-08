#include "../Config.hpp"

class IntroStateConfig : public Config
{

public:
    explicit IntroStateConfig(const char* xmlFilePath)
    /**@copydoc Config::configure()*/
    void configure() override;

private:

}