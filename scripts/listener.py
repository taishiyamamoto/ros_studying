#!/usr/bin/env python

import rospy
from geometry_msgs.msg import PointStamped 

class Subscriber():
    def __init__(self):
        self.sub=rospy.Subscriber('talk_number',PointStamped,self.callback)

        self.message=PointStamped()

    def callback(self,message):
        rospy.loginfo(message)

if __name__ == '__main__':
    rospy.init_node('listener')
    sub=Subscriber()

    try:
        rospy.spin()
    except rospy.ROSInterruptException: pass
        
