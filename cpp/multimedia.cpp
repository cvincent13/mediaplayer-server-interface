#include "multimedia.h"
#include <iostream>
#include <ostream>
#include <string>



Multimedia::Multimedia(std::string name, std::string pathname)
{
    this->name = name;
    this->pathname = pathname;
}

Multimedia::Multimedia()
{
    name = "";
    pathname = "";
}

void Multimedia::setName(std::string name)
{
    this->name = name;
}

void Multimedia::setPathname(std::string pathname)
{
    this->pathname = pathname;
}

std::string Multimedia::getName() const
{
    return name;
}

std::string Multimedia::getPathname() const
{
    return pathname;
}

Multimedia::~Multimedia()
{
    std::cout << name << " destroyed" << std::endl;
}

void Multimedia::display(std::ostream & s) const
{
    s << "Name: " << name << ", Pathname:  " << pathname;
}
