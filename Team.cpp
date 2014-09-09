#include "team.h"

Team::Team()
{
*teamRoster[1]; //assigns a default value to teamRoster, to be changed later
}
Team::Team(string name, int players)
{   
    playersPerTeam = players;
   *teamRoster = new Player[players]; //sets the number of players on a team
   // Player* teamRoster = static_cast<Player*>(::operator new(sizeof(players)));
   
}

void Team::addMember(Player* p, int num)
{
  teamRoster[num] = p; //adds a member to the teamRoster array
  return;
}

int Team::arrayBounds()
{
    return playersPerTeam;
}

void Team::touchRoster(int& player, int& tagged, int& location)
{
    
    int arrayindex = 0; //this was not intialized, casuing segfault
    
        do{ //will find the player with ID matching tagger
           arrayindex++;
           if (arrayindex == arrayBounds())
           {
                return; //if the ID isn't found, we should ignore the entry
           }          
        }while (teamRoster[arrayindex]->playerID != player); //will exit when it finds the player

    teamRoster[arrayindex]->setTagged(tagged, location); //tells the player he scored a tag on tagged at location
    return;
}

Player* Team::accessPlayer(int num)
{
    return teamRoster[num];
}


