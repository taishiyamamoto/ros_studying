#!/usr/bin/env python

import rospy
from std_msgs.msg import Float32

class Subscriber():
    def __init__(self):
        self.sub=rospy.Subscriber('talk_number',Float32,self.callback)

        self.message=Float32()

    def callback(self,message):
        rospy.loginfo(message)

if __name__ == '__main__':
    rospy.init_node('listener')
    sub=Subscriber()

    try:
        rospy.spin()
    except rospy.ROSInterruptException: pass
        
