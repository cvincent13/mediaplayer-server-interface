#ifndef FILM_H
#define FILM_H


#include "video.h"
class Film : public Video
{
private:
    int * chapters;
    int chapters_number;
public:
    Film() : chapters{nullptr}, chapters_number{0}{};
    Film(std::string name, std::string pathname, int duration,
         int * chapters, int chapters_number) :
        Video(name, pathname, duration),
        chapters{chapters}, chapters_number{chapters_number}{};
    void setChapters(int * chapters, int chapters_number);
    int * getChapters();
    void displayChapters(std::ostream & s);
};

#endif // FILM_H
