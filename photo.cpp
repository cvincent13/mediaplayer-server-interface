#include "photo.h"

void Photo::setLatitude(float latitude)
{
    this->latitude = latitude;
}

void Photo::setLongitude(float longitude)
{
    this->longitude = longitude;
}

float Photo::getLatitude() const
{
    return latitude;
}

float Photo::getLongitude() const
{
    return longitude;
}

void Photo::display(std::ostream & s) const
{
    Multimedia::display(s),
            s << ", LatitudehbjghbgCCCCCc: " << latitude
              << ", Longitude: " << longitude << std::endl;
}

void Photo::play() const
{
    system(("imagej " + getPathname() + " &").data());
}
