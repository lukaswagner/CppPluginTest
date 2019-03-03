#include "dependencyPlugin.hpp"

#include "pluginClasses.hpp"
#include "pluginExports.hpp"

PluginHeader* getHeader()
{
    return new PluginHeader{"Depedent Plugin", 42};
}
