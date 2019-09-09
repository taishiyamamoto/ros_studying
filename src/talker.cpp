#include<ros/ros.h>
#include<geometry_msgs/PointStamped.h>

class Talker{
    public:
        Talker(){
            pub_=nh_.advertise<geometry_msgs::PointStamped>("talk_number",1000);
        }
    
        void send_msgs(float number);

    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        
        geometry_msgs::PointStamped message_;
};

void
Talker::send_msgs(float number){

    message_.point.x=number;

    pub_.publish(message_);

}

int main(int argc,char **argv){
    ros::init(argc,argv,"talker");

    Talker tk;

    ros::Rate loop_rate(10);

    float count=0;
    
    while(ros::ok()){
        tk.send_msgs(count);

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}