#include "TrafficlightClass.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#define maxcars 100
#define DurationForYellowLight 4
#define MaxTrafficlights 4
inline void
printTrafficState( TrafficLight *(Traffic_Light_In_Intersection)[4]) {
  for (int e = 0; e < MaxTrafficlights; e++) {
    cout << "traffic light "
         << Traffic_Light_In_Intersection[e]->getTrafficLightID() << " is "
         << Traffic_Light_In_Intersection[e]->getstate() << endl; //print the traffic id and its corresponding state
  }
}
inline void NewcycleHeader() {
  cout << endl
       << "A NEW CYCLE BEGINS" << endl
       << endl
       << "TrafficLight ID:" << setw(25) << "Green time(sec):"
       << "     "
       << "Number of cars in Traffic Light:" << endl;
}
inline void instruction() {
  // print welcome message and how to read the simulation
  cout << endl
       << "Welcome Traffic Management Employee " << endl
       << endl
       << "The simulation will begin shortly.." << endl
       << "The simulation will update from the traffic light file (containing "
          "plate numbers & speed) at the end of each traffic cycle "
       << endl
       << "If there is an increase in the traffic rate of a traffic light, a "
          "status update will occur: "
       << endl
       << "Green: indicates no potential traffic congestion" << endl
       << "Yellow: indicates a potential traffic congestion, traffic light "
          "lane should be monitored "
       << endl
       << "Red: indicates a traffic congestion, traffic management procedures "
          "must take place "
       << endl
       << "Here are the current status of the traffic lights in intersection"
       << endl;
  NewcycleHeader();
}
// evaluate if a traffic light has the potential to become a cause for traffic
// congestion
void PotentialTraffic(int &x,
                      TrafficLight *(Traffic_Light_In_Intersection)[4],
                      int &finalcounter) {
  cout <<endl<< "WARNING: Traffic Light with ID: "
       << Traffic_Light_In_Intersection[x]->getTrafficLightID()
       << " has an increase in number of cars" << endl;
  // if the cars in file are less than 10 its safe, if less than 20 possible
  // traffic, otherwise traffic congestion
  if (finalcounter < 10) {
    cout <<endl<< "The Traffic level is green" << endl;
  } else if (finalcounter < 20) {
    cout <<endl<< "Traffic level is yellow" << endl;
  } else
    cout <<endl<< "Traffic level is red" << endl<<"Traffic Light Speed limit has been adjusted to 40 Km/h"<<endl;
  Traffic_Light_In_Intersection[x]->setspeedlimit(40);
}