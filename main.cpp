#include "Player.h"
#include "readMatchraw.h"
#include "ReadTeam.h"
#include "WriteMatch.h"




#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
//cout << argc << endl;
//cout << "Argv1"<< argv[1] << endl;
//cout << "Argv2" << argv[2] << endl;
//cout << "Argv3"<< argv[3] << endl;
//cout << "Argv4" << argv[4] << endl;
//cout << "Arg5" << argv[5] << endl;


   if (argc != 6)
   {
       cout << "Please enter two team files and a match file, the name of your expected output file, and the verbosity.";
       return 1;
   }
       else
   {
   ReadTeam rt;
   readMatchraw rr;
   WriteMatch mw;
   Team* team1 = rt.ReadTeamData(argv[1]);//writes both teams to memory
   Team* team2 = rt.ReadTeamData(argv[2]);
   rr.readRawData(argv[3], team1); 
   rr.readRawData(argv[3], team2);
   mw.writeMatchOutput(argv[4], argv[5], team1, team2); //check these arguments
   }

    return 0;
}
