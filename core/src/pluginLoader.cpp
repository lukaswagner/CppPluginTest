#include "pluginLoader.hpp"

#include <iostream>
#include "pluginClasses.hpp"

#if defined(WIN32) || defined(_WIN32)
#define WINDOWS
#include <windows.h>
#else
#endif

void PluginLoader::printError()
{
    auto id = GetLastError();
    char* message;
    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        id,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR) &message,
        0,
        NULL);
    std::cout << "Error " << id << ": " << message;
}

bool PluginLoader::getFunc(std::string name, void*& func)
{
    auto ptr = GetProcAddress((HMODULE)m_libHandle, name.c_str());

    if(ptr == NULL)
    {
        printError();
        return false;
    }

    func = ptr;
    return true;
}

PluginLoader::PluginLoader(std::string name)
{
    auto libHandle = LoadLibraryA(name.c_str());

    if(libHandle == NULL)
    {
        printError();
        return;
    }

    m_libHandle = libHandle;

    void* headerFunc = NULL;

    if(getFunc("getHeader", headerFunc))
    {
        m_header = ((pluginHeaderFunc*)headerFunc)();
    }
}

PluginLoader::~PluginLoader()
{
    // library allocated this header when getPluginHeader was called - don't forget to delete it
    delete m_header;

    if(!FreeLibrary((HMODULE)m_libHandle))
    {
        printError();
    }
}

PluginLoader::operator bool() const
{
    return m_libHandle != NULL && m_header != NULL;
}

PluginHeader* PluginLoader::getHeader()
{
    return m_header;
}