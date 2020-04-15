/*******************************************************************************
 * Copyright (C) 2020 Prof. Dr. Christian Pfitzner - All Rights Reserved       
 * You may use, distribute and modify this code under the
 * terms of the BSD license. 
 *******************************************************************************/


// ros includes
#include <ros/ros.h>
#include <std_srvs/SetBool.h>


/* wir verwenden hier eine globale Variable 
   das ist sicherlich kein schöner Programmierstill, erfüllt aber den Zweck
   dieses einfachen Beispiels */
bool g_variable = false; 


bool setBoolCallback(std_srvs::SetBool::Request  &req, std_srvs::SetBool::Response &res)
{
  /* hier wird abgefragt, ob die Variable bereits den neuen Wert besitzt
     Falls das der Fall ist, so gibt der Service einen Fehler zurück */
  if(g_variable == req.data)
  {
    res.success = false; 
    res.message = std::string("Variable already has the requested value"); 
    ROS_INFO_STREAM("[Server] Variable already has the requested value"); 

    return true; 
  }

  g_variable = req.data; 

  // Ausgabe im Terminal
  ROS_INFO_STREAM("[Server] New value of variable is: " << g_variable); 

  // Füllen der Response Nachricht
  res.success = req.data; 
  res.message = std::string("Variable was successfully set to " + static_cast<int>(g_variable)); 

  return true;
}



int main(int argc, char **argv)
{
  // initialisierung des ros Knotens
  ros::init(argc, argv, "service_server");
  
  // Initialisierung des node handles zur Kommunikation mit dem ROSCORE
  ros::NodeHandle n;

  // Initialisierung für den ROS-ServiceServers zum Behandeln von eingehenden Service-Anfragen
  ros::ServiceServer service = n.advertiseService("hello_ros/set_bool_srv", setBoolCallback);

  // Ausgabe im Terminal, dass der Knoten läuft. 
  ROS_INFO_STREAM("Service server is ready.");
  
  // das Programm wird ausgeführt und lauscht dabei auf eingehende Service Nachrichten. 
  ros::spin();

  return 0;
}