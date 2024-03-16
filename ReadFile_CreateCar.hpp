#include <cmath>
#include "TrafficlightClass.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#define maxcars 100
#define DurationForYellowLight 4
#define MaxTrafficlights 4
using namespace std;
template <typename T, typename U, typename Z>
T ReadCarInfo(Z filename, T (&carplate)[maxcars][MaxTrafficlights],
                U (&speed)[maxcars][MaxTrafficlights],
                T &TrafficLightId) {
  string temp = " "; //initialize string
  ifstream infile; //file opening 
  infile.open(filename);
  if(infile.fail()){
    cout << "File failed to open"<<endl;
  }
  int numoflines = 0;
  while (getline(infile, temp)) {
    numoflines++; //count number lines in file
  }
  numoflines--; // remove the header line from the counter
  infile.clear();
  infile.seekg(0);// start from the top of file
  int counter = 0; 
  getline(infile, temp);
  while (counter < numoflines) { // store plate number and speed into 2darray
    infile >> carplate[counter][TrafficLightId] >>
        speed[counter][TrafficLightId];
    counter++; // count number of cars
  }
  infile.close(); //close file
  return counter;
}
void CreateCarObject(int &counter, int (&carplate)[maxcars][MaxTrafficlights],
                     double (&speed)[maxcars][MaxTrafficlights],
                     TrafficLight *(Traffic_Light_In_Intersection)[4]
              , int &TrafficLightId) {
  for (int f = 0; f < counter; f++) { // create car object
    if (carplate[f][TrafficLightId] != 0) { //if the array element holds car information, create a car object with the corresponding car information
      Traffic_Light_In_Intersection[TrafficLightId]->addcar(
          car(carplate[f][TrafficLightId], speed[f][TrafficLightId]));
    }
  }
  
}

