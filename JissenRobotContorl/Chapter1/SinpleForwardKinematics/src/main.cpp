#include <Arduino.h>
#include <M5Stack.h>
#include <MyCobotBasic.h>
#include <ParameterList.h>


MyCobotBasic myCobot;   //インスタンス変数

Angles initial =  { -0.0, -0.0, -0.0, -0.0, -0.0, -0.0 };


void setup() {
  // put your setup code here, to run once:
  myCobot.setup();
  myCobot.powerOn();

  for(auto &val: angles)
    val=0.0;

  myCobot.writeAngles(initial, 50);

}

void loop() {
  // put your main code here, to run repeatedly:
}