#include <Arduino.h>
#include <Krill_1_PCB.h>
#include <Krill_1_Server.h>
//#include <Stepper.h>
// #include <WiFiUdp.h>
// #include <SPIFFS.h>

// Number of steps per output rotation
#define stepsPerRevolution 200

// initialize the stepper library on pins 15,2,0,4
// Stepper myStepper(stepsPerRevolution, 15,2,0,4);

bool state_red = false;
bool state_green = false;
bool state_13 = false;

// void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255) {
//   // calculate duty, 8191 from 2 ^ 13 - 1
//   uint32_t duty = (8191 / valueMax) * min(value, valueMax);

//   // write duty to LEDC
//   ledcWrite(channel, duty);
// }
//WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // ledcSetup(2, 5000, 8);
  // ledcAttachPin(LED_RED, 2);
  // ledcSetup(0, 5000, 8);
  // ledcAttachPin(LED_GREEN, 0);

  // // set the speed at 20 rpm:
  // myStepper.setSpeed(20);
  // // initialize the serial port:
  // pinMode(19, OUTPUT);
  digitalWrite(19, HIGH);

  Krill_1_setup(true);
  startWiFi();
  
  udp.onPacket([](AsyncUDPPacket packet) {
      // Serial.print("UDP Packet Type: ");
      // Serial.print(packet.isBroadcast()?"Broadcast":packet.isMulticast()?"Multicast":"Unicast");
      // Serial.print(", From: ");
      // Serial.print(packet.remoteIP());
      // Serial.print(":");
      // Serial.print(packet.remotePort());
      // Serial.print(", To: ");
      // Serial.print(packet.localIP());
      // Serial.print(":");
      // Serial.print(packet.localPort());
      // Serial.print(", Length: ");
      // Serial.print(packet.length());
      // Serial.print(", Data: ");
      //Serial.println(packet.data());
      String word = (char*)packet.data();
      char command = word.charAt(0);
      word.remove(0, 1);
      int value = word.toInt();
      //Serial.println(word);
      switch (command) {
        case 't':
          value = constrain(value, 0, 170);
          // Serial.print("Thruster: ");
          // Serial.println(value);
          Motor_1.write(constrain(value, 0, 170));
          break;
        case 's':
          //Serial.print("Servo: ");
          //Serial.println(value);
          Servo_1.write(constrain(value, 10, 170));
          break;
        case 'g':
          //Serial.print("Green Led: ");
          //Serial.println(value);
          digitalWrite(LED_GREEN, value);
          break;
        case 'r':
          //Serial.print("Red Led: ");
          //Serial.println(value);
          digitalWrite(LED_RED, value);
          break;
        default:
          //Serial.print("Unknown: ");
          //Serial.println(value);
          break;
      }
      //ledcWrite(LED_RED, word.toInt());
      //Serial.write(packet.data(), packet.length());
      //Serial.println();
      //reply to the client
      // Serial.printf("Got %u bytes of data", packet.length());
  });
  

  // Serial.println("On");
  // digitalWrite(LED_GREEN, HIGH);
  // delay(1000);
  // Serial.println("Off");
  // digitalWrite(LED_GREEN, LOW);
}

void loop() {
  // if (Serial.available()) {
  //   int value = Serial.parseInt();

  //   switch (value) {
  //   case 1:
  //     state_green = !state_green;
  //     digitalWrite(LED_GREEN, state_green);
  //     break;
  //   case 2:
  //     state_red = !state_red;
  //     digitalWrite(LED_RED, state_red);
  //     break;
  //   }
  // }

  // Serial.print("Distance: ");
  // Serial.println(get_distance(trigger, echo));
  // delay(200);

  // if (Serial.available()) {
  //   int toWrite = Serial.parseInt();
  //   Motor_1.write(toWrite);
  //   Serial.print("Sending: ");
  //   Serial.println(toWrite);
  //   delay(200);
  //   Serial.parseInt();
  // }

  // state_13 = !state_13;
  // digitalWrite(13, state_13);
  // Serial.print("The State 13: ");
  // Serial.println(state_13);
  // delay(500);

  /* Get a new sensor event */ 
  // sensors_event_t event; 
  // bno.getEvent(&event);
  
  // /* Display the floating point data */
  // Serial.print("X: ");
  // Serial.print(event.orientation.x, 4);
  // Serial.print("\tY: ");
  // Serial.print(event.orientation.y, 4);
  // Serial.print("\tZ: ");
  // Serial.print(event.orientation.z, 4);
  // Serial.println("");
  


  // delay(1000);
  //   //Send broadcast on port 1234
  //   udp.broadcastTo("Anyone here?", 1234);

  // float shuntvoltage = 0;
  // float busvoltage = 0;
  // float current_mA = 0;
  // float loadvoltage = 0;
  // float power_mW = 0;

  // shuntvoltage = ina.getShuntVoltage_mV();
  // busvoltage = ina.getBusVoltage_V();
  // current_mA = ina.getCurrent_mA();
  // power_mW = ina.getPower_mW();
  // loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  // Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  // Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  // Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  // Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  // Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  //Serial.println("");

  //delay(2000);

  // step one revolution in one direction:
  // Serial.println("clockwise");
  // myStepper.step(stepsPerRevolution);
  // delay(500);

  // // step one revolution in the other direction:
  // Serial.println("counterclockwise");
  // myStepper.step(-stepsPerRevolution);
  // delay(500);

}



