#include "readMatchraw.h"

readMatchraw::readMatchraw()
{
    //empty constructor

}
void readMatchraw::readRawData(char * matchData, Team* teamActual)
{
    ifstream matchRead(matchData);
    matchRead.open(matchData);

    int numTags, playerID, taggedID, timestamp, location;//int variables for conversion
    matchRead >> numTags; //get number of tags in the match file
    
    for (int c = 0; c < numTags-1; c++)
    {
     matchRead >> playerID;  //fileformat: int int int int: Shooter, Target, time from matchstart, hit location
     matchRead >> taggedID;
     matchRead >> timestamp;
     matchRead >> location;
    
    //transfers data to various arrays
    teamActual->touchRoster(playerID, taggedID, location);
    if (matchRead.eof())
    {
        matchRead.close();
        return;

    }
    }

}
