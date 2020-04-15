#!/usr/bin/env python



from std_srvs.srv import *
import rospy

def setBoolCallback(req):
    # print "Returning [%s + %s = %s]"%(req.a, req.b, (req.a + req.b))


    return SetBoolResponse(True, "hello")


def service_server():
    
    rospy.init_node('service_server_python')


    s = rospy.Service('hello_ros/set_bool_srv_py', SetBool, setBoolCallback)


    print "Python service server is ready."

    rospy.spin()



if __name__ == "__main__":
    service_server()