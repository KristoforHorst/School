#ifndef READTEAM_H
#define READTEAM_H

#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Team.h"


using namespace std;

class ReadTeam
{
public:
    ReadTeam();
    Team* ReadTeamData(char*);
};

#endif // READTEAM_H
