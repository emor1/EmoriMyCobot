#include <Arduino.h>
#include <M5Stack.h>
#include <MyCobotBasic.h>
#include <ParameterList.h>

/*
実装案

  1.実装案；ボタンで切り替え
    btnA: サーボを配列にまとめた角度で動かしていく、ディスプレイに手先位置座標を表示
    btnB: パワーをオフにして、自由にサーボの手先を動かせるようにする、ディスプレイに手先座標を表示
    btnC: 未定

*/

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