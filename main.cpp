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
    Photo * m1 = new Photo();
    Video * m2 = new Video("name2", "pathname2", 12);
    Photo * m3 = new Photo("name3", "pathname3", 1.3, 5.3);
    m1->display(std::cout);
    m2->display(std::cout);
    m3->display(std::cout);

    delete m1;
    delete m2;
    return 0;
}
