#include<ros/ros.h>
#include<std_msgs/Float32.h>

class Talker{
    public:
        Talker(){
            pub_=nh_.advertise<std_msgs::Float32>("talk_number",1000);
        }
    
        void send_msgs(float number);

    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        
        std_msgs::Float32 message_;
};

void
Talker::send_msgs(float number){

    message_.data=number;

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