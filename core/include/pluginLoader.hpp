#pragma once

#include <string>
#include "pluginClasses.hpp"

class PluginLoader
{
private:
    void* m_libHandle = NULL;
    PluginHeader* m_header = NULL;
    void printError();
    bool getFunc(std::string, void*& func);
public:
    PluginLoader(std::string name);
    ~PluginLoader();
    operator bool() const;
    PluginHeader* getHeader();
};
