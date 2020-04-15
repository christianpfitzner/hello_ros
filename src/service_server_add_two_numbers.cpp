/* Copyright (C) 2020 Prof. Dr. Christian Pfitzner - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license, which unfortunately won't be
 * written for another century.
 */


// ros includes
 #include <ros/ros.h>
 #include "hello_ros/SumTwoNumbers.h"
 

bool add(hello_ros::SumTwoNumbers::Request  &req,
         hello_ros::SumTwoNumbers::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}



 
 int main(int argc, char **argv)
 {
  // initialisierung des ros Knotens
  ros::init(argc, argv, "add_two_ints_server");

  // Initialisierung des node handles zur Kommunikation mit dem ROSCORE
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);


  ROS_INFO("Ready to add two ints.");

  // das Programm wird ausgeführt und lauscht dabei auf eingehende Service Nachrichten. 
  ros::spin();

  return 0;
 }