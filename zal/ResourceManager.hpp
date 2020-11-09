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

    ResourceManager(const ResourceManager& a)
    // konstruktor kopiujacy
    {
        d = new Resource;
        *d = *a.d;
    }

    ResourceManager(ResourceManager&& c) // move constructor
    {
        d   = c.d;
        c.d = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& c) // move operator
    {
        if (&c == this)
            return *this;
        delete d;
        d       = c.d;
        c.d = nullptr;
        return *this;
    }

    ResourceManager& operator=(const ResourceManager& b) // operator przypisania
    {
        if (this != &b)
            *d = *b.d;
        return *this;
    }

     double get() //double get
    {
        return d->get();
    }

    private:
    Resource *d;
};
