#include <Arduino.h>
#include <M5Stack.h>
#include <MyCobotBasic.h>
#include <ParameterList.h>
#include <uTimerLib.h>

/*
実装案

  1.実装案；ボタンで切り替え
    btnA: サーボを配列にまとめた角度で動かしていく、ディスプレイに手先位置座標を表示
    btnB: パワーをオフにして、自由にサーボの手先を動かせるようにする、ディスプレイに手先座標を表示
    btnC: 未定
*/

MyCobotBasic myCobot;   //インスタンス変数

Angles initial =  { -0.0, -0.0, -0.0, -0.0, -0.0, -0.0 };

Angles animation[5] ={
  {-90,90,-90,90,0,0},
  { -0.0, -0.0, -0.0, -0.0, -0.0, -0.0 },
  {-90,90,-90,90,0,0},
  { -0.0, -0.0, -0.0, -0.0, -0.0, -0.0 },
  {90.0, -0.0, -0.0, -0.0, -0.0, -0.0}
};

float link_lengths[4]={131.56, 110.4, 96.0, 73.18};

int t = 0;

// タイマー関数
void timing(){
  t++;
  if(t>sizeof(animation)/sizeof(Angles)){
    t = 0;
  }
}

// 座標を配列で返せるような関数を作成、mallocなどを用いて実装する
// float[3] ForwardKinematics();

void setup() {
  // put your setup code here, to run once:

  M5.begin();
  M5.Power.begin();

  myCobot.setup();
  myCobot.powerOn();

  for(auto &val: initial)
    val=0.0;

  myCobot.writeAngles(initial, 50);

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(10);
  M5.Lcd.println("MyCobot");



}


void loop() {
  // put your main code here, to run repeatedly:
  M5.Lcd.setCursor(0,70);

  M5.update();
  M5.Lcd.setTextSize(3);
  

  if(M5.BtnA.isPressed()){
    // myCobot.powerOff();
    myCobot.setFreeMove();
    M5.Lcd.printf("Power Off Mode\n");
    M5.Lcd.print("X: ");
    // M5.Lcd.print(x_cordinate)
    TimerLib.clearTimer();
  }
  if(M5.BtnB.isPressed()){
    myCobot.powerOn();
     myCobot.writeAngles(initial, 50);
     M5.Lcd.printf("Power On Mode\n");
     M5.Lcd.printf("");
     TimerLib.setInterval_s(timing, 5);
    while (true)
    {
      M5.update();
      myCobot.writeAngles(animation[t],50);
      if(M5.BtnA.isPressed()){
        break;
      }

    }
    
  }

  M5.Lcd.setCursor(0,100);
  for(auto &e: myCobot.getAngles())
      M5.Lcd.println(e);
}