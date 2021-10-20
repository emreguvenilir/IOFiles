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

ostream & operator << (ostream & os,const Entrant & violator)
{
  os << "\nName: " << violator.fName << " " << violator.lName << "\nAge: " << violator.age << "\nOccupation: " << violator.occupation << "\nNumber Of Codemon Owned: " << violator.numOfCodemon << "\nSecurity Level: " << violator.securityLevel << endl;
  return os;
}
void sortArray(Entrant arr[], const int size)
{
  int minIndex;
  for(int i=0;i<size-1;i++)
  {
    minIndex=i;
    for(int j=i+1;j<size;j++)
    {
      if(arr[j].numOfCodemon < arr[minIndex].numOfCodemon)
      {
        minIndex=j;
      }
    }
    Entrant temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
  return;
}
void sortArray(Zone arr[], const int size)
{
  int minIndex;
  for(int i=0;i<size-1;i++)
  {
    minIndex=i;
    for(int j=i+1;j<size;j++)
    {
      if(arr[j].totalNumOfPotentialViolations > arr[minIndex].totalNumOfPotentialViolations)
      {
        minIndex=j;
      }
    }
    Zone temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
  return;
}
void findWarnings(Entrant roomArray[], const int MAX_ENTRANTS, string openFileName,string outputFile,Zone zoneName, int warnings,Zone warningsArray[],const int MAX_STUDENT_AGE)
{
  const float thirdQuart = 0.75;
  int dataCounter=0;
  ifstream fin;
  ofstream fout;

  fin.clear();
  fout.clear();

  fin.open(openFileName.c_str());
  fout.open(outputFile.c_str());

  for(int i=0;i<MAX_ENTRANTS;i++)
  {
      fin >> roomArray[i].fName;
      fin >> roomArray[i].lName;
      fin >> roomArray[i].age;
      fin >> roomArray[i].occupation;
      fin >> roomArray[i].numOfCodemon;
      fin >> roomArray[i].securityLevel;
      if(roomArray[i].fName != "")
      {
        dataCounter++;
      }
      
  }

  for(int j=0;j<dataCounter;j++)
  {
    if(roomArray[j].age > MAX_STUDENT_AGE && roomArray[j].occupation=="Student")
    {
      zoneName.totalNumOfPotentialViolations += 1;
      warningsArray[warnings].totalNumOfPotentialViolations++;
      fout << roomArray[j] << "Warning: Entrant is classified as student at age " << roomArray[j].age << endl;
     
    }
  }
  for(int h=0;h<dataCounter;h++)
  {
    if(zoneName.securityLevel > roomArray[h].securityLevel)
    {
      zoneName.totalNumOfPotentialViolations++;
      warningsArray[warnings].totalNumOfPotentialViolations++;
      fout << roomArray[h] << "Warning: Entrant with level of " << roomArray[h].securityLevel << " entered a zone of level " << zoneName.securityLevel << endl;
    }
  }
  sortArray(roomArray,dataCounter);

  float thirdQuartile = (thirdQuart)*(dataCounter+1);
  const int thirdQuartileNumber = thirdQuartile-1;
  for(int g=0;g<dataCounter;g++)
  {
    if(roomArray[thirdQuartileNumber].numOfCodemon < roomArray[g].numOfCodemon)
    {
      zoneName.totalNumOfPotentialViolations++;
      warningsArray[warnings].totalNumOfPotentialViolations++;
      fout << roomArray[g] << "Warning: Entrant has too many codemon, entrant has " << roomArray[g].numOfCodemon  << " codemon, the third quartile was " << roomArray[thirdQuartileNumber].numOfCodemon << endl;
    }
  }

  fin.close();
  fout.close();
}
