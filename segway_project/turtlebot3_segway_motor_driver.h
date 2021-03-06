#ifndef TURTLEBOT3_SEGWAY_MOTOR_DRIVER_H_
#define TURTLEBOT3_SEGWAY_MOTOR_DRIVER_H_

#include <DynamixelSDK.h>

// Control table address (Dynamixel X-series)
#define ADDR_X_TORQUE_ENABLE            64
#define ADDR_X_GOAL_PWM                 100
#define ADDR_X_GOAL_VELOCITY            104
#define ADDR_X_PROFILE_ACCELERATION     108
#define ADDR_X_PROFILE_VELOCITY         112
#define ADDR_X_GOAL_POSITION            116
#define ADDR_X_REALTIME_TICK            120
#define ADDR_X_PRESENT_VELOCITY         128
#define ADDR_X_PRESENT_POSITION         132
#define ADDR_X_PWM                      11

// Limit values (XM430-W210-T)
#define LIMIT_X_MAX_VELOCITY            240

// Data Byte Length
#define LEN_X_TORQUE_ENABLE             1
#define LEN_X_GOAL_PWM                  2
#define LEN_X_GOAL_VELOCITY             4
#define LEN_X_GOAL_POSITION             4
#define LEN_X_REALTIME_TICK             2
#define LEN_X_PRESENT_VELOCITY          4
#define LEN_X_PRESENT_POSITION          4
#define LEN_X_PWM                       16

#define PROTOCOL_VERSION                2.0     // Dynamixel protocol version 2.0

#define DXL_LEFT_ID                     1       // ID of left rear motor
#define DXL_RIGHT_ID                    2       // ID of right rear motor
#define BAUDRATE                        1000000 // baud rate of Dynamixel
#define DEVICENAME                      ""      // no need setting on OpenCR

#define TORQUE_ENABLE                   1       // Value for enabling the torque
#define TORQUE_DISABLE                  0       // Value for disabling the torque

class Turtlebot3MotorDriver
{
 public:
  Turtlebot3MotorDriver();
  ~Turtlebot3MotorDriver();
  bool init(void);
  void closeDynamixel(void);
  bool setTorque(uint8_t id, bool onoff);
  bool controlMotor(int64_t left_wheel_value, int64_t right_wheel_value);

 private:
  uint32_t baudrate_;
  float  protocol_version_;
  uint8_t left_wheel_id_, right_wheel_id_;

  dynamixel::PortHandler *portHandler_;
  dynamixel::PacketHandler *packetHandler_;

  dynamixel::GroupSyncWrite *groupSyncWritePWM_;
};

#endif // TURTLEBOT3_SEGWAY_MOTOR_DRIVER_H_
