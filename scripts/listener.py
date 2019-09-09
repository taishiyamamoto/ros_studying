#!/usr/bin/env python

import rospy
from std_msgs.msg import Float32

class Subscriber():
    def __init__(self):
        self.sub=rospy.Subscriber("talk_number",Float32,self.callback)

        self.msg=Float32()

    def callback(self,msg):
        rospy.loginfo(msg)

if __name__ == '__main__':
    rospy.init_node('listener')
    sub=Subscriber()

    try:
        rospy.spin()
    except rospy.ROSInterruptException: pass
        
