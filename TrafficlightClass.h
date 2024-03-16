#ifndef TrafficlightClass_h
#define TrafficlightClass_h
#define MaxNumOfCars 100
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <time.h>
using namespace std;
class car {
private:
  int platenumber = 0;
  double speed = 0.0;

public:
//default constructor
  car() {
    int platenumber = 0;
    double speed = 0.0;
  }
//non default constructor
  car(int platenumber, double speed) {
    this->platenumber = platenumber;
    this->speed = speed;
  }
//destructor
  ~car(){};
//getters and setters
  int getplatenum() { return platenumber; }
  double getspeed() { return speed; }
  void setplatenum(int platenumber) { this->platenumber = platenumber; }
  void setspeed(double speed) { this->speed = speed; }
};

class TrafficLight {
private:
  static const int cycletime = 24;
  static int numoftrafficlights;
  int TrafficLightID;
  int state;
  double greenTimer;
  car cars[MaxNumOfCars];
  int numofcars = 0;
  static int TotalTrafficFlow;
  queue<car> car_queue;

public:
  double speedlimit = 0.0;
//default constructor
  TrafficLight() {
    numoftrafficlights++;
    TrafficLightID = numoftrafficlights;
  }
//destructor
  ~TrafficLight(){};
  // getters
  double getcycletime() const { return cycletime; }
  int getNumOfCars() { return numofcars; }
  int getTotalTrafficFlow() { return TotalTrafficFlow; }
  int getTrafficLightID() { return TrafficLightID; }
  string getstate() {
    string colour;
    if (state == 1) {
      colour = "RED";
    }
    if (state == 2) {
      colour = "YELLOW";
    }
    if (state == 3) {
      colour = "GREEN";
    }
    if (state == 0) {
      colour = "OFF";
    }
    return colour;
  }
  double getgreenTimer() { return greenTimer; }
  double getSpeedLimit() { return speedlimit; }

  void addcar(car newcar) {
    // checks if the traffic light can accomodate one more car
    if (numofcars < MaxNumOfCars) {
      //set number of cars in traffic light as the number of cars objects in queue
      setNumOfCars(car_queue.size());
      car_queue.push(newcar); // add car to queue
      TotalTrafficFlow++; //increment number of cars in intersection
      numofcars++; //increment number of cars in individual traffic light
      car elem = move(car_queue.front());
      car_queue.pop();
      car_queue.push(move(elem));
    } else {
      cout
          << "Can't add more cars to to road with traffic light , full capacity"
          << endl;
    }
  }
//setters
  void setstate(int newstate) { state = newstate; }
  void setTotalTrafficFlow(int TotalTrafficFlow) {
    this->TotalTrafficFlow = TotalTrafficFlow;
  }
  void setspeedlimit(double speedlimit) { this->speedlimit = speedlimit; }
  void setgreenTimer(double newgreentimer) { greenTimer = newgreentimer; }
  void setNumOfCars(int numofcars) { this->numofcars = numofcars; }

  // drop individual car
  void dropcar() {
    car_queue.front();
    car_queue.pop();//remove car objects from the front of queue
    numofcars--;
    TotalTrafficFlow--;
    setNumOfCars(numofcars); //update number of cars in traffic
  }
  // drop a defined number of cars >1
  void NumberOfCarstodrop(int dropcars) {
    for (int c = 0; c < dropcars; c++) {
      car_queue.front();
      car_queue.pop(); //remove car objects from the front of queue
      numofcars--;
      TotalTrafficFlow--;
    }
    setNumOfCars(numofcars);//update number of cars in traffic
  }

  void wait(double numseconds) {
    long now;
    now = time(NULL);
    time_t start;
    time(&start);
    do {
      time(&now);
    } while ((now - start) < numseconds);
    // loops while the number of seconds is less than that given by the user
  }
  // prints the traffic light information
  void printLightInfo() {
    cout << getTrafficLightID() << setw(30) << setprecision(2)
         << getgreenTimer() << setw(25) << getNumOfCars() << endl;
  }
};
// initialize static variable
int TrafficLight::numoftrafficlights = 0;
int TrafficLight::TotalTrafficFlow = 0;

#endif /* TrafficlightClass_h */
