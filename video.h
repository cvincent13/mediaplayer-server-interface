#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
class Video : public Multimedia
{
private:
    int duration{};
public:
    Video() : duration{0}{};
    Video(std::string name, std::string pathname, int duration) :
        Multimedia(name, pathname), duration{duration}{};

    void setDuration(int duration);

    int getDuration() const;

    void display(std::ostream & s) const;

    void play() const;


};

#endif // VIDEO_H
