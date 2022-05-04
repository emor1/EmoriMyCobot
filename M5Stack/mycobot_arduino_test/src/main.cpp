#include <Arduino.h>
#include<MyCobotBasic.h>
#include<ParameterList.h>
#include<M5Stack.h>

MyCobotBasic myCobot;

Angles angles = { -0.0, -0.0, -0.0, -0.0, -0.0, -0.0 };


void setup() {
  // put your setup code here, to run once:
  myCobot.setup();
  myCobot.powerOn();

  for(auto &val: angles)
    val=0.0;

  myCobot.writeAngles(angles,50);
}

void loop() {
  // put your main code here, to run repeatedly:
    myCobot.setLEDRGB(0XFF, 0, 0);       // set RGB show red
    delay(2000);
    myCobot.setLEDRGB(0, 0XFF, 0);       // set RGB show blue
    delay(2000);
    myCobot.setLEDRGB(0, 0, 0XFF);       // set RGB show green
    delay(2000);

    for(int i=1;i<7;i++){
      myCobot.writeAngle(i,-90,100);
      delay(1000);
      myCobot.writeAngle(i, 90,100);
      delay(1000);
      myCobot.writeAngle(i, 0,100);
      delay(500);
    }
  myCobot.writeAngles(angles,50);
  delay(500);

}
