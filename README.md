# SmartSignal
Real-time Traffic Control with object tracking 

A Traffic management system is a system that will calculate the average movement of vehicles to provide proactive route guidance and traffic control support by making data-driven adjustments to the road/intersection properties such as road speed limit, traffic light, and pedestrian signal sequencing.

Approach:
This system’s goal involves designing software to simulate a system of traffic lights at an intersection and make data-driven adjustments to reduce traffic congestion.

The objective of the project “Traffic management system” could have been implemented via a simpler code to simulate an individual traffic light status and speed limit adjustments. The program would read information from a file that contains the green time, the number of cars in the intersection, the speed limit, and traffic congestion separated by lines, this information would then be translated as a traffic light object. However, this simple simulation would not encompass the characteristics of a traffic light management system like the competitive systems out in the market, and neither would this program be useful for a real-life problem as it solves a very specific problem by relying heavily on data preorganized by the user into a file. To generalize the solution, the code has a structured logic that can operate independently to any additional monitoring devices aside from the traffic light sensor. The code receives the car information from the sensor file, then internally calculates the time for the traffic semaphores, adjusts the speed limit, evaluates the traffic congestion level then prints this information to the user.

The simulation is that of an intersection consisting of two streets that cross at right angles. For simplicity, the intersection has a one-way road with controllable
traffic lights on each corner. The software controls the 4 traffic lights
as shown in the figure:
The system is comprised of the following components:
1. Traffic semaphores (signal lights): these are standard semaphores
with three lights: red, yellow, and green.
2. Traffic sensors embedded in each lane near the intersection record the car information (4 sensors generating 4 traffic rate values when four traffic lights are used).

![Screen Shot 2024-03-13 at 12 50 55 PM](https://github.com/mariabenhammouda/SmartSignal/assets/102983688/170cac37-cca9-4d40-af6e-e78e8a985ef2)

Traffic light (L1) is green for a duration calculated based on the traffic flow rate on road R1, the other traffic lights (L2, L3, and L4) are red. L1 becomes yellow for 4 seconds (4 being a constant value). Other traffic lights (L2, L3, and L4) remain red. The Department of Transportation's traffic manual recommends that yellow lights are between 3 and 6 seconds long therefore this simulation uses a yellow light duration of 4 seconds. Then, traffic light L2 becomes green for a duration calculated based on the traffic flow rate on road R2. Meanwhile, L1, L3, and L4 are red. This cycle alternates between the traffic lights until the cycle time has passed. The next cycle starts with traffic light L1 becoming green again, and so on.

The green timings for the traffic lights are updated regularly based on a constant cycle time as per researched factors optimizing traffic light system performance.

𝑔𝑟𝑒𝑒𝑛𝑡𝑖𝑚𝑒 = 𝑐𝑦𝑐𝑙𝑒𝑡𝑖𝑚𝑒 × 𝑁𝑢𝑚𝑏𝑒𝑟 𝑜𝑓 𝑐𝑎𝑟𝑠 𝑖𝑛 𝑇𝑟𝑎𝑓𝑓𝑖𝑐 𝐿𝑖𝑔h𝑡/𝑇𝑜𝑡𝑎𝑙 𝑁𝑢𝑚𝑏𝑒𝑟 𝑜𝑓 𝑐𝑎𝑟𝑠 𝑖𝑛 𝐼𝑛𝑡𝑒𝑟𝑠𝑒𝑐𝑡𝑖𝑜𝑛


Input format:
A successful input

![Screen Shot 2024-03-13 at 12 54 28 PM](https://github.com/mariabenhammouda/SmartSignal/assets/102983688/df4c2f33-bf42-455c-9ee5-9bef2d219e28)

A failed input 

![Screen Shot 2024-03-13 at 12 56 02 PM](https://github.com/mariabenhammouda/SmartSignal/assets/102983688/3ae06bf0-f22e-4619-869c-598093451ae0)

