/*******************************************************************************
 * Copyright (C) 2020 Prof. Dr. Christian Pfitzner - All Rights Reserved       
 * You may use, distribute and modify this code under the
 * terms of the BSD license. 
 *******************************************************************************/


// ros includes
#include <ros/ros.h>
#include <std_srvs/SetBool.h>



int main(int argc, char **argv)
{
  // initialisierung des ros Knotens
   ros::init(argc, argv, "service_client");

   // Initialisierung des node handles zur Kommunikation mit dem ROSCORE
   ros::NodeHandle n;

  // Initialisierung für den ROS-ServiceClient zum Versenden von Service-Nachrichten
   ros::ServiceClient client = n.serviceClient<std_srvs::SetBool>("hello_ros/set_bool_srv");
   std_srvs::SetBool srv;

   // Loop-Rate mit 
   ros::Rate loop_rate(0.2);


   unsigned int i=0; 
   while(ros::ok())
   {
      if(      i == 0) srv.request.data = true;
      else if (i == 1) srv.request.data = false; 
      else if (i == 2) srv.request.data = false;  
      
      if (client.call(srv))
      {
         ROS_INFO_STREAM("Variable changed to "          << static_cast<int>(srv.response.success));
         ROS_INFO_STREAM("Message from service server: " << srv.response.message); 
      }
      else
      {
         ROS_ERROR("Failed to call service hello_ros/set_bool_srv");
      }

      loop_rate.sleep();


      i++;              // Iterator um eins hochzählen 
      i = i%3;          // Iterator mit dem Modulo 3 verrechnen. Daher ergibt sich die Reihenfolge 0, 1, 2, 0, 1, ...
   }

   return 0;
}