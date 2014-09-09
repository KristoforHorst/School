#ifndef WRITEMATCH_H
#define WRITEMATCH_H

#include <string>
#include <iostream>
#include <fstream>
#include "Team.h"

using namespace std;


class WriteMatch
{
public:
    WriteMatch();
    void writeMatchOutput(char*, char*, Team*, Team*);//two teams, match data
    Player* highScore(Player*, Player*);
};

#endif // WRITEMATCH_H
