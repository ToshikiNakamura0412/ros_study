#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "set_vel_node");
    ros::NodeHandle nh;

    ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/target_velocity", 1);
    geometry_msgs::Twist target_velocity;
    target_velocity.linear.x = 0.5;
    cmd_vel_pub.publish(target_velocity);
    return 0;
}
