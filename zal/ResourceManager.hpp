#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:

    ResourceManager()   //konstruktor domyslny
    {
      d = new Resource;
    }

    ~ResourceManager()  //destruktor
    {
      delete d;
    }

    ResourceManager(const ResourceManager& d)
    // konstruktor kopiujacy
    {
        d = new Resource;
        Resource = d.Resource;
    }

    ResourceManager(ResourceManager&& d) // move constructor
    {
        Resource   = d.Resource;
        d.Resource = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& other) // move operator
    {
        if (&other == this)
            return *this;
        delete Resource;
        Resource       = other.Resource;
        other.Resource = nullptr;
        return *this;
    }

    ResourceManager& operator=(const ResourceManager& d) // operator przypisania
    {
        if (this != &d)
            *Resource = *d.Resource;
        return *this;
    }

     double get()
    {
        return d;
    }

    private:
    Resource *d;
};
