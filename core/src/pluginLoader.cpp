#include "pluginLoader.hpp"

#include <iostream>
#include "pluginClasses.hpp"

#if defined(WIN32) || defined(_WIN32)
#define WINDOWS
#include <Windows.h>
#else
#include <dlfcn.h>
#endif

void PluginLoader::printError()
{
    #ifdef WINDOWS
    const auto id = GetLastError();
    char* message;
    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr,
        id,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<LPSTR>(&message),
        0,
        nullptr);
    std::cout << "Error " << id << ": " << message;
    #else
    std::cout << "Error " << dlerror() << std::endl;
    #endif
}

bool PluginLoader::getFunc(const std::string& name, void*& func) const
{
    #ifdef WINDOWS
    const auto ptr = GetProcAddress(static_cast<HMODULE>(m_libHandle), name.c_str());
    #else
    const auto ptr = dlsym(m_libHandle, name.c_str());
    #endif

    if(ptr == nullptr)
    {
        printError();
        return false;
    }

    func = ptr;
    return true;
}

PluginLoader::PluginLoader(const std::string& name)
{
    #ifdef WINDOWS
    const auto libHandle = LoadLibraryA(name.c_str());
    #else
    const auto libHandle = dlopen(name.c_str(), RTLD_LAZY);
    #endif

    if(libHandle == nullptr)
    {
        printError();
        return;
    }

    m_libHandle = libHandle;

    void* headerFunc = nullptr;

    if(getFunc("getHeader", headerFunc))
    {
        m_header = reinterpret_cast<pluginHeaderFunc*>(headerFunc)();
    }
}

PluginLoader::~PluginLoader()
{
    // library allocated this header when getPluginHeader was called - don't forget to delete it
    delete m_header;

    #ifdef WINDOWS
    if(!FreeLibrary(static_cast<HMODULE>(m_libHandle)))
    {
        printError();
    }
    #else
    if(dlclose(m_libHandle) != 0)
    {
        printError();
    }
    #endif
}

PluginLoader::operator bool() const
{
    return m_libHandle != nullptr && m_header != nullptr;
}

PluginHeader* PluginLoader::getHeader() const
{
    return m_header;
}
