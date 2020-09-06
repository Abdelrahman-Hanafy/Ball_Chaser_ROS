#include "ros/ros.h"
//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"
#include "geometry_msgs/Twist.h"

// ROS::Publisher motor commands;
ros::Publisher vels_pub;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities
bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res){
    
    ROS_INFO("DriveToTargetRequest received - lx:%1.2f, az:%1.2f", (float)req.linear_x, (float)req.angular_z);

    std::vector<float> vls = {req.linear_x, req.angular_z};

    geometry_msgs::Twist motor_command;
    motor_command.linear.x = vls[0];
    motor_command.angular.z = vls[1];

    vels_pub.publish(motor_command);

    // Wait 3 seconds for arm to settle
    ros::Duration(3).sleep();

    // Return a response message
    res.msg_feedback = "velocties set - lx: " + std::to_string(req.linear_x) + " , az: " + std::to_string(req.angular_z);
    ROS_INFO_STREAM(res.msg_feedback);

    return true;

}


int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    vels_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    
    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    ros::ServiceServer drive = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);
    ROS_INFO("Ready to send Velocties commands");
    
    // TODO: Handle ROS communication events
    ros::spin();

    return 0;
}