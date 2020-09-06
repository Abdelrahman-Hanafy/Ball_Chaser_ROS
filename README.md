
# Ball Chaser Project
this is a  robot that can chase a white ball in side gazebo world using data from rgb camera 

# Prerequisites
you should have the following list installed

* ROS melodic 
* GAZEBO 
* RViz
* GCC to build C++
* catkin pakage

# Install and Launch

first download the project 
``` $ git clone https://github.com/Abdelrahman-Hanafy/Ball_Chaser_ROS.git 

then **DELETE** the following dirs and rebuils them : _build and devel_ 
    $ cd [path where you cloned]/Ball_Chaser_ROS
    $ rm -rf /build /devel 
    $ catkin_make 

TO launch using roslaunch
    $roslaunch my_robot world.launch ```


