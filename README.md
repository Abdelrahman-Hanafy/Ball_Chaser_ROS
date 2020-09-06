
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
 
``` 
first download the project
    $ git clone https://github.com/Abdelrahman-Hanafy/Ball_Chaser_ROS.git 

then **DELETE** the following dirs and rebuils them : _build and devel_ 

    $ cd [path where you cloned]/Ball_Chaser_ROS
    $ rm -rf /build /devel 
    $ catkin_make 

TO launch using roslaunch

    $roslaunch my_robot world.launch 
```

# Project description 

Directory Structure
```
.Ball_Chaser                                    # Ball Chaser Porject
├── catkin_ws                                   # catkin workspace
    ├──src                                      
        ├── ball_chaser                         # ball cahser package
        │   ├── CMakeLists.txt                  # compiler instructions
        │   ├── launch                          # launch folder for launch files
        │   │   └── ball_chaser.launch
        │   ├── model                           # Model folder for gazebo models 
        │   │   └── ball                        # Model files for the ball
        │   │       ├── model.config
        │   │       └── model.sdf
        │   ├── package.xml                     # package info
        │   ├── src                             # source folder for C++ scripts
        │   │   ├── drive_bot.cpp
        │   │   └── process_image.cpp
        │   └── srv                             # service folder for ROS services
        │       └── DriveToTarget.srv
        └── my_robot                            # my_robot package 
            ├── CMakeLists.txt                  # compiler instructions
            ├── launch                          # launch folder for launch files
            │   ├── robot_description.launch
            │   └── world.launch
            ├── meshes                          # meshes folder for sensors
            │   └── hokuyo.dae
            ├── package.xml                     # package info
            ├── rviz                            # rviz folder for rviz configration
            │   └── world.rviz
            ├── urdf                            # urdf folder for xarco files
            │   ├── my_robot.gazebo
            │   └── my_robot.xacro
            └── worlds                          # world folder for world files
                ├── empty.world
                ├── myworld.world
                └── world.world

```



