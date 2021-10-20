//Programmer: Emre Guvenilir
//Student ID: efgtnd
//Section: 101
//Date:         10/19/2021
//Purpose: Homework #5: Codemon Academy Zones

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Zone
{
  string zoneName;
  int securityLevel;
  int totalNumOfPotentialViolations;
  
};
struct Entrant
{
  string fName;
  string lName;
  int age;
  string occupation;
  int numOfCodemon;
  int securityLevel;
};
//Pre: None
//Post: ostream Return type
//Description: cout << operator overloaded
ostream & operator << (ostream & os,const Entrant & violator);
//Pre: arr[] must be declared and initialized, and size > 0,
//Post: None
//Description: sortArray(Entrant arr[], const int size) sorts an array from lowest to highest values
void sortArray(Entrant arr[], const int size);
//Pre: arr[] must be declared and initialized, and size > 0,
//Post: None
//Description: sortArray(Entrant arr[], const int size) sorts an array from lowest to highest values
void sortArray(Zone arr[], const int size);
//Pre: All variables must be initialized and declared and MAX_ENTRANTS = 100
//Post: None
//Description: The function reads in the files, and accounts and sorts all the data and potential warnings, and then outputs the needed warnings to an output file
void findWarnings(Entrant roomArray[], const int MAX_ENTRANTS, string openFileName,string outputFile,Zone zoneName,int warnings,Zone warningsArray[],const int MAX_STUDENT_AGE);