#include "examplePlugin.hpp"

#include "pluginClasses.hpp"
#include "pluginExports.hpp"

PluginHeader* getHeader()
{
    return new PluginHeader{"Example Plugin", 42};
}
