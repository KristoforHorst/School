#include "Player.h"

Player::Player()
{
teamName = "Demonstrative Dingos";
playerName = "Default Dave";
playerID = -1;
for(int i = 0; i < 5; i++)
locations[i] = 0;

}

Player::Player(int id, string name, int totalPlayers, string stringN)
{
    teamName = stringN;
    playerID = id;
    playerName = name;
    totalPlayers = 2*(totalPlayers +1);
    playerTagged = new int[totalPlayers]; //assuming reading lowest team, accounting for uneven teams. 
}

int Player::getTagged(int index)
{
  return playerTagged[index];
}

int Player::getPlayer(string verbose)
{

    int totalScore;
    if (verbose == "high")
    {

     


    }
    else if (verbose == "medium")
    {
        return locations[0]; //total tags

    }
    else 
    {
        totalScore = (locations[1] * 5) + (locations[2] * 8) + (locations[3] * 10) + (locations[4] * 15);
        return totalScore;
    }
}

string Player::whatTeam()
{
    return teamName;
}

void Player::setPlayer(string name, int id)
{
    playerID = id;
    playerName = name;
}

void Player::setTagged(int &id, int &loc)
{
    playerTagged[id]++; //increments player tags
    locations[0]++; //increments total tag
    locations[loc]++; //increments specific tag
}
