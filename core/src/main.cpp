#include "pluginLoader.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        std::cout << "Please provide the name of / path to the plugin." << std::endl;
        return -1;
    }

    auto pl = PluginLoader(argv[1]);
    if(!pl)
    {
        std::cout << "Could not load the plugin." << std::endl;
        return -1;
    }

    auto header = pl.getHeader();
    std::cout << "Successfully loaded plugin \"" << header->m_name << "\" with version " << header->m_version << "." << std::endl;

    return 0;
}
