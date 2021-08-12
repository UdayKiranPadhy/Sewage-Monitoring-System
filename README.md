# Sewage-Monitoring-System
This repository contains the files of Sewage Monitoring System Which was done during CRUX.

### Abstract
Over flow of sewage on roads is been a major problem in many developed and under developed cities as well. Sewage is generally considered as waste water. The response to the complaints is not properly answered or taken into account. A precautionary system is developed where this issue of sewage overflow can be reduced by early sensing of increase in its level. The system design comprises of a sensor to sense the level, a controller to command, a communication network to register the complaints on blockage and continues increase in the level of sewage. A data base is to be maintained to record the data. The system rather simply monitoring the level, it generates alarm signals via complaints to the required departments through mail and SMS regarding prior to overflow.

### Components Required:
1.	Arduino Board Uno (2no.)
2.	NodeMCU Wifi Module (1no.)
3.	NRF24 Transceiver Module (2no.)
4.	Ultra-Sonic Sensor
5.	Servo Motor
6.	Solar Panels
7.	Rechargeable Batteries

### Working Mechanism:
In the method proposed, development of IoT based sewage level maintenance is designed, where the sewage level is monitored using an Ultra Sonic Sensor. The Ultra Sonic Sensor keeps on monitoring the level of the sewage. As the level changes, the Ultra Sonic sensor detects and send the signal to the Respective associated Node where the controller commands the IoT network to generate alert complaints to the municipal and corporation departments in prior to overflow. The complaints will be repeatedly registered until the level reaches the minimum set. The communication is done based on IoT where the complaints are auto registered and the entire system is controlled using an ARDUINO microcontroller.


![Communication Topology](https://raw.githubusercontent.com/UdayKiranPadhy/Sewage-Monitoring-System/master/CommunicationTopology.jpg)

### Communication Topology
The types of network topology that can be used are port to port topology, star, tree, mesh, ring bus and fully connected topology. The design caries port to port topology, where Switched point-to-point topologies are the basic model of conventional telephony.

### Circuit Diagram

#### Transmitor Sensor Node

![Transmitor Sensor Node](https://raw.githubusercontent.com/UdayKiranPadhy/Sewage-Monitoring-System/master/ModelOutline.png)

#### Gateway Node

![Transmitor Sensor Node](https://raw.githubusercontent.com/UdayKiranPadhy/Sewage-Monitoring-System/master/ModelOutline2.png)


### Advantages:
1.	Reduces Human Intervention
2.	Real Time Analysis Of sewage level
3.	Making Possible to check the present Condition Of the sewage in any remote Location with access.
4.	Due to the use of Solar Strips, it doesn’t require any other external power source as far as possible.
5.	The Surveillance of Sewage and Drainage Levels has become a lot easier, with of the use of Radio Communication. 
6.	Because of the robotic arm the clearing of sewage is ensured at minimum level.

### Disadvantages:
1.	The System is still depended on internet connections.
2.	It doesn’t locate the point where the blockade has occurred.
3.	Due to the use of ultra-sonic sensor the reading might get changed because of Any large waste material.


### Conclusion:
A precautionary system avoids or eliminates the issue of sewage overflow on roads which is being a major problem in many cities. The level sensors are efficiently used and system is designed in a social relevant idea thus to create an impact on hygiene and cleanliness by simply avoiding the problem of overflow on streets and also to ensure compulsory cleaning of blockage which causes the increase the sewage level by registering repeated complaints to random departments unless action is taken.
