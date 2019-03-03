#include "minimalPlugin.hpp"

#include "pluginClasses.hpp"
#include "pluginExports.hpp"

// just return the header, nothing else
PluginHeader* getHeader()
{
    return new PluginHeader{"Minimal Plugin", 42};
}
