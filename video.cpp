#include "video.h"

void Video::setDuration(int duration)
{
    this->duration = duration;
}

int Video::getDuration() const
{
    return duration;
}

void Video::display(std::ostream & s) const
{
    Multimedia::display(s), s << ", Duration: " << duration << std::endl;
}

void Video::play() const
{
    system(("mpv " + getPathname() + " &").data());
}
