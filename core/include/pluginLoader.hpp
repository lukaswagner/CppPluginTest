#pragma once

#include <string>
#include "pluginClasses.hpp"

class PluginLoader
{
private:
    void* m_libHandle = nullptr;
    PluginHeader* m_header = nullptr;
    static void printError();
    bool getFunc(const std::string&, void*& func) const;
public:
    explicit PluginLoader(const std::string& name);
    ~PluginLoader();
    explicit operator bool() const;
    PluginHeader* getHeader() const;
};
