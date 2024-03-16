#include "PrintToConsole.hpp"
#include "ReadFile_CreateCar.hpp"
#include "TrafficlightClass.h"
#include "calculategreentime.hpp"
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

int main() {
  // intialize variables
  int NumberofcarsTopassGreen[4] = {0};
  int carplate[maxcars][MaxTrafficlights] = {0};
  double speed[maxcars][MaxTrafficlights] = {0};
  int intialcount[4], finalcount[4], Trafficid_counter = 0;
  //initialize traffic light objects and pointer to traffic light object
  TrafficLight TrafficLight1, TrafficLight2, TrafficLight3, TrafficLight4,
      *Traffic_Light_In_Intersection[4] = {&TrafficLight1, &TrafficLight2,
                                           &TrafficLight3, &TrafficLight4};

  // print instructions
  instruction();

  for (int x = 0; x < MaxTrafficlights; x++) {
    //set speed for each traffic light
    Traffic_Light_In_Intersection[x]->setspeedlimit(75.0);
    string filename = "TrafficLight";
    filename.append(to_string(x + 1)); 
    filename.append(".txt");
    intialcount[x] = ReadCarInfo(filename, carplate, speed, x);
    CreateCarObject(intialcount[x], carplate, speed,
                    Traffic_Light_In_Intersection, x);
  }
  // calculate green time for each traffic light
  for (int x = 0; x < MaxTrafficlights; x++) {
    Traffic_Light_In_Intersection[x]->setgreenTimer(
        Calculategreentime(Traffic_Light_In_Intersection, x));
    Traffic_Light_In_Intersection[x]->printLightInfo();
  }
  cout << endl
       << "Across all Traffic lights the total number of cars that are in "
          "traffic is: "
       << Traffic_Light_In_Intersection[0]->getTotalTrafficFlow() << endl
       << endl;
  // strat time counter
  long now;
  time_t start, end;
  start = time(0);
  // repeat simulation infinitly
  while (true) {
    // check if the time passed is more than the cycletime, if it is, update the
    // values from file, otherwise continue looping the traffic light status
    if (time(0) - start > Traffic_Light_In_Intersection[0]->getcycletime()) {
      start = time(0); // reset timer

      for (int x = 0; x < MaxTrafficlights; x++) {

        string filename = "TrafficLight";
        filename.append(to_string(x + 1)); //update file 
        filename.append(".txt");
        finalcount[x] = 0;
        finalcount[x] = ReadCarInfo(filename, carplate, speed, x);
      }
      Trafficid_counter = 0;
      NewcycleHeader();
      for (int x = 0; x < MaxTrafficlights; x++) {
        if (finalcount[x] >
            intialcount[x]) { // if there are more cars than previous cycle,
                              // update values from file and print warning
                              // message
          intialcount[x] = finalcount[x];
          CreateCarObject(finalcount[x], carplate, speed,
                          Traffic_Light_In_Intersection, x);
          PotentialTraffic(x, Traffic_Light_In_Intersection, finalcount[x]);
        }
      }

      cout << endl;

      // calculate greentime
      for (int x = 0; x < MaxTrafficlights; x++) {
        Traffic_Light_In_Intersection[x]->setgreenTimer(
            Calculategreentime(Traffic_Light_In_Intersection, x));
        // if the lane is empty, set default green as 6 sec
        if (Traffic_Light_In_Intersection[x]->getNumOfCars() == 0) {
          Traffic_Light_In_Intersection[x]->setgreenTimer(6);
        }
        Traffic_Light_In_Intersection[x]->printLightInfo();
      }
    }
    // if less than cycletime continue looping
    else {
      time(&start);
      for (int c = 0; c < MaxTrafficlights; c++) {
        Traffic_Light_In_Intersection[c]->setstate(3);
        NumberofcarsTopassGreen[c] =
            floor(Traffic_Light_In_Intersection[c]
                      ->getgreenTimer()); // round greentime
        if (Traffic_Light_In_Intersection[c]->getstate() !=
            "OFF") { // if the traffic light is OFF skip it
          // set traffic light to green
          Traffic_Light_In_Intersection[c]->setstate(3);
          printTrafficState(Traffic_Light_In_Intersection);
          cout << endl;
          Traffic_Light_In_Intersection[c]->wait(
              Traffic_Light_In_Intersection[c]->getgreenTimer());
          // set traffic light to yellow
          Traffic_Light_In_Intersection[c]->setstate(2);
          printTrafficState(Traffic_Light_In_Intersection);
          cout << endl;
          Traffic_Light_In_Intersection[c]->wait(DurationForYellowLight);
          // set traffic light to red
          Traffic_Light_In_Intersection[c]->setstate(1);
          printTrafficState(Traffic_Light_In_Intersection);
          cout << endl;
        }
        // drop as cars as per greentime, if there are less cars than magnitude
        // of greentime, drop all the cars in lane then set number of cars to 0,
        // otherwise, drop cars as per magnitude of greentime. Assuming 1 car
        // passes per sec of greentime
        int counterOfCars = 0;
        if (Traffic_Light_In_Intersection[c]->getNumOfCars() <=
            NumberofcarsTopassGreen[c]) {
          Traffic_Light_In_Intersection[c]->NumberOfCarstodrop(
              Traffic_Light_In_Intersection[c]->getNumOfCars());
          Traffic_Light_In_Intersection[c]->setNumOfCars(0);
        } else
          while (counterOfCars < NumberofcarsTopassGreen[c]) {
            Traffic_Light_In_Intersection[c]->dropcar();
            counterOfCars++;
          }
      }
    }
  }
}
