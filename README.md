# Challenge Custom Message ROS2

1. Clone repository ini

```
git clone https://github.com/Hallherout/DaffaDaniswara_ChallengeROS2.git
```

2. Build

```
cd DaffaDaniswara_ChallengeROS2/
colcon build
```

3. Pada terminal pertama

```
source install/setup.bash
ros2 run controller_package controller_publisher
```

4. Pada terminal kedua

```
source install/setup.bash
ros2 run controller_package controller_subscriber
```