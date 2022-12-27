//
// main.cpp
// Created on 21/10/2018
//

#include "multimedia.h"
#include <iostream>
#include <string>
#include <ostream>
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia * m1 = new Multimedia();
    Multimedia * m2 = new Multimedia("name2", "pathname2");
    Multimedia * m3 = new Multimedia("name3", "pathname3");
    m1->display(std::cout);
    m2->display(std::cout);
    m3->display(std::cout);

    delete m1;
    delete m2;
    return 0;
}
