#include "ReadTeam.h"

ReadTeam::ReadTeam()
{
 //empty constructor
}

Team* ReadTeam::ReadTeamData(char* teamName)
{
    ifstream teamReader(teamName); //opens the text file
    teamReader.open(teamName);

    string name, teamname, teamC; //needed for team name, player name, and playercount reads
    int teamCount, playerID;//needed for the ID pull
    
    getline(teamReader, teamname); //stores team name.
    teamReader >> teamCount; //stores player count for iterations

    Team* teamActual= new Team(teamname, teamCount);//creates teamRoster in Team to hold players
    for(int c = 0; c < teamCount; c++) //iterates thru players
    {
      teamReader >> playerID; //reads in the whole number as a string
      teamReader >> name; //gets the player name
      Player* temp = new Player(playerID, name, teamCount, teamname); // creates player object
      teamActual->addMember(temp , c); //pushes the new player onto the heap of players
      if(teamReader.eof()) //exit the for statement if at eof but for-loop is not finished (avoids bounding error)
        break;
    }

    teamReader.close(); //close read object

    return teamActual;
}
