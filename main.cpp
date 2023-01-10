//
// main.cpp
// Created on 21/10/2018
//

#include "photo.h"
#include "video.h"
#include <iostream>
#include <string>
#include <ostream>
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia * m1 = new Photo();
    Multimedia * m2 = new Video("name2", "pathname2", 12);
    Multimedia * m3 = new Photo("name3", "pathname3", 1.3, 5.3);

    Multimedia * tab[] = {m1, m2, m3};

    for (int k = 0; k < 10; k++) {
        tab[k]->display(std::cout);
    }

    delete m1;
    delete m2;
    return 0;
}
