#pragma once

#include <string>
#include <vector>
#include <tuple>

struct PluginHeader
{
    std::string m_name;
    int m_version;
};

typedef PluginHeader* pluginHeaderFunc(void);
