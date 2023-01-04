#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"
class Photo : public Multimedia
{
private:
    float latitude{}, longitude{};

public:
    Photo() : latitude{0}, longitude{0}{};

    Photo(std::string name, std::string pathname, float latitude, float longitude) :
        Multimedia(name, pathname), latitude{latitude}, longitude{longitude}{};

    void setLatitude(float latitude);

    void setLongitude(float longitude);

    float getLatitude() const;

    float getLongitude() const;

    void display(std::ostream & s) const;

    void play() const;



};

#endif // PHOTO_H
