#include "WriteMatch.h"

WriteMatch::WriteMatch()
{
//empty constructor
}

void WriteMatch::writeMatchOutput(char* matchFile, char* verbosity, Team* team1, Team* team2)
{

    ofstream writeObject(matchFile);
    writeObject.open(matchFile);
    int firstTeamScore =0;
    int secondTeamScore =0;
   

    if ( strcmp(verbosity,"low"))
    {  
       for(int index = 0; index < team1->arrayBounds(); index++)
        firstTeamScore += team1->accessPlayer(index)->getPlayer(verbosity); //sums the player's tag score
       for(int index = 0; index < team2->arrayBounds(); index++)
        secondTeamScore =+ team2->accessPlayer(index)->getPlayer(verbosity);
 
          writeObject << team1->accessPlayer(0)->whatTeam() << ":" << firstTeamScore <<endl; //The team names will change between executions
          writeObject << team2->accessPlayer(0)->whatTeam() << ":" << secondTeamScore << endl; //but the players always know their team.
         if(firstTeamScore > secondTeamScore)
            {
            writeObject << "Overall winners: " << team1->accessPlayer(0)->whatTeam() << endl;
            }
        else
             writeObject << "Overall winners: " << team2->accessPlayer(0)->whatTeam() << endl;
    }
    else if (strcmp(verbosity,"medium"))
    {  
        Player* who1 = new Player();
        Player* who2 = new Player(); //creates 2 player pointers to store high scorers later
       writeObject << team1->accessPlayer(0)->whatTeam();
           for(int index = 0; index < team1->arrayBounds(); index++)
           {//gets player's total tags

               writeObject << team1->accessPlayer(index)->playerName << " scored " << team1->accessPlayer(index)->getPlayer(verbosity) << " total tags." << endl;
           }

           for(int index = 0; index < team2->arrayBounds(); index++)
           {
               writeObject << team2->accessPlayer(index)->playerName << " scored " << team2->accessPlayer(index)->getPlayer(verbosity) << " total tags." << endl;
           }

           for(int index = 0; index < team1->arrayBounds(); index++)
           {//determines the highest scoring member of both teams
                who1 = highScore(who1, team1->accessPlayer(index));
           }
            
           for(int index = 0; index < team2->arrayBounds(); index++)
           {
                who2 = highScore(who2, team2->accessPlayer(index));
           }
           writeMatchOutput(matchFile, "low", team1, team2); //utilizes the lower verbosity to finish the write

    }
    else if (strcmp(verbosity,"high"))
    {
        writeObject << team1->accessPlayer(0)->whatTeam();
        for(int index = 0; index < team1->arrayBounds(); index++)
         for(int index2 = 0; index2 < team1->arrayBounds(); index2++)
            for(int interior = 1; interior < 1+2*team1->arrayBounds(); interior++)
            {
            if( team2->accessPlayer(index2)->playerID == interior)
            writeObject << team1->accessPlayer(index)->playerName << " tagged " << team2->accessPlayer(index2)->playerName << " a total of " <<
            team1->accessPlayer(index)->getTagged(interior) << " times.";
            }
            for(int index = 0; index < team1->arrayBounds(); index++)
                firstTeamScore += team1->accessPlayer(index)->getPlayer(verbosity); //sums the player's tag score
            writeObject << team1->accessPlayer(0)->whatTeam() << " : " << firstTeamScore << " points." << endl;


        writeObject << team2->accessPlayer(0)->whatTeam();
        for(int index = 0; index < team2->arrayBounds(); index++)
           for(int index2 = 0; index2 < team1->arrayBounds(); index2++)
            for(int interior = 1; interior < 1+2*team1->arrayBounds(); interior++)
            {
            if(team1->accessPlayer(index2)->playerID == interior)
            writeObject << team2->accessPlayer(index)->playerName << " tagged " << team1->accessPlayer(index2)->playerName << " a total of " <<
            team2->accessPlayer(index)->getTagged(interior) << " times.";
            }  
            for(int index = 0; index < team2->arrayBounds(); index++)
                secondTeamScore =+ team2->accessPlayer(index)->getPlayer(verbosity);
           writeObject << team2->accessPlayer(0)->whatTeam() << " : " << secondTeamScore << " points." << endl;
           if(firstTeamScore > secondTeamScore)
            {
            writeObject << "Overall winners: " << team1->accessPlayer(0)->whatTeam() << endl;
            }
        else
             writeObject << "Overall winners: " << team2->accessPlayer(0)->whatTeam() << endl;


    }
    else
        cout << "Please enter low, medium, or high for your verbosity value." << endl;




    writeObject.close();
    return;
}

Player* WriteMatch::highScore(Player* first, Player* second)
{
if(first->getPlayer("low") > second->getPlayer("low"))
    return first;
else
    return second;

}