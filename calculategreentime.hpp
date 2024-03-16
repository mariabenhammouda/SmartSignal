double Calculategreentime(TrafficLight *(Traffic_Light_In_Intersection)[4],
                          int &x) {
  //calculate green time and return its value in double form
  return (((double)Traffic_Light_In_Intersection[x]->getNumOfCars() /
           Traffic_Light_In_Intersection[x]->getTotalTrafficFlow()) *
          Traffic_Light_In_Intersection[x]->getcycletime());
}