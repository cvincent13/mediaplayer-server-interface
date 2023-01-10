#include "film.h"

void Film::setChapters(int * chapters, int chapters_number)
{
    delete this->chapters;
    this->chapters = chapters;
    this->chapters_number = chapters_number;
}

int * Film::getChapters()
{
    return chapters;
}

void Film::displayChapters(std::ostream & s)
{
    for (int k = 0; k < chapters_number; k++){
        s << "Chapter " << k << ": duration = " << chapters[k] << std::endl;
    }
}


