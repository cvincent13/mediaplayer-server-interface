#include "film.h"

void Film::setChapters(int * chapters, int chapters_number)
{
    this->chapters_number = chapters_number;
    this->chapters = new int[chapters_number];
    for (int k = 0; k < chapters_number; k++) {
        this->chapters[k] = chapters[k];
    }
}

int * Film::getChapters() const
{
    int * chapters_copy = new int[chapters_number];
    for (int k = 0; k < chapters_number; k++) {
        chapters_copy[k] = chapters[k];
    }
    return chapters_copy;
}

int Film::getChaptersNumber() const
{
    return chapters_number;
}

void Film::displayChapters(std::ostream & s) const
{
    for (int k = 0; k < chapters_number; k++){
        s << "Chapter " << k << ": duration = " << chapters[k] << std::endl;
    }
}
