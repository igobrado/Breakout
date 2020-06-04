#ifndef BREAKOUT_MANAGER_HPP
#define BREAKOUT_MANAGER_HPP
#include "tinyxml2.h"

class IManager
{
public:
    virtual ~IManager() = default;

protected:
    virtual void Load(tinyxml2::XMLElement* startPos, const char* moduleName, const char* componentName) = 0;
};

template <typename ManagerType>
class Manager : public IManager
{
public:
    Manager(const char* xmlFilePath)
            : mXmlFile()
    {
        mXmlFile.LoadFile(xmlFilePath);
    }

protected:
    tinyxml2::XMLDocument mXmlFile;
};
#endif  // BREAKOUT_MANAGER_HPP
