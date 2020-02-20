#ifndef KRILL_1_PCB_H
#define KRILL_1_PCB_H

#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_INA219.h>
#include <Wire.h>


#define US_NW_TRIGGER 19
#define US_NW_ECHO 18

#define US_N_TRIGGER 5
#define US_N_ECHO 17

#define US_NE_TRIGGER 16
#define US_NE_ECHO 4

#define US_W_TRIGGER 32
#define US_W_ECHO 33

#define US_E_TRIGGER 25
#define US_E_ECHO 26

#define US_S_TRIGGER 12
#define US_S_ECHO 14

#define MOTOR_1 27
#define MOTOR_2 13
#define SERVO_1 13

#define LED_GREEN 0
#define LED_RED 2

extern Servo Motor_1;
extern Servo Motor_2;
extern Servo Servo_1;

extern Adafruit_BNO055 bno;
extern Adafruit_INA219 ina;

void Krill_1_setup(bool usesServo);
float get_distance(int trigger, int echo);

#endif