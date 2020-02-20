#include <Krill_1_PCB.h>

Servo Motor_1;
Servo Motor_2;
Servo Servo_1;
Adafruit_BNO055 bno = Adafruit_BNO055(55);
Adafruit_INA219 ina;

void Krill_1_setup(bool usesServo) {

    //Set pin modes
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    pinMode(US_N_TRIGGER, OUTPUT);
    pinMode(US_N_ECHO, INPUT);

    pinMode(US_NE_TRIGGER, OUTPUT);
    pinMode(US_NE_ECHO, INPUT);

    pinMode(US_NW_TRIGGER, OUTPUT);
    pinMode(US_NW_ECHO, INPUT);

    pinMode(US_W_TRIGGER, OUTPUT);
    pinMode(US_W_ECHO, INPUT);

    pinMode(US_E_TRIGGER, OUTPUT);
    pinMode(US_E_ECHO, INPUT);

    pinMode(US_S_TRIGGER, OUTPUT);
    pinMode(US_S_ECHO, INPUT);

    // 0x28
    // 0x40
    Wire.begin();

    //Starts IMU
    ina.begin();

    if(!bno.begin()) {
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
       // while(1);
    }
    else {
        delay(1000);
        bno.setExtCrystalUse(true);
    } 

    //Starts motors
    Motor_1.attach(MOTOR_1);
    Motor_1.write(0);

    if (usesServo) {
        Servo_1.attach(SERVO_1);
        Servo_1.write(90);
    }
    else {
        Motor_2.attach(MOTOR_2);
        Motor_2.write(0);
    }
}

float get_distance(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  float duration = pulseIn(echo, HIGH);
  float distance = (duration / 2) / 29.1;

  return distance;
}