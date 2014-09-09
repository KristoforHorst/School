#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
    Player();
    Player(int, string, int, string);
    int playerID;
    string playerName;
    int getPlayer(string);
    int getTagged(int);
    void setPlayer(string, int);
    void setTagged(int&, int&);
    string whatTeam();
private:
    string teamName;
    int* playerTagged;//holds enough spaces for every player to have thier own
    int locations[4], totalPlayers;
};

#endif // PLAYER_H
