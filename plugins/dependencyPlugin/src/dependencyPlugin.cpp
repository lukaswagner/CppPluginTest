#include "dependencyPlugin.hpp"

#include "pluginClasses.hpp"
#include "pluginExports.hpp"

PluginHeader* getHeader()
{
    return new PluginHeader{"Dependency Plugin", 42};
}
