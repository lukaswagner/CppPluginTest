#include "pluginLoader.hpp"
#include <iostream>

#ifdef FILESYSTEM_IS_EXPERIMENTAL
#include <experimental/filesystem>
namespace filesystem = std::experimental::filesystem;
#else
#include <filesystem>
namespace filesystem = std::filesystem;
#endif

int main(const int argc, char const *argv[])
{
    filesystem::path p;

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

    const auto header = pl.getHeader();
    std::cout << "Successfully loaded plugin \"" << header->m_name << "\" with version " << header->m_version << "." << std::endl;

    return 0;
}
