#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String

def talker():
    # initialisierung des ros knotens
    rospy.init_node('my_string_publisher_python', anonymous=True)
    # Initialisierung des Publishers
    pub = rospy.Publisher('hello_world_topic', String, queue_size=10)
    # Dauer einer Schleife festlegen
    rate = rospy.Rate(10) # 10hz
    # Schleife mit Abbruchkriterium
    while not rospy.is_shutdown():
        # Vorbereiten der Nachricht
        hello_str = "hello world"
        pub.publish(hello_str)
        # Warten bis Schleifenzeit erreicht ist
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass