#ifndef READMATCHRAW_H
#define READMATCHRAW_H

#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Team.h"

using namespace std;

class readMatchraw
{
public:
    readMatchraw();
    void readRawData(char*, Team*);
};

#endif // READMATCHRAW_H
