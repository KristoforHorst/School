#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "Player.h"

class Team
{
public:
    Team();
    Team(string, int);
    void addMember(Player*, int);
    int arrayBounds();
    void touchRoster(int&, int&, int&);
    Player* accessPlayer(int num);
private:
    int playersPerTeam;
	Player* teamRoster[];  
};

#endif // TEAM_H
