//Programmer: Emre Guvenilir
//Student ID: efgtnd
//Section: 101
//Date:         10/19/2021
//Purpose: Homework #5: Codemon Academy Zones

#include <iostream>
#include <string>
#include <fstream>
#include "helper.h"

using namespace std;

int main()
{
  const string libraryOutput = "libraryOutput.log.txt";//trainingRoomOutput = "trainingRoomOutput.log.txt";

  Zone library,trainingRoom,facultyLounge,chamberOfEkans;
  library.zoneName = "Library";
  trainingRoom.zoneName = "Training Room";
  facultyLounge.zoneName = "Faculty Lounge";
  chamberOfEkans.zoneName = "Chamber of Ekans";

  const int MAX_ENTRANTS=100,LIBRARY_SECURITY=1,TRAINING_ROOM_SECURITY=2,FACULTY_LOUNGE_SECURITY=3,CHAMBER_OF_EKANS_SECURITY=4,MAX_STUDENT_AGE = 30,NUM_OF_ZONES=4;
  const string libraryFile = "the_library.log",trainingRoomFile = "training_room.log",facultyLoungeFile = "faculty_lounge.log",chamberOfEkansFile= "the_chamber_of_ekans.log";
  const int LIBRARY_INDEX=0,TRAINING_INDEX=1,FACULTY_INDEX=2,CHAMBER_OF_EKANS_INDEX=3;
  const string trainingRoomOutput = "trainingRoomOutput.log.txt",facultyLoungeOutput = "facultyLoungeOutput.log.txt",chamberOfEkansOutput = "chamberOfEkansOutput.log.txt";

  library.securityLevel= LIBRARY_SECURITY;
  trainingRoom.securityLevel=TRAINING_ROOM_SECURITY;
  facultyLounge.securityLevel=FACULTY_LOUNGE_SECURITY;
  chamberOfEkans.securityLevel=CHAMBER_OF_EKANS_SECURITY;
  Zone warningsArray[NUM_OF_ZONES] = {library,trainingRoom,facultyLounge,chamberOfEkans};

  Entrant libraryArr[MAX_ENTRANTS];
  Entrant trainingRoomArr[MAX_ENTRANTS];
  Entrant facultyLoungeArr[MAX_ENTRANTS];
  Entrant chamberOfEkansArr[MAX_ENTRANTS];

  findWarnings(libraryArr,MAX_ENTRANTS,libraryFile,libraryOutput,library,LIBRARY_INDEX,warningsArray,MAX_STUDENT_AGE);
  findWarnings(trainingRoomArr,MAX_ENTRANTS,trainingRoomFile,trainingRoomOutput,trainingRoom,TRAINING_INDEX,warningsArray,MAX_STUDENT_AGE);
  findWarnings(facultyLoungeArr,MAX_ENTRANTS,facultyLoungeFile,facultyLoungeOutput,facultyLounge,FACULTY_INDEX,warningsArray,MAX_STUDENT_AGE);
  findWarnings(chamberOfEkansArr,MAX_ENTRANTS,chamberOfEkansFile,chamberOfEkansOutput,chamberOfEkans,CHAMBER_OF_EKANS_INDEX,warningsArray,MAX_STUDENT_AGE);

  //Summary Section
  cout << "Summary\n";
  sortArray(warningsArray,NUM_OF_ZONES);
  for(int a=0;a<NUM_OF_ZONES;a++)
  {
    cout << "\n" << warningsArray[a].zoneName << ": " << warningsArray[a].totalNumOfPotentialViolations << " potential violations";
  }
  cout<< endl;
  return 0;
}