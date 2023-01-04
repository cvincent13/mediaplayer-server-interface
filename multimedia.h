#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H


#include <string>
#include <ostream>

class Multimedia
{
private:
    std::string name{};
    std::string pathname{};

public:
    Multimedia();

    Multimedia(std::string name, std::string pathname);

    void setName(std::string name);

    void setPathname(std::string pathname);

    std::string getName() const;

    std::string getPathname() const;

    ~Multimedia();

    virtual void display(std::ostream & s) const;

    virtual void play() const = 0;
};

#endif // MULTIMEDIA_H
